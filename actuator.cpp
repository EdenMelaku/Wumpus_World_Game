#include <actuator.h>
#include <World.h>

string Actuator::turn_left(string direction)
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

string Actuator::turn_right(string direction)
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

// move left, right, top, bottom
vector<int> Actuator::move_left(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[1] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1] - 1;
  }
  return new_pos;
}

vector<int> Actuator::move_right(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[1] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1] + 1;
  }
  return new_pos;
}

vector<int> Actuator::move_down(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[0] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0] - 1;
    new_pos[1] = current_pos[1];
  }
  return new_pos;
}

vector<int> Actuator::move_top(int position)
{
  vector<int> current_pos = convert_to_2d(position);
  vector<int> new_pos;
  if(current_pos[0] == 0){
    new_pos[0] = current_pos[0];
    new_pos[1] = current_pos[1];
  }else{
    new_pos[0] = current_pos[0] + 1;
    new_pos[1] = current_pos[1];
  }
  return new_pos;
}

// move forward or backward
vector<int> Actuator::move_forward(int current_pos, string direction)
{
  if( direction == "left" ){
    return move_left(current_pos);
  }else if( direction == "right"){
    return move_right(current_pos);
  }else if( direction == "up"){
    return move_top(current_pos);
  }else{
    return move_down(current_pos);
  }
}

vector<int> Actuator::move_backward(int current_pos, string direction)
{
  if( direction == "left" ){
    return move_right(current_pos);
  }else if( direction == "right"){
    return move_left(current_pos);
  }else if( direction == "up"){
    return move_down(current_pos);
  }else{
    return move_top(current_pos);
  }
}

// check if wumpus found in a given direction from a given positon
bool is_wumpus_found(vector<int> current_pos, string direction){
  vector<int> wumpus_pos = World::get_wumpus();
  if(direction == "left"){
    if(current_pos[0] == wumpus_pos[0] && current_pos[1] >= wumpus_pos[1]){
      return true;
    }else{
      return false;
    }
  }else if(direction == "right"){
    while(current_pos_2d[1] <= 3){
      current_pos_1d = convert_vector_to_1d(current_pos_2d);
      if(boxes[current_pos_1d].has_wumpus()){
        wumpus_pos = current_pos_1d;
      }
      current_pos_2d[1] = current_pos_  bool Actuator::is_wumpus_found(vector<int> current_pos, string direction)  2d[1] + 1;
    }
  }else if(direction == "down"){
    while(current_pos_2d[1] >= 0){
      current_pos_1d = convert_vector_to_1d(current_pos_2d);
      if(boxes[current_pos_1d].has_wumpus()){
        wumpus_pos = current_pos_1d;
      }
      current_pos_2d[1] = current_pos_2d[1] - 1;
    }
  }else{
    while(current_pos_2d[0] <= 3){
      current_pos_1d = convert_vector_to_1d(current_pos_2d);
      if(boxes[current_pos_1d].has_wumpus()){
        wumpus_pos = current_pos_1d;
      }
      current_pos_2d[0] = current_pos_2d[0] + 1;
    }
  }
  return wumpus_pos;
}

// shoot on the wumpus if it is been founded
void Actuator::shoot(int current_pos, string direction, bool arrow_status){
  if(arrow_status == true){
    int wumpus_pos = is_wumpus_found(current_pos, direction);
    if(wumpus_pos != -1){
      boxes[wumpus_pos].set_wumpus(false);
      //gets adjacent nodes
      vector<int> adjacents = World::get_adjacent_rooms(wumpus_pos);
      for(int i=0;i<adjacents.size();i++){
          boxes[adjacents.at(i)].set_stench(false);
      }
    }
  }
}

//kills the agent
void Actuator::kill_agent(Agent agent)
{
  int agent_pos = agent.getPosition();
  if(boxes[agent_pos].has_wumpus() || boxes[agent_pos].has_pit()){
    agent.setHealthStatus("dead");
  }
}

//checks if the game is over(is_wumpus_dead  V  is_gold_found V  is_agent_dead) ,
// can be called after every action(move, shoot)
bool Actuator::is_game_over(Agent agent)
{
  if(agent.getHealthStatus() == "dead"){
    return true;
  }else if(agent.getGold()){
    return true;
  }else{
    return false;
  }
}
