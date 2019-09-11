#include "Agent.h"


pair<int,int> Agent::get_location()
{
    return location;
}
Direction Agent::get_direction()
{
    return direction;
}
void Agent::set_direction(Direction new_direction)
{   
    direction = new_direction;
}
// sensors
bool Agent::is_alive()
{
    return alive;
}
void Agent::shoot()
{

}
