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

string Agent::set_agent_direction(string agent_direction)
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

vector<string> Agent::get_senses()
{
  return Agent::senses;
}
void Agent::set_senses(vector<string> senses)
{
  Agent::senses = senses;
}

// sensors
void Agent::percieve_room(pair<int, int> room_location)
{
  vector<string> room_info = World::grid[room_location.first][room_location.second];
  set_senses(room_info);
}

// knowledge base propositional logic
// inference/reasoning
bool tableaux_calculator(string propositional_logic);
// actuators/actions
