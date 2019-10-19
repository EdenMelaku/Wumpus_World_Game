#include "IA.h"
#include "../../utilities/DataStructures.h"
#include <iostream>


namespace agent{

IntelligentAgent::IntelligentAgent(){
    ;
}

Decision IntelligentAgent::go(std::pair<int,int> agent_location, Percepts room_perceptions){
    
    ia_sensor.add_percept(agent_location, room_perceptions);
    
    decision = ia_inferer.infer(agent_location);
    
    return decision;
    }

}
