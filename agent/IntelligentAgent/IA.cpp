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
    Percepts p;
    p.breeze = true;
    p.bump = true;
    p.stench = true;

    std::pair<int, int> r = std::make_pair(1, 1);
    ia_kb = ia_sensor.add_percept(std::make_pair(1, 1), p);
    Decision decision;
    // decision = ia_inferer.infer();
    std::cout << ia_kb.get_information_breeze(std::make_pair(1,1)) << std::endl;
    std::cout << ia_kb.get_information_bump(std::make_pair(1,1)) << std::endl;
    std::cout << ia_kb.get_information_stench(std::make_pair(1,1)) << std::endl;
}

}
