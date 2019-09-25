#ifndef SENSOR_H
#define SENSOR_H

#include "KB.h"
#include "../../Utilities/DataStructures.h"


namespace components{

using namespace DataStructures;

class Sensor
{
    private:
        KnowledgeBase current_kb;
        DataStructures::Knowledge percept_to_knowledge(DataStructures::Percepts perceptions);
    public:
        void add_percept(std::pair<int, int> room, DataStructures::Percepts perceptions);
};
     
} 
#endif;
