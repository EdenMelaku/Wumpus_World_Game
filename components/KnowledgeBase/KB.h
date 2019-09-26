#ifndef KNOWLEDGEBASE_H
#define KNOWLEDGEBASE_H

#include <map>
#include <set>
#include "../../utilities/DataStructures.h"


namespace components{

class KnowledgeBase
{
    /*
    *
    * This class holds the data structure of the agent's knowledgebase and methods for manipulating it.
    * The data structure is held in the data member data.
    * Data is a mapping from rooms to the information gathered about that room. 
    * A room is represented by a pair<int, int> as row, col representation.
    * The information collected about each room is held in the value of the map using the Knowledge struct.
    * The knowledge struct (written above) contains all the possible perceptions that can be attributed to a room by the agent after perceptions within the wumpus world.
    * 
    */
    private:
        std::map<std::pair<int, int>, DataStructures::Knowledge> data; 
    public:
        KnowledgeBase();
        ~KnowledgeBase();
        std::map<std::pair<int, int>, DataStructures::Knowledge> get_data();
        void add_into_knowledgebase(std::pair<int, int> room, DataStructures::Knowledge knowledge);
        void change_room_information(std::pair<int, int> room, DataStructures::Knowledge knowledge);
        DataStructures::Knowledge get_room_information(std::pair<int, int> room);
};  

}
#endif;
