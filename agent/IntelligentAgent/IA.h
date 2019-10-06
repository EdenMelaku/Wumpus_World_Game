#ifndef IA_H
#define IA_H

#include "../../components/Sensor/Sensor.h"
#include "../../components/KnowledgeBase/KB.h"
#include "../../components/Inference/Inference.h"
#include "../../components/Actuator/Actuator.h"

namespace agent{

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
        void go();
};

}

#endif
