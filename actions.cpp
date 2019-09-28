//
// Created by eden on 25/09/2019.
//
#include <vector>
#include "actions.h"
#include "sensor.h"




/*
 *
 */
actions::actions() {;}
actions::actions(bool turnleft, bool turnright,bool shoot,bool move, vector<int> turns){
     turnleft =turnleft;
     turnright=turnright;
     shoot=shoot;
     move=move;
     turns=turns;
    
    }
