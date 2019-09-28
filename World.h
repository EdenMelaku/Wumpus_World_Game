/*
this is a wumpus world Environment header file.
it includes the attributes and methods that has to be included in the world
includes the Room.h file which is the implmentation for each box from the 16

*/

#ifndef WORLD_H
#define WORLD_H
#include <string>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include <set>
#include <ctime>
#include "Room.h"
using namespace std;

class World
{
private:
    int size;
    //records current position of the player
    int pos;
    bool is_wumpus_dead;
    bool is_agent_dead;
    bool is_gold_found;

    pair<int, int> wumpus_location;
    vector<pair<int, int> > pit_locations;
    pair<int, int> gold_location;

public:
    vector<vector<Room> > boxes;

    World();
    World(int size);
    //initializes an empty box with no position information
    // getter and setter for wumpus_location attribute
    pair<int, int> get_wumpus_location();

    void set_wumpus_location(pair<int, int> wumpus_location);

    // getter and setter for pit_locations attribute
    vector<pair<int, int> > get_pit_locations();
    void set_pit_locations(vector<pair<int, int> > pit_locations);

    // getter and setter for gold_location attribute
    pair<int, int> get_gold_location();
    void set_gold_location(pair<int, int>);

    void init_empty_world();
    //generates random positions along with sensor information
    void generate_position();
    //creates a wumpus room at position and initialize a stench in adjacent rooms
    void create_wumpus(pair<int,int> wumpus);
    // remove wumpus
    void remove_wumpus();
    //creates a pit room at position and initialize a breez in adjacent rooms
    void create_pit(pair<int,int> pit);
    //creates a gold room at position and initialize a glitter in the rooms
    void create_gold(pair<int,int> gold);
    //returns adjacent rooms
    vector<int> get_adjacent_rooms(int positon);
    //validates is a position is valid or not if not valid then bump
    bool is_valid_position(int i, int j);
    //checks if there is a way between the agent position(0,0) and the gold at
    bool check_percolaton(int agent_pos, int gold_position);
    int convert_vector_to_1d(vector<int> pos);
    int convert_to_1d(int pos[]);
    vector<int> convert_to_2d(int position);
};
#endif
