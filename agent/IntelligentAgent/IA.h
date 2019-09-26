#ifndef IA.h
#define IA.h

#include  "Sensor.h"
#include "KB.h"
#include "Inference.h"
#include "Actuator.h"

namespace agent{

using namespace components;

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

#endif;
