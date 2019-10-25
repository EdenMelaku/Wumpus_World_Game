//
// Created by eden on 25/09/2019.
//
#include <set>
#include "playGround.h"


using namespace std;

PlayGround::PlayGround()
{
    ;
}
PlayGround::PlayGround(string playerr, playableWorld playableworldd)
{
    player = playerr;
    playableworld = playableworldd;
    is_agent_dead = false;
    is_wumpus_dead = false;
    is_gold_found = false;
    direction = "up";
    action = actions();
}

void PlayGround::penalize(int value)
{
    point = point - value;
}

void PlayGround::reward(int value)
{
    point = point + value;
}
//checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
// can be called after every action(move, shoot)
bool PlayGround::is_game_over()
{
    return (is_agent_dead || is_gold_found);
}
void PlayGround::changeDir(string dir)
{
    direction = dir;
}

void PlayGround::kill_agent()
{
    pair<int, int> agent_location = make_pair(playableworld.agent_location.first - 1, playableworld.agent_location.second - 1);
    Room room = playableworld.world.boxes.at(agent_location.second).at(agent_location.first);
    if (room.has_wumpus() || room.has_pit())
    {
        is_agent_dead = true;
    }
}

vector<sensor> PlayGround::get_initial_perception()
{
        pair<int, int> location = playableworld.agent_location;
         Room room = playableworld.world.boxes.at(location.second - 1).at(location.first - 1);
    vector<sensor> perception;
    if (room.get_breeze())
    {
        Type type = Type::B;
        sensor s = sensor(location, type);
        perception.push_back(s);
        p.breeze=true;
    }
    if (room.get_stench())
    {
        Type type = Type::S;
        sensor s = sensor(location, type);
        perception.push_back(s);
        p.stench=true;
    }
    if (room.get_glitter())
    {
        Type type = Type::G;
        sensor s = sensor(location, type);
        perception.push_back(s);
        is_gold_found = true;
        p.glitter=true;
    }
    if (room.has_pit())
    {
        Type type = Type::P;
        sensor s = sensor(location, type);
        perception.push_back(s);

    }
    if (room.has_wumpus())
    {
        Type type = Type::W;
        sensor s = sensor(location, type);
        perception.push_back(s);
        p.wumpus=true;
    }
    if (is_wumpus_dead)
    {
        Type t = Type::scream;
        sensor s = sensor(perception.at(0).get_Location(), t);
        p.scream=true;
    }
    return perception;

}

vector<sensor> PlayGround::execute()
{
    pair<int, int> location = playableworld.agent_location;
    if (action.move)
    {
        location = playableworld.move_forward();
    }
    if (action.shoot)
    {
        playableworld.shoot();
    }
    kill_agent();

    Room room = playableworld.world.boxes.at(location.second - 1).at(location.first - 1);
    vector<sensor> perception;
    if (room.get_breeze())
    {
        Type type = Type::B;
        sensor s = sensor(location, type);
        perception.push_back(s);
        p.breeze=true;
    }
    if (room.get_stench())
    {
        Type type = Type::S;
        sensor s = sensor(location, type);
        perception.push_back(s);
        p.stench=true;
    }
    if (room.get_glitter())
    {
        Type type = Type::G;
        sensor s = sensor(location, type);
        perception.push_back(s);
        is_gold_found = true;
        p.glitter=true;
    }
    if (room.has_pit())
    {
        Type type = Type::P;
        sensor s = sensor(location, type);
        perception.push_back(s);

    }
    if (room.has_wumpus())
    {
        Type type = Type::W;
        sensor s = sensor(location, type);
        perception.push_back(s);
        p.wumpus=true;
    }
    if (is_wumpus_dead)
    {
        Type t = Type::scream;
        sensor s = sensor(perception.at(0).get_Location(), t);
        p.scream=true;
    }
    return perception;
}
