#include "Room.h"


/**
 * @brief Construct a new Room:: Room object
 * 
 */
Room::Room(){
    ;
}

/**
 * @brief Construct a new Room:: Room object
 * 
 * @param row       The row of the room in the world it is located in.
 * @param column    The row of the room in the world it is located in.
 */
Room::Room(int row, int column)
{
    location = make_pair(row, column);
}

/**
 * @brief Get the row and column attributes of the Room within the world.
 * 
 * @return pair<int, int>   The location of the room in terms of (row, column) ordering.
 */
pair<int, int> Room::getLocation()
{
    return location;
}

/**
 * @brief Set breeze attribute in the room, marking there is a pit in one or many adjacent rooms.
 * 
 * @param value  Boolean value of the breeze attribute determining whether it there is breeze in the room or not.
 */
void Room::set_breeze(bool value)
{
    breeze = value;
}

/**
 * @brief Retrieve the breeze attribute of a room, marking there is a pit in one or many adjacent rooms.
 * 
 * @return true     The room has breeze.
 * @return false    The room does not have breeze.
 */
bool Room::get_breeze()
{
    return breeze;
}

/**
 * @brief Set stench attribute in the room, marking there is a wumpus in one or many adjacent rooms.
 * 
 * @param value Boolean value of the stench attribute determining whether it there is stench in the room or not.
 */
void Room::set_stench(bool value)
{
    stench = value;
}

/**
 * @brief Retrieve the stench attribute of a room, marking there is a wumpus in one or many adjacent rooms.
 * 
 * @return true The room has stench.
 * @return false The room does not have stench. 
 */
bool Room::get_stench()
{
    return stench;
}

/**
 * @brief Set the glitter attribute of a room, marking there is gold in the room.
 * 
 * @param value Boolean value of the glitter attribute determining whether it there is gold in the room or not.
 */
void Room::set_glitter(bool value)
{
    glitter = value;
}

/**
 * @brief Retrieve the glitter attribute of a room, marking there is gold in the room.
 * 
 * @return true The room glitters.
 * @return false  The room does not glitter.
 */
bool Room::get_glitter()
{
    return glitter;
}

/**
 * @brief Set the Occupant in a room. An Occupant could be a pit, gold or wumpus.
 * 
 * @param setOccupant A wumpus, pit or gold.
 */
void Room::set_occupant(Occupant setOccupant)
{
    occupant = setOccupant;
}

/**
 * @brief Retrieve what occupant is in the room.
 * 
 * @return Occupant A wumpus, pit or gold.
 */
Occupant Room::get_occupant()
{
    return occupant;
}

/**
 * @brief Determine whether the room has a wumpus inside it.
 * 
 * @return true     The room has a wumpus.
 * @return false    The room does not have a wumpus.
 */
bool Room::has_wumpus()
{
    return (occupant == Occupant::wumpus);
}

/**
 * @brief Determine whether the room has a pit.
 * 
 * @return true     The room has a pit.
 * @return false    The room does not have a pit.
 */
bool Room::has_pit()
{
    return (occupant == Occupant::pit);
}

/**
 * @brief Determine whether the Room has gold inside it.
 * 
 * @return true     The room has gold.
 * @return false    The room does not have gold.
 */
bool Room::has_gold()
{
    return (occupant == Occupant::gold);
}
