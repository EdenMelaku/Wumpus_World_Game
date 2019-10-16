#ifndef MODEL_H
#define MODEL_H

#include <tuple>
#include <map>
#include "DataStructures.h"



namespace DataStructures{

    enum class Rule{
        Wumpus,
        Pit
    };
    typedef std::pair<int, int> Room;
    typedef std::map<Room, DataStructures::Percepts> model;

    class Model{

    // std::set<std::pair<int, int>, bool> conclusion;

    // Wumpus:
    public:
        bool get_specific_percept_info(std::pair<int, int> room, DataStructures::constraint);
        model generate_model(Room room, Rule rule);
    };
}
#endif
