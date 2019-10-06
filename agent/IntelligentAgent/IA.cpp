#include "IA.h"
#include "../../utilities/DataStructures.h"
#include <iostream>


namespace agent{

using namespace DataStructures;

IntelligentAgent::IntelligentAgent(){
    ;
}
// Action IntelligentAgent::go(Information information)
// {
//     ia_sensor.sense(information);
//     Decision decision;
//     decision = ia_inferer.infer();
//     ia_actuator.actuate(decision);
// }

void IntelligentAgent::go(){
    std::cout << "going";
}

}
