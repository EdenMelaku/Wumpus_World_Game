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

}