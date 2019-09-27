#include "IA.h"
#include "../../utilities/DataStructures.h"


namespace agent{

using namespace DataStructures;

Action IntelligentAgent::go(Information information)
{
    ia_sensor.sense(information);
    Decision decision;
    decision = ia_inferer.infer();
    ia_actuator.actuate(decision);
}

}
