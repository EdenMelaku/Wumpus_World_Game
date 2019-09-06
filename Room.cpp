/* 
     Room includes sensor informations for a single box in the world in the form bool
    
       WILL BE VISIBLE WHEN IN THE ROOM
       pos0- (S)stench - wumpus in adj
       pos1- (B)breez  - pit in adj
       pos2- (V)visited

       WILL NOT BE VISIBLE just action
       pos3- (G)gliter or gold in room  // wins the game
       pos4- (P)pit    // looses the game
       pos5- (W)wumpus  // wumpus is dead
       
       
    

*/
#include "Room.h"

using namespace std;

Room::Room()
{
    set_breez(false);
    set_stench(false);
    set_visited(false);
    set_gliter(false);
    set_pit(false);
    set_wumpus(false);
}
//sets the value of the sensor information to the given bool val;
void Room::set_stench(bool val)
{
    stench = val;
}
void Room::set_breez(bool val)
{
    breez = val;
}

void Room::set_visited(bool val)
{
    visited = val;
}
void Room::set_gliter(bool val)
{
    gliter = val;
}
void Room::set_pit(bool val)
{
    pit = val;
}
void Room::set_wumpus(bool val)
{
    wumpus = val;
}

//can return the sensor information
bool Room::get_stench(){
    return stench;
}
bool Room::get_breez(){
    return breez;
}
bool Room::get_visited(){
    return visited;
}
bool Room::get_gliter()
{
    return gliter;
}
bool Room::get_pit()
{
return pit;
}
bool Room::get_wumpus()
{
    return wumpus;
}
