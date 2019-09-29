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
actions::actions(bool turnleftt, bool turnrightt,bool shoott,bool movee, vector<int> turnss){
     turnleft =turnleftt;
     turnright=turnrightt;
     shoot=shoott;
     move=movee;
     turns=turnss;
    
    }
