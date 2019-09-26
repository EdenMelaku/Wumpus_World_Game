//
// Created by eden on 25/09/2019.
//

#include "actions.h"
#include "playableWorld.h"
#include "World.h"
#include "Room.cpp"
#include "agent/sensor.h"



void turn(string direction){
    if(direction=='left'){
        playableWord::turn_left();
    }
    else if(direction=='right'){
        playableWord::turn_right();
    }
    else if(direction=='top'){
        playableWord::turn_top();
    }
    else if(direction=='bottom'){
        playableWord::turn_bottom();
    }

}
/*
 *
 */
vector<Sensor> actions::run(){
    pair<int, int> location=playableWorld::get_agent_location();
    if(turnleft) { turn("left");}
    else if(turnright) { turn('right'); }
    else if(turnup) { turn('top'); }
    else if(turndown) { turn('bottom'); }

    if(move) { location = playableWorld::move_forward(); }
    if(shoot) { playableWorld::shoot(); }

    Room room = World::boxes.at(location.first).at(location.second);
    vector<Sensor> perception;
    if(room.get_breeze()) {
        Type type=Type::B;
        Sensor s=Sensor(location,type);
        perception.push_back(s);
    }
    if(room.get_stench()){
        Type type=Type::S;
        Sensor s=Sensor(location,type);
        perception.push_back(s);
    }
    if(room.get_glitter()){
        Type type=Type::G;
        Sensor s=Sensor(location,type);
        perception.push_back(s);
    }
    if(room.has_pit()){
        Type type=Type::P;
        Sensor s=Sensor(location,type);
        perception.push_back(s);
    }
    if(room.has_wumpus()){
        Type type=Type::W;
        Sensor s=Sensor(location,type);
        perception.push_back(s);
    }
    return perception;
}