#include <iostream>
#include <string>
#include <vector>
// #include <tuple>

using namespace std;

class Actuator
{
  // playing functons
  //moving to the move_<direction> direction given current
  //position (c_pos) default current position (pos)
  string turn_left(string direction);
  string turn_right(string direction);

  vector<int> move_left(int current_pos);
  vector<int> move_right(int current_pos);
  vector<int> move_down(int current_pos);
  vector<int> move_top(int current_pos);

  vector<int> move_forward(int current_pos, string direction);
  vector<int> move_backward(int current_pos, string direction);

  // shoot the wumpus
  //kills the wumpus
  // void shoot();
  // checks if the agent can shoot the wumpus
  // bool can_shoot();

  // bool is_arrow_left(Agent agent);
  bool is_wumpus_found(vector<int> current_pos, string direction);
  void shoot(int current_pos, string direction);
  //kills the agent
  void kill_agent();
  //checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
  // can be called after every action(move, shoot)
  bool is_game_over();
}
