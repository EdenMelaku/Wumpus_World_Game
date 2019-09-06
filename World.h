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
    //converts 1d position to 2d
    vector<int> convert_to_2d(int position);
    //converts 2d position to 1d
    int convert_to_1d(int pos[]);
    // convert vector 2D position to 1D
    int convert_vector_to_1d(vector<int> pos);

    // playing functons
    //moving to the move_<direction> direction given current
    //position (c_pos) default current position (pos)
    string turn_left(string direction);
    string turn_right(string direction);

    vector<int> move_left(int c_pos = pos);
    vector<int> move_right(int c_pos = pos);
    vector<int> move_down(int c_pos = pos);
    vector<int> move_top(int c_pos = pos);

    vector<int> move_forward(int current_pos, string direction);
    vector<int> move_backward(int current_pos, string direction);

    // shoot the wumpus
    //kills the wumpus
    // void shoot();
    // checks if the agent can shoot the wumpus
    // bool can_shoot();

    bool is_arrow_left(Agent agent);

    int is_wumpus_found(int current_pos, string direction);

    void shoot(int current_pos, string direction);
};
#endif
