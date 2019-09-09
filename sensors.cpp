#include "sensors.h"
#include "World.h"

bool is_stinch(int agent_position)
{
  if(boxes[agent_position].has_stench()){
    return true;
  }
  return false;
}

bool is_breez(int agent_position)
{
  if(boxes[agent_position].has_breeze()){
    return true;
  }
  return false;
}

bool is_glitter(int agent_position)
{
  if(boxes[agent_position].has_glitter()){
    return true;
  }
  return false;
}

bool is_scream(int agent_position)
{
  return false;
}

bool is_bump(int agent_position)
{
  return false;
}
