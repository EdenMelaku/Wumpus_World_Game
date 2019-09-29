#include "playableWorld.h"
#include <set>


/**
 * @brief Construct a new playable World::playable World object
 * 
 */
playableWorld::playableWorld(){}

/**
 * @brief Construct a new playable World::playable World object
 * 
 * @param agent_locationn       The location of the agent within the world
 * @param agent_directionn      The direction of the agent
 * @param worldd                The world that the Agent navigates
 */
playableWorld::playableWorld(pair<int, int> agent_locationn, string agent_directionn,World worldd )
{
  agent_location = agent_locationn;
  agent_direction = agent_directionn;
  world=worldd;
}

/**
 * @brief   Get the location of the agent in the world
 * 
 * @return pair<int, int>   The location of the agent in row and column
 */
pair<int, int> playableWorld::get_agent_location()
{
  return agent_location;
}

/**
 * @brief     Set the location of the Agent within the world
 * 
 * @param agent_locationn   A pair<int, int> value which uses the location in terms of row and column
 */
void playableWorld::set_agent_location(pair<int, int> agent_locationn)
{ 
  if(world.is_valid_position(agent_location.first, agent_location.second)){ 
    agent_location = agent_locationn;
  }
  else cout<<"BUMP"<<endl;
  cout<<agent_location.first<<","<< agent_location.second<<endl;

}

/**
 * @brief Get the direction that the Agent will align in
 * 
 * @return string   The direction of the Agent
 */
string playableWorld::get_agent_direction(){
  return agent_direction;
}

/**
 * @brief Set the direction of the Agent in the game
 * 
 * @param agent_directionn The direction that the agent will align towards
 */
void playableWorld::set_agent_direction(string agent_directionn)
{
  agent_direction = agent_directionn;
}

/**
 * @brief Turns the agent to the direction to the left of current direction
 * 
 * @return string The direction of the Agent after turning towards the left
 */
string playableWorld::turn_left()
{
  string agent_direction = get_agent_direction();
  if( agent_direction == "top" ){
    set_agent_direction("left");
  }
  else if( agent_direction == "bottom" ){
    set_agent_direction("right");
  }
  else if( agent_direction == "left" ){
    set_agent_direction("bottom");
  }
  else{
    set_agent_direction("top");
  }
  return get_agent_direction();
}

/**
 * @brief Turns the agent to the direction to the right of current direction
 * 
 * @return string The direction of the Agent after turning towards the right
 */
string playableWorld::turn_right()
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

/**
 * @brief Command to allow the Agent to move towards the left in the world and update agent's location
 * 
 */
void playableWorld::move_left()
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

/**
 * @brief Command to allow the Agent to move towards the right in the world and update agent's location
 * 
 */
void playableWorld::move_right()
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

/**
 * @brief Command to allow the Agent to move in a downward direction in the world and update agent's location
 * 
 */
void playableWorld::move_down()
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

/**
 * @brief Command to allow the Agent to move in a downward direction in the world and update agent's location
 * 
 */
void playableWorld::move_top()
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

/**
 * @brief Moves the agent through the world in a forward direction using the move_left, move_right_ move_down and move_top commands
 * 
 * @return pair<int, int> The location of the agent after moving forward in the current direction of the agent.
 */
pair<int, int> playableWorld::move_forward()
{
  string agent_direction = get_agent_direction();
  if( agent_direction == "left" ){
    move_left();
  }
  else if( agent_direction == "right"){
    move_right();
  }
  else if( agent_direction == "top"){
    move_top();
  }
  else{
    move_down();
  }
  return get_agent_location();
}

/**
 * @brief Moves the agent through the world in a forward direction using the move_left, move_right_ move_down and move_top commands
 * 
 * @return pair<int, int> The location of the agent after moving backward in the curent direction of the agent.
 */
pair<int, int> playableWorld::move_backward()
{
  string agent_direction = get_agent_direction();
  if( agent_direction == "left" ){
    move_right();
  }
  else if( agent_direction == "right"){
    move_left();
  }
  else if( agent_direction == "top"){
    move_down();
  }
  else{
    move_top();
  }
  return get_agent_location();
}

/**
 * @brief Checks if the wumpus is in the the line of direction of the agent.
 * 
 * @param wumpus_location     The current location of the wumpus.
 * @return true               The wumpus is in the direction that the Agent currently has.
 * @return false              The wumpus is not in the direction that the Agent currently has.
 */
bool playableWorld::is_wumpus_in_line_sight(pair<int, int> wumpus_location){
  pair<int, int> agent_location = get_agent_location();
  string agent_direction = get_agent_direction();
  if(agent_direction == "left"){
    // if the agent and the wumpus are at the same row and wumpus is infront of the agent
    if(agent_location.first == wumpus_location.first && agent_location.second >= wumpus_location.second){
      return true;
    }
    else{
      return false;
    }
  }
  else if(agent_direction == "right"){
    // if the agent and the wumpus are at the same row and wumpus is infront of the agent
    if(agent_location.first == wumpus_location.first && agent_location.second <= wumpus_location.second){
      return true;
    }
    else{
      return false;
    }
  }
  else if(agent_direction == "down"){
    // if the agent and the wumpus are at the same column and wumpus is infront of the agent
    if(agent_location.second == wumpus_location.second && agent_location.first >= wumpus_location.first){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    // if the agent and the wumpus are at the same column and wumpus is infront of the agent
    if(agent_location.first == wumpus_location.first && agent_location.first <= wumpus_location.first){
      return true;
    }
    else{
      return false;
    }
  }
}

/**
 * @brief Command to shoot the wumpus in the game, and removes the wumpus from the game.
 * 
 */
void playableWorld::shoot( ){
  pair<int, int> wumpus_location = world.get_wumpus_location();
 // bool has_arrow = play_Ground::arrow=1;
  if(arrow>0){
    if(is_wumpus_in_line_sight(wumpus_location)){
      world.remove_wumpus(); 
    }
   arrow--;
  }
}
