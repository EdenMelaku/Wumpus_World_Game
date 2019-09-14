#include "Agent.h"

pair<int,int> Agent::get_agent_location()
{
  return agent_location;
}

void Agent::set_agent_location(pair<int, int> agent_location)
{
  Agent::agent_location = agent_location;
}

string Agent::get_agent_direction()
{
  return agent_direction;
}

void Agent::set_agent_direction(string agent_direction)
{
  Agent::agent_direction = agent_direction;
}

bool Agent::get_is_alive()
{
  return is_alive;
}

void Agent::set_is_alive(bool is_alive)
{
  Agent::is_alive = is_alive;
}

bool Agent::get_has_arrow()
{
  return has_arrow;
}

void Agent::set_has_arrow(bool has_arrow)
{
  Agent::has_arrow = has_arrow;
}

vector<bool> Agent::get_senses()
{
  return Agent::senses;
}
void Agent::set_senses(vector<bool> senses)
{
  Agent::senses = senses;
}

// sensors
vector<bool> Agent::percieve_room(pair<int, int> room_location)
{
  // vector<string> room_info = World::grid[room_location.first][room_location.second];
  vector<bool> senses = World::get_room_senses(room_location);
  set_senses(senses);
  return senses;
}

// knowledge base propositional logic


// inference/reasoning
bool tableaux_calculator(string sentences)
{

}

// actuators/actions
