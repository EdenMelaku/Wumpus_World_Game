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
    //converts 1d position to 2d
    int * convert_to_2d (int position);
     //converts 2d position to 1d
    int  convert_to_1d (int pos []);

    // int move_left(int current_pos[])
    // {
    //   int new_pos[2];
    //   if(current_pos[0] == 0){
    //     new_pos = current_pos;
    //   }else{
    //     new_pos[0] = current_pos[0] - 1;
    //     new_pos[1] = current_pos[1];
    //   }
    //   return new_pos;
    // }
    string turn_left(string direction)
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

    string turn_right(string direction)
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


    int move_left(int current_pos[2])
    {
      int new_pos[2];
      if(current_pos[1] == 0){
        new_pos[0] = current_pos[0];
        new_pos[1] = current_pos[1];
      }else{
        new_pos[0] = current_pos[0];
        new_pos[1] = current_pos[1] - 1;
      }
      return convert_to_1d(new_pos);
    }

    int move_right(int current_pos[2])
    {
      int new_pos[2];
      if(current_pos[1] == 0){
        new_pos[0] = current_pos[0];
        new_pos[1] = current_pos[1];
      }else{
        new_pos[0] = current_pos[0];
        new_pos[1] = current_pos[1] + 1;
      }
      return convert_to_1d(new_pos);
    }

    int move_bottom(int current_pos[2])
    {
      int new_pos[2];
      if(current_pos[0] == 0){
        new_pos[0] = current_pos[0];
        new_pos[1] = current_pos[1];
      }else{
        new_pos[0] = current_pos[0] - 1;
        new_pos[1] = current_pos[1];
      }
      return convert_to_1d(new_pos);
    }

    int move_top(int current_pos[2])
    {
      int new_pos[2];
      if(current_pos[0] == 0){
        new_pos[0] = current_pos[0];
        new_pos[1] = current_pos[1];
      }else{
        new_pos[0] = current_pos[0] + 1;
        new_pos[1] = current_pos[1];
      }
      return convert_to_1d(new_pos);
    }

    int move_forward(int current_pos[2], string direction)
    {
      if( direction == "left" ){
        return move_left(current_pos);
      }else if( direction == "right"){
        return move_right(current_pos);
      }else if( direction == "top"){
        return move_top(current_pos);
      }else{
        return move_bottom(current_pos);
      }
    }

    int move_backward(int current_pos[2], string direction)
    {
      if( direction == "left" ){
        return move_right(current_pos);
      }else if( direction == "right"){
        return move_left(current_pos);
      }else if( direction == "top"){
        return move_bottom(current_pos);
      }else{
        return move_top(current_pos);
      }
    }
};
