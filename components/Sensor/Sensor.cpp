#include "Sensor.h"

namespace components{

using namespace DataStructures;

    DataStructures::Knowledge Sensor::percept_to_knowledge(DataStructures::Percepts perceptions)
    {
        DataStructures::Knowledge kb;
        kb.stench = perceptions.stench;
        kb.breeze = perceptions.breeze;
        kb.glitter = perceptions.glitter;
        kb.bump = perceptions.bump;
        kb.scream = perceptions.scream;
        kb.wumpus = perceptions.wumpus;

        return kb;
    }

    void Sensor::add_percept(std::pair<int, int> room, DataStructures::Percepts perceptions)
    {
        DataStructures::Knowledge information = Sensor::percept_to_knowledge(perceptions);
        current_kb.add_into_knowledgebase(room, information);
    }
}
