#include "actuator.h"

Actuator::Actuator(pair<int, int> agent_location, string agent_direction)
{
  Actuator::agent_location = agent_location;
  Actuator::agent_direction = agent_direction;
}

pair<int, int> Actuator::get_agent_location()
{
  return Actuator::agent_location;
}

void Actuator::set_agent_location(pair<int, int> agent_location)
{
  Actuator::agent_location = agent_location;
}

string Actuator::get_agent_direction(){
  return Actuator::agent_direction;
}

void Actuator::set_agent_direction(string agent_direction)
{
  Actuator::agent_direction = agent_direction;
}

string Actuator::turn_left()
{
  string agent_direction = get_agent_direction();
  if( agent_direction == "top" ){
    set_agent_direction("left");
  }else if( agent_direction == "bottom" ){
    set_agent_direction("right");
  }else if( agent_direction == "left" ){
    set_agent_direction("bottom");
  }else{
    set_agent_direction("top");
  }
  return get_agent_direction();
}

string Actuator::turn_right()
{
  string agent_direction = get_agent_direction();
  if( agent_direction == "top" ){
    set_agent_direction("right");
  }else if( agent_direction == "bottom" ){
    set_agent_direction("left");
  }else if( agent_direction == "left" ){
    set_agent_direction("top");
  }else{
    set_agent_direction("bottom");
  }
  return get_agent_direction();
}

// move left, right, top, bottom
void Actuator::move_left()
{
  pair<int, int> agent_location = get_agent_location();
  pair<int, int> updated_agent_location;
  if(agent_location.second == 1){
    // if agent location is in the left edge
    updated_agent_location.first = agent_location.first;
    updated_agent_location.second = agent_location.second;
  }else{
    updated_agent_location.first = agent_location.first;
    updated_agent_location.second = agent_location.second - 1;
  }
  set_agent_location(updated_agent_location);
}

void Actuator::move_right()
{
  pair<int, int> agent_location = get_agent_location();
  pair<int, int> updated_agent_location;
  if(agent_location.second == 4){
    // if agent location is in the right edge
    updated_agent_location.first = agent_location.first;
    updated_agent_location.second = agent_location.second;
  }else{
    updated_agent_location.first = agent_location.first;
    updated_agent_location.second = agent_location.second + 1;
  }
  set_agent_location(updated_agent_location);
}

void Actuator::move_down()
{
  pair<int, int> agent_location = get_agent_location();
  pair<int, int> updated_agent_location;
  if(agent_location.second == 1){
    // if agent location is in the bottom edge
    updated_agent_location.first = agent_location.first;
    updated_agent_location.second = agent_location.second;
  }else{
    updated_agent_location.first = agent_location.first - 1;
    updated_agent_location.second = agent_location.second;
  }
  set_agent_location(updated_agent_location);
}

void Actuator::move_top()
{
  pair<int, int> agent_location = get_agent_location();
  pair<int, int> updated_agent_location;
  if(agent_location.first == 4){
    // if agent location is in the left edge
    updated_agent_location.first = agent_location.first;
    updated_agent_location.second = agent_location.second;
  }else{
    updated_agent_location.first = agent_location.first + 1;
    updated_agent_location.second = agent_location.second;
  }
  set_agent_location(updated_agent_location);
}

// move forward or backward
pair<int, int> Actuator::move_forward()
{
  string agent_direction = get_agent_direction();
  if( agent_direction == "left" ){
    move_left();
  }else if( agent_direction == "right"){
    move_right();
  }else if( agent_direction == "top"){
    move_top();
  }else{
    move_down();
  }
  return get_agent_location();
}

pair<int, int> Actuator::move_backward()
{
  string agent_direction = get_agent_direction();
  if( agent_direction == "left" ){
    move_right();
  }else if( agent_direction == "right"){
    move_left();
  }else if( agent_direction == "top"){
    move_down();
  }else{
    move_top();
  }
  return get_agent_location();
}

int main(int argc, char const *argv[]) {
  cout << "this is simple test on the actuaror class\n";
  pair<int, int> agent_location = make_pair(1, 1);
  string agent_direction = "right";
  Actuator actuator = Actuator(agent_location, agent_direction);
  cout << "starting agent direction " << agent_direction << endl;
  cout << "starting agent_location (" << agent_location.first <<", " << agent_location.second <<")" << endl;
  string updated_agent_direction = actuator.turn_left();
  pair<int, int> updated_agent_location = actuator.move_forward();
  cout << "---------------------------------------------------" << endl;
  cout << "updated agent direction " << updated_agent_direction << endl;
  cout << "updated agent_location (" << updated_agent_location.first <<", " << updated_agent_location.second <<")" << endl;
  return 0;
}
