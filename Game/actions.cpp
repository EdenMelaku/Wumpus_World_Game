//
// Created by eden on 25/09/2019.
//
#include <vector>
#include "actions.h"
#include "sensor.h"




/*
 *
 */
actions::actions() {
     turnleft =false;
     turnright=false;
     shoot=false;
     move=false;
     
}
actions::actions(bool turnleftt, bool turnrightt,bool shoott,bool movee){
     turnleft =turnleftt;
     turnright=turnrightt;
     shoot=shoott;
     move=movee;
    
    }
