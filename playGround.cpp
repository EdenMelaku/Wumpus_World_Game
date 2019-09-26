//
// Created by eden on 25/09/2019.
//

#include <string>
#include <vector>
#include "playGround.h"

using namespace std;
vector<vector<bool>> visiblity;

void penalize(int value);
void reward(int value);

//checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
// can be called after every action(move, shoot)
bool is_game_over()
{
    ;
}
PlayGround::PlayGround(){
    ;
}
PlayGround::PlayGround(string playern, World worldn)
{
    world = worldn;
    player = playern;
}
//kills the agent
/*
vector<Sensor> playGround::infer(actions ac)
{
    vector<Sensor> perception = ac.run();
    if (is_wumpus_dead)
    {
        Type t = Type::scream;
        Sensor s = Sensor(perception.at(0).getLocation(), t);
    }
    return perception;
}
*/