
namespace components{

#include "Inference.h"

using namespace components;
using namespace DataStructures;
using namespace std;

Inference::Inference(components::KnowledgeBase current_kb)
{
  Inference::current_kb = current_kb;
}

/**
 * [Inference::is_valid_position validates if a given position is valid or not]
 * @param  i [row of a given position]
 * @param  j [column of a given position]
 * @return   [bool]
 */
bool Inference::is_valid_position(int i, int j)
{
  if((i >= 1 && i <= 4) && (j >= 1 && j <= 4)) {
    return true;
  }
  return false;
}

/**
 * [Inference::get_adjacent_rooms find valid adjacent rooms of the current room]
 * @param current_room [piar<int, int> current room position in tumple format]
 * @return [vector<pair<int, int>> valid adjacent rooms]
 */
vector<pair<int, int>> Inference::get_adjacent_rooms(pair<int, int> current_room)
{
  vector<pair<int, int>> adjacent_rooms;
  vector<pair<int, int>> adjacent_rooms_candidates;
  adjacent_rooms_candidates.push_back(make_pair(current_room.first + 1, current_room.second));
  adjacent_rooms_candidates.push_back(make_pair(current_room.first - 1, current_room.second));
  adjacent_rooms_candidates.push_back(make_pair(current_room.first, current_room.second + 1));
  adjacent_rooms_candidates.push_back(make_pair(current_room.first, current_room.second - 1));

  for(auto itr = adjacent_rooms_candidates.begin(); itr < adjacent_rooms_candidates.end(); itr++) {
    if(is_valid_position(itr->first, itr->second)) {
      adjacent_rooms.push_back(*itr);
    }
  }

  return adjacent_rooms;
}

/**
 * [Inference::find_possible_move find the possible move base on the knowledgebase of the rooms.]
 * @param current_room [current room position in pair<int, int> format]
 * @return [selected room in pair<int, int> format]
 */
pair<int, int> Inference::find_possible_move(pair<int, int> current_room)
{
  // todo - calculate_possible_move
  vector<pair<int, int>> adjacent_rooms = get_adjacent_rooms(current_room);
  map<pair<int, int>, Knowledge> data = current_kb.get_data();

  // possible move candidate base on their priorities
  vector<pair<int, int>> possible_move_candidates1;
  vector<pair<int, int>> possible_move_candidates2;
  vector<pair<int, int>> possible_move_candidates3;

  // possible move which hold on of the prior possible moves
  vector<pair<int, int>> possible_move_candidates;

  for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++) {
    // if the adjacent room is ok and unvisited.
    if(data[*itr].ok && !data[*itr].visited) {
      possible_move_candidates1.push_back(*itr);
    // if the adjacent room is ok and visited.
    }else if(data[*itr].ok && data[*itr].visited) {
      possible_move_candidates2.push_back(*itr);
    }else {
      possible_move_candidates3.push_back(*itr);
    }
  }

  // assign possible_moves
  if(possible_move_candidates1.size() > 0){
    possible_move_candidates = possible_move_candidates1;
  }else if(possible_move_candidates2.size() > 0){
    possible_move_candidates = possible_move_candidates2;
  }else{
    possible_move_candidates = possible_move_candidates3;
  }

  // fix the random number generator.
  srand((int)time(0));
  int random_number = rand()%possible_move_candidates.size();
  pair<int, int> selected_room = possible_move_candidates[random_number];

  return selected_room;
}

/**
 * [Inference::infer infer response from the given knowledgebase]
 * @param  current_room [current room position in pair<int, int> format]
 * @return              [response which contain the infered action and an updated knowledgebase]
 */
Response Inference::infer(pair<int, int> current_room)
{
  std::map<std::pair<int, int>, DataStructures::Knowledge> data = current_kb.get_data();
  Knowledge room_data = current_kb.get_room_information(current_room);
  vector<pair<int, int>> adjacent_rooms = get_adjacent_rooms(current_room);

  Response response;

  // if there is no stench and no breeze
  if(!room_data.stench && !room_data.breeze) {
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
      // Knowledge k = current_kb.get_room_information(*itr);
      // k.ok = true;
      // current_kb.change_room_information(*itr, k);
        data[*itr].ok = true;
      // change_ok_information(*itr, true);
    }
  // if there is stench
  }else if(room_data.stench) {
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
      Knowledge adjacent_room_data = current_kb.get_room_information(*itr);
      bool room_is_ok = adjacent_room_data.ok;
      bool room_has_possible_wumpes = adjacent_room_data.possible_wumpus;
      bool room_has_wumpes = adjacent_room_data.wumpus;
      if(!room_is_ok && !room_has_possible_wumpes && !room_has_wumpes) {
        data[*itr].possible_wumpus = true;
        // change_possible_wumpus_information(*itr, true);
      }else if(room_has_possible_wumpes) {
        data[*itr].wumpus = true;
        pair<int, int> wumpus_room = *itr;
        response.shoot_at = wumpus_room;
      }else {
        continue;
      }
    }
  // if there is breeze
  }else if(room_data.breeze) {
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
      bool room_is_ok = current_kb.get_room_information(*itr).ok;
      bool room_has_possible_pit = current_kb.get_room_information(*itr).possible_pit;
      bool room_has_pit = current_kb.get_room_information(*itr).pit;
      if(!room_is_ok && !room_has_possible_pit && !room_has_pit) {
          data[*itr].possible_pit = true;
      }else if(room_has_possible_pit) {
          data[*itr].pit = true;
          data[*itr].possible_pit = false;
      }else{
        continue;
      }
    }
  // if there is stench and breeze
  }else {
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++) {
      bool room_is_ok = current_kb.get_room_information(*itr).ok;
      bool room_has_possible_wumpes = current_kb.get_room_information(*itr).possible_wumpus;
      bool room_has_possible_pit = current_kb.get_room_information(*itr).possible_pit;
      if(!room_is_ok && !room_has_possible_wumpes && !room_has_possible_pit) {
          data[*itr].possible_wumpus = true;
          data[*itr].possible_pit = true;
      }else if(room_has_possible_wumpes) {
          data[*itr].wumpus = true;
      }else if(room_has_possible_pit) {
          data[*itr].pit = true;
      }else {
        continue;
      }
    }
  }

  pair<int, int> selected_room = find_possible_move(current_room);

  data[current_room].visited = true;

  response.move_to = selected_room;

  return response;
}
}
