//
// Created by eden on 25/09/2019.
//
#include <vector>
#include "actions.h"
#include "sensor.h"


/**
 * @brief Construct a new actions::actions object
 * 
 */
actions::actions()
{;}
/**
 * @brief Construct a new actions::actions object
 * 
 * @param turnleftt      Boolean value for turning left
 * @param turnrightt     Boolean value for turning left
 * @param shoott         Boolean value for turning left
 * @param movee          Boolean value for turning left
 * @param turnss         Boolean value for turning left
 */
actions::actions(bool turnleftt, bool turnrightt,bool shoott,bool movee, vector<int> turnss)
{
     turnleft =turnleftt;
     turnright=turnrightt;
     shoot=shoott;
     move=movee;
     turns=turnss;
    
}
