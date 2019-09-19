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
    int count = 4;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {

            Room common = Room(i, j);
            boxes[i][j] = common;
        }
    }
}
// getter and setter for wumpus_location attribute
pair<int, int> World::get_wumpus_location()
{
    return wumpus_location;
}
void World::set_wumpus_location(pair<int, int> wumpus_location)
{
    World::wumpus_location = wumpus_location;
}

// getter and setter for pit_locations attribute
vector<pair<int, int>> World::get_pit_locations()
{
    return World::pit_locations;
}
void World::set_pit_locations(vector<pair<int, int>> pit_locations)
{
    World::pit_locations = pit_locations;
}

// getter and setter for gold_location attribute
pair<int, int> World::get_gold_location()
{
    return World::gold_location;
}
void World::set_gold_location(pair<int, int> gold_location)
{
    World::gold_location = gold_location;
}

//generates random positions along with sensor information
void World::generate_position()
{

    srand((int)time(0));
    int iter = 3;
    set<vector<int>> store;         // a set of position for storing wumpus, pit , gold
    vector<int> agentPosition;      // to hold the agent position
    vector<int> restrictedPosition; //to hold the restricted position adjcent to the agent
    agentPosition.push_back(0);
    agentPosition.push_back(0);
    store.insert(agentPosition);
    restrictedPosition.push_back(1);
    restrictedPosition.push_back(0);
    store.insert(restrictedPosition);
    vector<int> restrictedPosition2;
    restrictedPosition2.push_back(0);
    restrictedPosition2.push_back(1);
    store.insert(restrictedPosition2);

    vector<int> rooms;
    int j = 0;
    while (store.size() < 10)
    {
        for (int i = 0; i < iter; ++i)
        {

            rand() % 15;
        }
        rooms.push_back(rand() % 4);
        rooms.push_back(rand() % 4);
        store.insert(rooms);
    }

    store.erase(store.find(agentPosition));
    store.erase(store.find(restrictedPosition2));
    store.erase(store.find(restrictedPosition));
    set<vector<int>>::iterator it = store.begin();
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
void World::create_wumpus(vector<int> wumpus)
{
    int pos[] = {wumpus.at(0), wumpus.at(1)};
    int point = convert_to_1d(pos);
    //create the wumpus
    Occupant wumpu = Occupant::wumpus;
    boxes[pos[0]][pos[1]].set_occupant(wumpu);

    //initialize  stench on adjacent nodes

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for (int i = 0; i < adjacents.size(); i++)
    {
        int pos[] = {adjacents.at(0), adjacents.at(1)};
        boxes[pos[0]][pos[1]].set_stench(true);
    }
}
//creates a pit room at position and initialize a breez in adjacent rooms
void World::create_pit(vector<int> pit)
{

    int pos[] = {pit.at(0), pit.at(1)};
    int point = convert_to_1d(pos);
    //create the pit
    Occupant pitt = Occupant::pit;
    boxes[pos[0]][pos[1]].set_occupant(pitt);

    //initialize breez on adjacent nodes

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for (int i = 0; i < adjacents.size(); i++)
    {
        int pos[] = {adjacents.at(0), adjacents.at(1)};

        boxes[pos[0]][pos[1]].set_breeze(true);
    }
}
//creates a gold room at position and initialize a glitter in the rooms
void World::create_gold(vector<int> gold)
{
    int pos[] = {gold.at(0), gold.at(1)};
    int point = convert_to_1d(pos);
    //initialize glitter
    boxes[pos[0]][pos[1]].set_glitter(true);
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
    for (vector<int[]>::iterator iterr = adj.begin(); iterr != adj.end(); ++iterr)
    {
        int adjj[2];
        adjj[0] = *iterr[0];
        adjj[1] = *iterr[1];
        if (is_valid_position(adjj[0], adjj[0]))
        {

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

//converts 2d position to 1d
int World::convert_vector_to_1d(vector<int> pos)
{
    int position = pos[0] + (pos[1] * 4);
    return position;
}
