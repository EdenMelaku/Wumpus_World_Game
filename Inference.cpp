#include "Inference.h"

Inference::Inference(KnowledgeBase Knowledge_base)
{
  Inference::knowledge_base = knowledge_base;
}

vector<pair<int, int>> Inference::get_adjacent_rooms(pair<int, int> current_room)
{
  vector<pair<int, int>> adjacent_rooms;
  return adjacent_rooms;
}

vector<pair<int, int>> Inference::get_adjacent_ok_rooms(pair<int, int> current_room)
{
  vector<pair<int, int>> adjacent_rooms = get_adjacent_rooms(current_room);
  vector<pair<int, int>> adjacent_ok_rooms;
  for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
    if(knowledge_base.find(*itr).ok){
      adjacent_ok_rooms.push_back(*itr);
    }
  }
  return adjacent_ok_rooms;
}

vector<pair<int, int>> Inference::get_adjacent_visited_rooms(pair<int, int> current_room)
{
  vector<pair<int, int>> adjacent_rooms = get_adjacent_rooms(current_room);
  vector<pair<int, int>> adjacent_visited_rooms;
  for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
    if(knowledgebase.find(*itr).visited){
      adjacent_visited_rooms.push_back(*itr);
    }
  }
  return adjacent_visited_rooms;
}

void Inference::inference(pair<int, int> current_room)
{
  Knowledge room_knowledge = Inference::knowledge_base.find(current_room);
  vector<pair<int, int>> adjacent_rooms = get_adjacent_rooms(current_room);

  // if there is no stench and no breeze
  if(!room_knowledge.stench && !room_knowledge.breeze) {
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
      Inference::knowledge_base.find(*itr).ok = true;
    }
  // if there is stench
  }else if(room_knowledge.stench) {
    // vector<pair<int, int>>::iterator itr = adjacent_rooms.begin();
    // iterator throught all the adjacent rooms
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
      Knowledge adjacent_room_knowledge = KnowledgeBase::get_percepts(*itr)
      bool room_is_ok = adjacent_room_knowledge.ok;
      bool room_has_possible_wumpes = adjacent_room_knowledgepossible_wumpes;
      bool room_has_wumpes = adjacent_room_knowledge.wumpes;
      if(!room_is_ok && !room_has_possible_wumpes && !room_has_wumpes) {
        Inference::knowledge_base.find(*itr).possible_wumpes = true;
      }else if(room_has_possible_wumpes) {
        Inference::knowledge_base.find(*itr).wumpus = true;
        pair<int, int> wumpus_room = *itr;
      }else{
        continue;
      }
    }
  // if there is breeze
  }else if(room_knowledge.breeze){
    // vector<pair<int, int>>::iterator itr = adjacent_rooms.begin();
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
      bool room_is_ok = KnowledgeBase::get_percepts(*itr).ok;
      bool room_has_possible_pit = KnowledgeBase::get_percepts(*itr).possible_pit;
      bool room_has_pit = KnowledgeBase::get_percepts(*itr).pit;
      if(!room_is_ok && !room_has_possible_pit && !room_has_pit) {
        Inference::knowledge_base.find(*itr).possible_pit = true;
      // }else if(room_possible_count >= 3) {
      }else if(room_has_possible_pit) {
        Inference::knowledge_base.find(*itr).pit = true;
        Inference::knowledge_base.find(*itr).possible_pit = false;
      }else{
        continue;
      }
    }
  // if there is stench and breeze
  }else{
    for(auto itr = adjacent_rooms.begin(); itr < adjacent_rooms.end(); itr++){
      bool room_is_ok = knowledge_base.get_percepts(*itr).ok;
      bool room_has_possible_wumpes = knowledge_base::get_percepts(*itr).possible_wumpes;
      bool room_has_possible_pit = knowledge_base::get_percepts(*itr).possible_pit;
      if(!room_is_ok && !room_has_possible_wumpes && !room_has_possible_pit) {
        Inference::knowledge_base.find(*itr).possible_wumpes = true;
        Inference::knowledge_base.find(*itr).possible_pit = true;
      }else if(room_has_possible_wumpes) {
        Inference::knowledge_base.find(*itr).wumpus = true;
      }else if(room_has_possible_pit) {
        Inference::knowledge_base.find(*itr).pit = true;
      }else{
        continue;
      }
    }
}

// if wumpus room has been founded
if(wumpus_room != null){
  shoot_wumpus(wumpus_room);
  remove_wumpus(wumpus_room);
  remove_all_possible_wumpse_rooms(); // if wumpus is set all the possible wumpus room must be false
}
if (possible_moves.size() > 1){
  possible_moves.remove(adjacent_visited_rooms); // remove the visted rooms
}
pair<int, int> selected_room = rand(possible_moves);
move_to(selected_room);
set_room_visted(current_room);

}
