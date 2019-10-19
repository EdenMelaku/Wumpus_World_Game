#include "Inference.h"
#include <iostream>


namespace components{

// using namespace DataStructures;

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
DataStructures::Decision Inference::infer(std::pair<int, int> current_room)
{
  DataStructures::Decision d;

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

/**
 * @brief rule matching function that will incorporate infered conclusions into knowledgebase as well as pass on conclusion for next action
 * 
 * @param room 
 */
void Inference::rule_matching(std::pair<int, int> room){

  std::set<std::pair<int, int>> adjacentRooms = get_adjacent_rooms(room);
  std::cout << "Agent in: " << room.first << "," << room.second << std::endl;
  
  for (auto adj : adjacentRooms){
    
    // check adjacent rooms for existence of wumpus or pit to figure out an ok room to move to
    std::cout << "checking room: " << adj.first << "," << adj.second << std::endl;
    bool wumpus = current_kb.get_information_wumpus(room);
    bool pit = current_kb.get_information_pit(room);

    // if the presence of wumpus is not recorded in the adjacent room, perform model based inference to test for presence of wumpus
    if (!wumpus) wumpus = infer_presence(adj, DataStructures::Rule::Wumpus);
    if (!pit) pit = infer_presence(adj, DataStructures::Rule::Pit);

    if(wumpus){
        std::cout << "wumpus detected" << std::endl;
        current_kb.change_information_wumpus(adj, true); // update knowledgebase
//       Decision d;
//       d.shoot_at = adj;
//       // return d;
    }

    if(pit){
        std::cout << "pit detected" << std::endl;
        current_kb.change_information_pit(adj, true); // update knowledgebase
        pit_rooms.insert(adj);
    }

    if(!wumpus && !pit){
        std::cout << "room is ok" << std::endl;
        current_kb.change_information_ok(adj, true); // update knowledgebase
        ok_rooms.insert(adj);
    }
  }

}

/**
 * @brief Infers the presence of a character such as a wumpus or pit in a room
 * 
 * @param room The room from which will be inferred character exists in it or not.
 * @param character The game character which will be checked for existence.
 * @return true The character exists in the room.
 * @return false The character does not exist in the room.
 */
bool Inference::infer_presence(std::pair<int, int> room, DataStructures::Rule character){

    // PH(position, value) == Rule(position, value)

    DataStructures::model inference_model;
    DataStructures::constraint constraint;
    bool conclusion = false;
    int counter;

    if (character == DataStructures::Rule::Wumpus){
      inference_model = DataStructures::Model::generate_model(room, DataStructures::Rule::Wumpus);
      counter = inference_model.size();
      constraint = DataStructures::constraint::stench;
    }
    else if (character == DataStructures::Rule::Pit){
      inference_model = DataStructures::Model::generate_model(room, DataStructures::Rule::Pit);
      counter = inference_model.size();
      constraint = DataStructures::constraint::breeze;
    }
    
    for (auto rule : inference_model){
      std::cout << rule.first.first << "," << rule.first.second << ": " << "breeze: " << rule.second.breeze << " stench: " <<  rule.second.stench << std::endl;
      std::pair<int, int> model_room = std::make_pair(rule.first.first,rule.first.second);
      // cross-check equivalence in rooms
      conclusion = check_equivalence(model_room, constraint, inference_model);
      if (conclusion) --counter;
    }

    if (counter == 0) conclusion = true;

    return conclusion;
}

/**
 * @brief Checks the equivalence of contraints of the model with the data stored in the knowledgebase
 * 
 * @param room Room that the constraint will be checked against
 * @param constraint Constraint that will be checked for validity in the knowlegebase
 * @return true Specified constraint is in congruity with data stored in the knowledgebase
 * @return false Specified constraint is not in conngruity with data stored in the knowledgebase
 */
bool Inference::check_equivalence(std::pair<int, int> room, DataStructures::constraint specific_constraint, DataStructures::model specified_model){

    bool is_equivalent = current_kb.get_specific_percept_info(room, specific_constraint) == DataStructures::Model::get_specific_constraint_info(room, specific_constraint, specified_model);
    std::cout << "check equiv: " << is_equivalent << std::endl;
    return is_equivalent;

}

}
