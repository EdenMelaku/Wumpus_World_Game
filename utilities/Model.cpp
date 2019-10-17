#include "Model.h"


namespace DataStructures{

model generate_model(Room room, Rule rule){
    model required_model;
    Room left = std::make_pair(room.first-1, room.second);
    Room right = std::make_pair(room.first+1, room.second);
    Room top = std::make_pair(room.first, room.second+1);
    Room bottom = std::make_pair(room.first, room.second-1);

    if(rule == Rule::Wumpus){
        required_model[left].stench = true;
        required_model[right].stench = true;
        required_model[top].stench = true;
        required_model[bottom].stench = true;
    }
    else if(rule == Rule::Pit){
        required_model[left].breeze = true;
        required_model[right].breeze = true;
        required_model[top].breeze = true;
        required_model[bottom].breeze = true;
    }
    return required_model;
    
}

bool get_specific_constraint_info(std::pair<int, int> room, DataStructures::constraint specified_constraint, DataStructures::model specified_model){

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
