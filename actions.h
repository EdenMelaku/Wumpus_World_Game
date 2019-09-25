//
// Created by eden on 25/09/2019.
//

#ifndef WUMPUS_WORLD_GAME_ACTIONS_H
#define WUMPUS_WORLD_GAME_ACTIONS_H
#include "sensor.h"

class actions {
private:
    bool turnleft ;
    bool turnright;
    bool turnup;
    bool turndown;
    bool shoot;
    bool move;
public:
     vector<Sensor> run();

};


#endif //WUMPUS_WORLD_GAME_ACTIONS_H
