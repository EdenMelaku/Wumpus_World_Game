#include "Inference.h"
#include <iostream>


namespace components{

using namespace DataStructures;

/**
 * @brief Construct a new Inference:: Inference object
 * 
 * @param kb Knowledgebase object
 */
Inference::Inference(KnowledgeBase& kb) :current_kb(kb)
{
  
}

/**
 * [Inference::is_valid_position validates if a given position is valid or not]
 * @param  i [row of a given position]
 * @param  j [column of a given position]
 * @return   [bool]
 */
bool is_valid_position(int i, int j)
{
  // this function is not generic enough to handle a grid that's not 4X4, needs improvement
  if((i >= 0 && i <= 3) && (j >= 0 && j <= 3)) return true;
  else return false;
}

/**
 * [Inference::get_adjacent_rooms find valid adjacent rooms of the current room]
 * @param current_room [piar<int, int> current room position in tumple format]
 * @return [vector<pair<int, int>> valid adjacent rooms]
 */
std::set<std::pair<int, int>> get_adjacent_rooms(std::pair<int, int> room)
{
    std::set<std::pair<int, int>> adjacent_rooms;
    std::vector<std::pair<int, int>> adjacent_rooms_candidates;
    adjacent_rooms_candidates.push_back(std::make_pair(room.first + 1, room.second));
    adjacent_rooms_candidates.push_back(std::make_pair(room.first - 1, room.second));
    adjacent_rooms_candidates.push_back(std::make_pair(room.first, room.second + 1));
    adjacent_rooms_candidates.push_back(std::make_pair(room.first, room.second - 1));

    // cout << room.first << "," << room.second << ": " << endl;
    for(auto itr : adjacent_rooms_candidates) {
        if(is_valid_position(itr.first, itr.second)) {
          adjacent_rooms.insert(itr);
          // cout << itr.first << "," << itr.second << endl;
        }
    }
    return adjacent_rooms;
}
/**
 * [Inference::infer infer response from the given knowledgebase]
 * @param  current_room [current room position in pair<int, int> format]
 * @return              [response which contain the infered action and an updated knowledgebase]
 */
Decision Inference::infer(std::pair<int, int> current_room)
{
  Decision d;

  // model: <room> bool value, <room> bool value, <room> bool value
  // model: wumpus: <room> boolvalue stench
  //        pit <room> boolvalue breeze
  // the inference will take current_room and infer wumpus, infer pit, infer okay. All three will have different models
  // then return detections to Actuator, which will possibly give suggestions on next step to take, i.e Decision
  // std::vector<deduction, std::set<std::pair<int, int>, bool>> model;

  // ----------------- RULE MATCHING -------------
  // for each adj in adjacentrooms:
  //      bool w = inferwumpus(adj)
  //      bool p = inferwumpus(adj)
  //      if (w) shoot(direction)
  //      if (p) pitrooms.add(adj)
  //      if (!w && !p) okrooms.add(adj)

  // inferwumpus(room):
  //    PH(get_info_sth) |= room.left.sth
  //    PH(get_info_sth) |= room.right.sth
  //    PH(get_info_sth) |= room.top.sth
  //    PH(get_info_sth) |= room.bottom.sth

  // infer(room, sthBoss):
  //    sth = getModel(sthBoss) //this is where it's at
  //    PH(get_info_sth) |= room.left.sth
  //    PH(get_info_sth) |= room.right.sth
  //    PH(get_info_sth) |= room.top.sth
  //    PH(get_info_sth) |= room.bottom.sth

  // test
  // get_adjacent_rooms(make_pair(0,0));
  // get_adjacent_rooms(make_pair(0,2));
  // get_adjacent_rooms(make_pair(3,1));
  // get_adjacent_rooms(make_pair(3,3));
  // get_adjacent_rooms(make_pair(-1,-1));
  // get_adjacent_rooms(make_pair(4,4));
  rule_matching(current_room);
  return d;
}

bool infer_wumpus(std::pair<int, int> room){
    
    return true;
}

bool infer_pit(std::pair<int, int> room){

    return true;
}

void Inference::rule_matching(std::pair<int, int> room){
  std::set<std::pair<int, int>> adjacentRooms = get_adjacent_rooms(room);
  for (auto adj : adjacentRooms){

    bool wumpus = infer_wumpus(adj);
    bool pit = infer_pit(adj);

    if(wumpus){
        current_kb.change_information_wumpus(adj, true); // update knowledgebase
//       Decision d;
//       d.shoot_at = adj;
//       // return d;
    }

    if(pit){
        current_kb.change_information_pit(adj, true); // update knowledgebase
        pit_rooms.insert(adj);
    }

    if(!wumpus && !pit) ok_rooms.insert(adj);
  
  }
}






// Decision Inference::infer(pair<int, int> current_room)
// {
//   std::map<std::pair<int, int>, DataStructures::Knowledge> data = current_kb.get_data();
//   Knowledge room_data = current_kb.get_room_information(current_room);
//   vector<pair<int, int>> adjacent_rooms = get_adjacent_rooms(current_room);

//   Decision decision;

//   // if there is no stench and no breeze
//   if(!room_data.stench && !room_data.breeze) {
//     for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
//         current_kb.change_information_ok(*itr, true);
//     }
//   // if there is stench
//   }else if(room_data.stench) {
//     for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
//       Knowledge adjacent_room_data = current_kb.get_room_information(*itr);
//       bool room_is_ok = adjacent_room_data.ok;
//       bool room_has_possible_wumpes = adjacent_room_data.possible_wumpus;
//       bool room_has_wumpes = adjacent_room_data.wumpus;
//       if(!room_is_ok && !room_has_possible_wumpes && !room_has_wumpes) {
//         current_kb.change_information_possible_wumpus(*itr, true);
//       }else if(room_has_possible_wumpes) {
//         current_kb.change_information_wumpus(*itr, true);
//         current_kb.change_information_possible_wumpus(*itr, false);
//         pair<int, int> wumpus_room = *itr;
//         decision.shoot_at = wumpus_room;
//       }else {
//         continue;
//       }
//     }
//   // if there is breeze
//   }else if(room_data.breeze) {
//     for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
//       bool room_is_ok = current_kb.get_room_information(*itr).ok;
//       bool room_has_possible_pit = current_kb.get_room_information(*itr).possible_pit;
//       bool room_has_pit = current_kb.get_room_information(*itr).pit;
//       if(!room_is_ok && !room_has_possible_pit && !room_has_pit) {
//           current_kb.change_information_possible_pit(*itr, true);
//       }else if(room_has_possible_pit) {
//           current_kb.change_information_pit(*itr, true);
//           current_kb.change_information_possible_pit(*itr, false);
//       }else{
//         continue;
//       }
//     }
//   // if there is stench and breeze
//   }else {
//     for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++) {
//       bool room_is_ok = current_kb.get_information_ok(*itr);
//       bool room_has_possible_wumpes = current_kb.get_information_possible_wumpus(*itr);
//       bool room_has_possible_pit = current_kb.get_information_possible_pit(*itr);
//       if(!room_is_ok && !room_has_possible_wumpes && !room_has_possible_pit) {
//           current_kb.change_information_possible_wumpus(*itr, true);
//           current_kb.change_information_possible_pit(*itr, true);
//       }else if(room_has_possible_wumpes) {
//           current_kb.change_information_wumpus(*itr, true);
//       }else if(room_has_possible_pit) {
//           current_kb.change_information_pit(*itr, true);
//       }else {
//         continue;
//       }
//     }
//   }

//   pair<int, int> selected_room = find_possible_move(current_room);

//   current_kb.change_information_visited(current_room, true);

//   decision.move_to = selected_room;

//   return decision;
// }
}
