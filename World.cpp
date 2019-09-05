#include <string>
#include <array>
#include <vector>
using namespace std;


class World
{
    private:
    //vector<bool> includes sensor informations in the form of 0 or 1
    // 1 - present and 0 not present 
    /* WILL BE VISIBLE WHEN IN THE ROOM
       pos0- (S)stinch - wumpus in adj
       pos1- (B)breez  - pit in adj
       pos2- (V)visited

       WILL NOT BE VISIBLE just action
       pos3- (G)gliter or gold in room  // wins the game
       pos4- (P)pit    // looses the game
       pos5- (W)wumpus  // agent is dead
       
       
    */
    vector<bool> boxes[4][4] ;
    
    public:

    World();
    //initializes an empty box with no position information
    void init_empty_world();
    //generates random positions along with sensor information
    void generate_position();
    //validates is a position is valid or not if not valid then bump
    bool is_valid_position(int i , int j);


     

    


};



