/*
this is a wumpus world Environment implementation code .


*/

#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include "Room.h"
#include "World.h"
using namespace std;

World::World()
{
    init_empty_world();
    generate_position();
    World::pos = 0;
    // check_percolaton();
}
//initializes an empty box with no position information
void World::init_empty_world()
{
    Room common = Room();
    int count = 16;
    for (int i = 0; i < count; i++)
    {
        boxes[i] = common;
    }
}
//generates random positions along with sensor information
void World::generate_position()
{
    srand((int)time(0));
    int iter = 3;
    set<vector<int>> values;        // a set of position for storing wumpus, pit , gold
    vector<int> agentPosition;      // to hold the agent position
    vector<int> restrictedPosition; //to hold the restricted position adjcent to the agent
    agentPosition.push_back(0);
    agentPosition.push_back(0);
    values.insert(agentPosition);
    restrictedPosition.push_back(1);
    restrictedPosition.push_back(0);
    values.insert(restrictedPosition);
    vector<int> restrictedPosition2;
    restrictedPosition2.push_back(0);
    restrictedPosition2.push_back(1);
    values.insert(restrictedPosition2);

    vector<int> room;
    int j = 0;
    while (values.size() < 10)
    {
        for (int i = 0; i < iter; ++i)
        {

            rand() % 15;
        }
        room.push_back(rand() % 4);
        room.push_back(rand() % 4);
        values.insert(room);
    }

    values.erase(values.find(agentPosition));
    values.erase(values.find(restrictedPosition2));
    values.erase(values.find(restrictedPosition));
    set<vector<int>>::iterator it = values.begin();
    ++it;
    vector<int> wumpus = *it; //random position for wumpus
    ++it;
    vector<int> gold = *it; //random position for gold
    ++it;
    vector<int> pit1 = *it; //random position for pit
    ++it;
    vector<int> pit2 = *it; //random position for pit
    ++it;
    vector<int> pit3 = *it; //random position for pit

    //now lets map this positions into our rooms in the boxes

    //1- ASSIGNING WUMPUS
    create_wumpus(wumpus);
    //2- ASSIGNING pit
    create_pit(pit1);
    create_pit(pit2);
    create_pit(pit3);

    //3- ASSIGNING gold
    create_gold(gold);
}
//creates a wumpus room at position and initialize a stench in adjacent rooms
void World::create_wumpus(vector<int> wumpus){
     int pos[] ={wumpus.at(0), wumpus.at(1)};
     int point=convert_to_1d(pos);
     //create the wumpus
     boxes[point].set_wumpus(true);

    //initialize  stench on adjacent nodes

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for(int i=0;i<adjacents.size();i++){
        boxes[adjacents.at(i)].set_stench(true);
    }



}
//creates a pit room at position and initialize a breez in adjacent rooms
void World::create_pit(vector<int> pit){

    int pos[] ={pit.at(0), pit.at(1)};
     int point=convert_to_1d(pos);
     //create the pit
     boxes[point].set_pit(true);

    //initialize breez on adjacent nodes

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for(int i=0;i<adjacents.size();i++){
        boxes[adjacents.at(i)].set_breez(true);
    }
}
//creates a gold room at position and initialize a glitter in the rooms
void World::create_gold(vector<int> gold){
    int pos[] ={gold.at(0), gold.at(1)};
     int point=convert_to_1d(pos);
     //initialize glitter
     boxes[point].set_gliter(true);
}
vector<int> World::get_adjacent_rooms(int positon)
{
    vector<int> room = convert_to_2d(positon);
    int i = room.at(0);
    int j = room.at(1);
    vector<int> adjacents;
    vector<int[]> adj;
    adj.push_back({i + 1, j});
    adj.push_back({i - 1, j});
    adj.push_back({i, j + 1});
    adj.push_back({i, j - 1});
    for(vector<int[]>::iterator iterr=adj.begin();iterr!=adj.end();++iterr){
         int adjj[2];
         adjj[0]=*iterr[0];
         adjj[1]=*iterr[1];
        if(is_valid_position(adjj[0],adjj[0])){

          adjacents.push_back(convert_to_1d(adjj));

        }

    }
    return adjacents;

}
//validates is a position is valid or not if not valid then bump
bool is_valid_position(int i, int j)
{
    if (i >= 0 && j >= 0 && i <= 3 && j <= 3)
    {
        return true;
    }
    return false;
}
//checks if there is a way between the agent position(0,0) and the gold at
bool check_percolaton(int agent_pos, int gold_position);
//converts 1d position to 2d
vector<int> World::convert_to_2d(int position)
{
    int i = position % 4;
    int j = position / 4;
    vector<int> arr = {i, j};
    return arr;
}
//converts 2d position to 1d
int World::convert_to_1d(int pos[])
{
    int position = pos[0] + (pos[1] * 4);
    return position;
}

// playing functons
// turn the agent face direction
// moving to the move_<direction> direction given current
// position (c_pos) default current position (pos)
// turn left or right
string World::turn_left(string direction)
{
  string updated_direction;
  if( direction == "top" ){
    updated_direction = "left";
  }else if( direction == "bottom" ){
    updated_direction = "right";
  }else if( direction == "left" ){
    updated_direction = "bottom";
  }else{
    updated_direction = "top";
  }
  return updated_direction;
}

string World::turn_right(string direction)
{
  string updated_direction;
  if( direction == "top" ){
    updated_direction = "right";
  }else if( direction == "bottom" ){
    updated_direction = "left";
  }else if( direction == "left" ){
    updated_direction = "top";
  }else{
    updated_direction = "bottom";
  }
  return updated_direction;
}

// move left, right, top, bottom
vector<int> World::move_left(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[1] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1] - 1;
  }
  return new_pos;
}

vector<int> World::move_right(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[1] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1] + 1;
  }
  return new_pos;
}

vector<int> World::move_down(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[0] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0] - 1;
    new_pos[1] = current_pos[1];
  }
  return new_pos;
}

vector<int> World::move_up(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[0] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0] + 1;
    new_pos[1] = current_pos[1];
  }
  return new_pos;
}

// move forward or backward
vector<int> World::move_forward(int current_pos, string direction)
{
  if( direction == "left" ){
    return move_left(current_pos);
  }else if( direction == "right"){
    return move_right(current_pos);
  }else if( direction == "up"){
    return move_up(current_pos);
  }else{
    return move_down(current_pos);
  }
}

vector<int> World::move_backward(int current_pos, string direction)
{
  if( direction == "left" ){
    return move_right(current_pos);
  }else if( direction == "right"){
    return move_left(current_pos);
  }else if( direction == "up"){
    return move_down(current_pos);
  }else{
    return move_up(current_pos);
  }
}
// shoot the wumpus
//kills the wumpus
void World::shoot() {}
// checks if the agent can shoot the wumpus
bool World::can_shoot() {}
//kills the agent
void World::kill_Agent() {}
//checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
// can be called after every action(move, shoot)
bool World::is_game_over() {}
