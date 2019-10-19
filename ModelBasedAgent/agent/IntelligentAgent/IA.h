#ifndef IA_H
#define IA_H

#include "../../components/KnowledgeBase/KB.h"
#include "../../components/Sensor/Sensor.h"
#include "../../components/Inference/Inference.h"
#include "../../components/Actuator/Actuator.h"


namespace agent{

using namespace DataStructures;

class IntelligentAgent
{
    
    private:
        
        // playground ia_playground;
        components::KnowledgeBase ia_kb;
        components::Sensor ia_sensor = components::Sensor(ia_kb);
        components::Inference ia_inferer = components::Inference(ia_kb);
        components::Actuator ia_actuator;
    public:
        IntelligentAgent();
        Decision decision;
        Decision go(std::pair<int,int> agent_location, Percepts room_perceptions);
};

}

#endif
