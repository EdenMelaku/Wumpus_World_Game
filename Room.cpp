#include "Room.h"


Room::Room(int row, int column)
{
    location = make_pair(row, column);
}
pair<int, int> Room::getLocation()
{
    return location;
}
void Room::make_breeze()
{
    breeze = true;
}
bool Room::has_breeze()
{
    return breeze;
}
void Room::make_stench()
{
    stench = true;
}
bool Room::has_stench()
{
    return stench;
}
void Room::make_glitter()
{
    glitter = true;
}
bool Room::has_glitter()
{
    return glitter;
}
void Room::set_occupant(Occupant setOccupant)
{
    occupant = setOccupant;
}
Occupant Room::get_occupant()
{
    return occupant;
}
bool Room::has_wumpus()
{
    return (occupant == Occupant::wumpus);
}
bool Room::has_pit()
{
    return (occupant == Occupant::pit);
}
bool Room::has_gold()
{
    return (occupant == Occupant::gold);
}