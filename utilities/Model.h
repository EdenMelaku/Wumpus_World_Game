#ifndef MODEL_H
#define MODEL_H

#include <tuple>
#include <map>
#include "DataStructures.h"


namespace DataStructures{

    typedef std::pair<int, int> Room;
    typedef std::map<Room, DataStructures::Percepts> model;
    enum class Rule{
        Wumpus,
        Pit
    };
    
    class Model{

    public:
        static bool get_specific_percept_info(std::pair<int, int> room, DataStructures::constraint, model);
        static model generate_model(Room room, Rule rule);
    
    };
}

#endif
