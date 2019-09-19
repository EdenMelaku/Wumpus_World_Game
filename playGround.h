/*
this is a playGround header file.
this class is responsible for the dynamic behavoirs of the game
creating a playable environment is the main task of this module

*/

#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class PlayGround
{
private:
    bool is_wumpus_dead;
    bool is_agent_dead;
    bool is_gold_found;
    pair<int, int> agentLocation;
   
    //the current point of the player
    int point;
    
public: 
    int arrow=1;
    void penalize(int value);
    void reward(int value);

    //checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
    // can be called after every action(move, shoot)
    bool is_game_over() {}
    //kills the agent
   
};
#endif