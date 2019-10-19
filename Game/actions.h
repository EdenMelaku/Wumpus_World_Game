//
// Created by eden on 25/09/2019.
//

#ifndef WUMPUS_WORLD_GAME_ACTIONS_H
#define WUMPUS_WORLD_GAME_ACTIONS_H
#include "sensor.h"
#include <vector>

class actions
{

public:
    bool turnleft;
    bool turnright;
    bool shoot;
    bool move;
 
    actions();
    actions(bool turnleft, bool turnright, bool shoot, bool move);
};

#endif //WUMPUS_WORLD_GAME_ACTIONS_H
