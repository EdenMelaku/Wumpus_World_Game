/* 
     Room includes sensor informations for a single box in the world in the form bool
    
       WILL BE VISIBLE WHEN IN THE ROOM
       pos0- (S)stinch - wumpus in adj
       pos1- (B)breez  - pit in adj
       pos2- (V)visited

       WILL NOT BE VISIBLE just action
       pos3- (G)gliter or gold in room  // wins the game
       pos4- (P)pit    // looses the game
       pos5- (W)wumpus  // wumpus is dead
       
       
    

*/

#ifndef ROOM_H
#define ROOM_H

#include <vector>
using namespace std;

class Room
{
private:
    bool stinch;
    bool breez;
    bool visited;
    bool gliter;
    bool pit;
    bool wumpus;

public:
//sets the value of the sensor information to the given bool val;
    void set_stinch(bool val);
    void set_breez(bool val);
    void set_visited(bool val);
    void set_gliter(bool val);
    void set_pit(bool val);
    void set_wumpus(bool val);
//can return the sensor information
    bool get_stinch();
    bool get_breez();
    bool get_visited();
    bool get_gliter();
    bool get_pit();
    bool get_wumpus();
};

#endif;