#ifndef SENSOR_H
#define SENSOR_H

#include "../KnowledgeBase/KB.h"
#include "../../utilities/DataStructures.h"


namespace components{

class Sensor
{
    private:
        KnowledgeBase& current_kb;
        DataStructures::Knowledge percept_to_knowledge(DataStructures::Percepts perceptions);
    public:
        Sensor(KnowledgeBase& kb);
        KnowledgeBase add_percept(std::pair<int, int> room, DataStructures::Percepts perceptions);
};
     
} 
#endif
