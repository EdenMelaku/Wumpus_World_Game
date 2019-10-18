#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "../../utilities/DataStructures.h"


namespace components{

class Actuator
{
    public:
        Actuator();
        void actuate(DataStructures::Decision decision); //change return type to action
};

}
#endif
