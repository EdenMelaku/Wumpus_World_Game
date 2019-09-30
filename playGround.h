/*
this is a playGround header file.
this class is responsible for the dynamic behavoirs of the game
creating a playable environment is the main task of this module

*/

#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <string>
#include <vector>
#include "sensor.h"
#include "actions.h"
#include "playableWorld.h"


using namespace std;

class PlayGround
{
private:
    
    pair<int, int> agentLocation;
    //vector<Sensor> infer(actions ac);
    //the current point of the player
    int point;
    bool move;
    bool shoot;

public:
   bool is_wumpus_dead;
    bool is_agent_dead;
    bool is_gold_found;
    actions action;
    string player;
    string direction;
    string turn;

    playableWorld playableworld;
    vector<vector<bool> > visiblity;
    PlayGround();
    PlayGround(string player,playableWorld playableworld);
    int arrow = 1;
    void penalize(int value);
    void reward(int value);
    void changeDir(string dir);

    //checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
    // can be called after every action(move, shoot)
    bool is_game_over();
    //vector<Sensor> infer(actions ac);
    void kill_agent();
    vector<sensor> infer();
};

#endif