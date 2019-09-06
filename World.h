/* 
this is a wumpus world Environment header file.
it includes the attributes and methods that has to be included in the world 
includes the Room.h file which is the implmentation for each box from the 16

*/

#ifndef WORLD_H
#define WORLD_H
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
    //validates is a position is valid or not if not valid then bump
    bool is_valid_position(int i, int j);
    //checks if there is a way between the agent position(0,0) and the gold at
    bool check_percolaton(int agent_pos, int gold_position);
    //converts 1d position to 2d
    int *convert_to_2d(int position);
    //converts 2d position to 1d
    int convert_to_1d(int pos[]);

    // playing functons
    //moving to the move_<direction> direction given current
    //position (c_pos) default current position (pos)
    void move_left(int c_pos = pos);
    void move_right(int c_pos = pos);
    void move_up(int c_pos = pos);
    void move_down(int c_pos = pos);
    // shoot the wumpus
    //kills the wumpus
    void shoot();
    // checks if the agent can shoot the wumpus
    bool can_shoot();
    //kills the agent
    void kill_Agent();
    //checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
    // can be called after every action(move, shoot)
    bool is_game_over();
};
#endif
