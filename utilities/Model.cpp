#include "Model.h"


namespace DataStructures{

/**
 * Validates whether a given position is valid or not.
 * @param  i row of a given position
 * @param  j column of a given position
 * @return   bool
 */
bool is_valid_position(int i, int j)
{
  // this function is not generic enough to handle a grid that's not 4X4, needs improvement
  if((i >= 0 && i <= 3) && (j >= 0 && j <= 3)) return true;
  else return false;
}

model Model::generate_model(Room room, Rule rule){
    model required_model;
    Room left = std::make_pair(room.first-1, room.second);
    Room right = std::make_pair(room.first+1, room.second);
    Room top = std::make_pair(room.first, room.second+1);
    Room bottom = std::make_pair(room.first, room.second-1);

    if(rule == Rule::Wumpus){
        if (is_valid_position(left.first, left.second)) required_model[left].stench = true;
        if (is_valid_position(right.first, right.second))  required_model[right].stench = true;
        if (is_valid_position(top.first, top.second)) required_model[top].stench = true;
        if (is_valid_position(bottom.first, bottom.second)) required_model[bottom].stench = true;
    }
    else if(rule == Rule::Pit){
        if (is_valid_position(left.first, left.second)) required_model[left].breeze = true;
        if (is_valid_position(right.first, right.second))  required_model[right].breeze = true;
        if (is_valid_position(top.first, top.second)) required_model[top].breeze = true;
        if (is_valid_position(bottom.first, bottom.second)) required_model[bottom].breeze = true;
    }
    return required_model;   
}

bool Model::get_specific_constraint_info(std::pair<int, int> room, DataStructures::constraint specified_constraint, DataStructures::model specified_model){

    if(specified_constraint == DataStructures::constraint::breeze) return specified_model[room].breeze;
    else if(specified_constraint == DataStructures::constraint::bump) return specified_model[room].bump;
    else if(specified_constraint == DataStructures::constraint::glitter) return specified_model[room].glitter;
    // else if(specified_constraint == DataStructures::constraint::pit) return specified_model[room].scream;
    else if(specified_constraint == DataStructures::constraint::scream) return specified_model[room].scream;
    else if(specified_constraint == DataStructures::constraint::stench) return specified_model[room].stench;
    else if(specified_constraint == DataStructures::constraint::wumpus) return specified_model[room].wumpus;
    else return false;  

}

}
