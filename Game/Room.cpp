#include <iostream>

#include "Room.h"

Room::Room(){
    ;
}
Room::Room(int row, int column)
{
    location = make_pair(row, column);
    cout<<"created room at"<<row<<" "<<column<<endl;
}
pair<int, int> Room::getLocation()
{
    return location;
}
void Room::set_breeze(bool value)
{
    breeze = value;
}
bool Room::get_breeze()
{
    return breeze;
}
void Room::set_stench(bool value)
{
    stench = value;
}
bool Room::get_stench()
{
    return stench;
}
void Room::set_glitter(bool value)
{
    glitter = value;
}
bool Room::get_glitter()
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
