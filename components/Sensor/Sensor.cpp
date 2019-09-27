#include "Sensor.h"

namespace components{

using namespace DataStructures;

    /**
     * @brief Construct a new Sensor:: Sensor object
     * 
     * @param kb  KnowledgeBase that sensor will write to
     */
    Sensor::Sensor(KnowledgeBase kb)
    {
        current_kb = kb;
    }
    /**
     * @brief Converts obtained percepts to Knowledge
     * 
     * @param perceptions 
     * @return Knowledge 
     */
    Knowledge Sensor::percept_to_knowledge(Percepts perceptions)
    {
        Knowledge kb;
        kb.stench = perceptions.stench;
        kb.breeze = perceptions.breeze;
        kb.glitter = perceptions.glitter;
        kb.bump = perceptions.bump;
        kb.scream = perceptions.scream;
        kb.wumpus = perceptions.wumpus;
        return kb;
    }
    /**
     * @brief Adds the percepts obtained into the knowledge base
     * 
     * @param room 
     * @param perceptions 
     */
    void Sensor::add_percept(std::pair<int, int> room, Percepts perceptions)
    {
        Knowledge information = Sensor::percept_to_knowledge(perceptions);
        current_kb.add_into_knowledgebase(room, information);
    }
}
