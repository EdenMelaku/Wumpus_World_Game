/*
this is a wumpus world Environment header file.
it includes the attributes and methods that has to be included in the world
includes the Room.h file which is the implmentation for each box from the 16

*/

#ifndef WORLD_H
#define WORLD_H
#include <string>
#include <vector>
#include "Room.h"
using namespace std;

class World
{
private:

    Room boxes[16];
    //records current position of the player
    int static pos;
    bool is_wumpus_dead;
    bool is_agent_dead;
    bool is_gold_found;

public:
    World();
    //initializes an empty box with no position information
    void init_empty_world();
    //generates random positions along with sensor information
    void generate_position();
    //creates a wumpus room at position and initialize a stench in adjacent rooms
    void create_wumpus(vector<int> wumpus);
    //creates a pit room at position and initialize a breez in adjacent rooms
    void create_pit(vector<int> pit);
    //creates a gold room at position and initialize a glitter in the rooms
    void create_gold(vector<int> gold);
    //returns adjacent rooms
    vector<int> get_adjacent_rooms(int positon);
    //validates is a position is valid or not if not valid then bump
    bool is_valid_position(int i, int j);
    //checks if there is a way between the agent position(0,0) and the gold at
    bool check_percolaton(int agent_pos, int gold_position);
};
#endif
