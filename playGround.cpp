//
// Created by eden on 25/09/2019.
//


#include <set>
#include "playGround.h"


using namespace std;

PlayGround::PlayGround()
{
    ;
}PlayGround::PlayGround(string player,playableWorld playableworld)
{
    player = player;
    playableworld =playableworld;
    is_agent_dead = false;
    is_wumpus_dead = false;
    is_gold_found = false;
    direction = "up";
    action=actions(false,false,false,false,{0,0});
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
void PlayGround::changeDir(string dir){
    direction=dir;
}

void PlayGround::kill_agent()
{
  pair<int, int> agent_location = playableworld.get_agent_location();
  pair<int, int> wumpus_location = playableworld.world.get_wumpus_location();
  vector<pair<int, int> > pit_locations = playableworld.world.get_pit_locations();
  set<pair<int,int> > pits(pit_locations.begin(),pit_locations.end());
  if(agent_location == wumpus_location || pits.find(agent_location)!=pits.end()){
    
    is_agent_dead=true;

  }
}

vector<sensor> PlayGround::infer()
{
    pair<int, int> location=playableworld.get_agent_location();
    if(action.turnleft) {playableworld.turn_left();}
    else if(action.turnright) { playableworld.turn_right(); }
    

    if(move) { location = playableworld.move_forward(); }
    if(shoot) { playableworld.shoot(); }

    Room room = playableworld.world.boxes.at(location.first).at(location.second);
    vector<sensor> perception;
    if(room.get_breeze()) {
        Type type=Type::B;
        sensor s=sensor(location,type);
        perception.push_back(s);
    }
    if(room.get_stench()){
        Type type=Type::S;
        sensor s=sensor(location,type);
        perception.push_back(s);
    }
    if(room.get_glitter()){
        Type type=Type::G;
        sensor s=sensor(location,type);
        perception.push_back(s);
    }
    if(room.has_pit()){
        Type type=Type::P;
        sensor s=sensor(location,type);
        perception.push_back(s);
    }
    if(room.has_wumpus()){
        Type type=Type::W;
        sensor s=sensor(location,type);
        perception.push_back(s);
    }
    if (is_wumpus_dead)
    {
        Type t = Type::scream;
        sensor s = sensor(perception.at(0).get_Location(), t);
    }
    return perception;
}

