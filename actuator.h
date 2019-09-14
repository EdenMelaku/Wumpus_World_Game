#include "World.h"

using namespace std;

class Actuator
{
private:
  pair<int, int> agent_location;
  string agent_direction;

public:
  // the class constructor
  Actuator(pair<int, int> agent_location, string agent_direction);

  // getter and setter for agent_location attribute
  pair<int, int> get_agent_location();
  void set_agent_location(pair<int, int>);

  // getter and setter for agent_direction attrubute
  string get_agent_direction();
  void set_agent_direction(string agent_direction);

  // turn left or right from current agent direction
  string turn_left();
  string turn_right();

  // move left, right, down or top
  void move_left();
  void move_right();
  void move_down();
  void  move_top();

  // move forward or backward
  pair<int, int> move_forward();
  pair<int, int> move_backward();

  // check if wumpus is in line sight of the agent
  bool is_wumpus_in_line_sight(pair<int, int> wumpus_location);
  void shoot();
  void grab_gold();
  //kills the agent
  void kill_agent();
  //checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
  // can be called after every action(move, shoot)
  bool is_game_over();
};
