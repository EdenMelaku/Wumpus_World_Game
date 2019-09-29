#include "World.h"


using namespace std;

/**
 * @brief Construct a new World:: World object
 * 
 */
World::World()
{
    ;
}

/**
 * @brief Construct a new World:: World object
 * 
 * @param sizee The size of the World to be constructed. The result of which is a row by column grid with row = column = sizee. 
 */
World::World(int sizee)
{
    size = sizee;
    init_empty_world();
    generate_position();
    pos = 0;

    // check_percolaton();
}

/**
 * @brief Initialize an empty world grid with no information about the rooms that make it up.
 * 
 */
void World::init_empty_world()
{
    int count = size;
    for (int i = 0; i < count; i++)
    {
        vector<Room> vecs;
        for (int j = 0; j < count; j++)
        {
            Room common = Room(i, j);
            vecs.push_back(common);
        }
        boxes.push_back(vecs);
    }
}

/**
 * @brief Access the location of the wumpus within the world.
 * 
 * @return pair<int, int>   The row and column information of the wumpus.
 */
pair<int, int> World::get_wumpus_location()
{
    return wumpus_location;
}

/**
 * @brief Store the location of the wumpus in an data member for faster access.
 * 
 * @param wumpus_location   pair<int, int> value of the location of the wumpus.
 */
void World::set_wumpus_location(pair<int, int> wumpus_location)
{
    wumpus_location = wumpus_location;
}

/**
 * @brief Access the location of the pits that are present in the world.
 * 
 * @return vector<pair<int, int>>  A vector that holds the row and column attributes of the rooms with pits.
 */
vector<pair<int, int>> World::get_pit_locations()
{
    return pit_locations;
}

/**
 * @brief Store the locaton of the pits in a vector.
 * 
 * @param pit_locations The vector that hold the row and column values of the rooms that have pits.
 */
void World::set_pit_locations(vector<pair<int, int>> pit_locations)
{
    pit_locations = pit_locations;
}

/**
 * @brief The location of the gold in the world.
 * 
 * @return pair<int, int>  The row and column value of the location of the room containing gold.
 */
pair<int, int> World::get_gold_location()
{
    return gold_location;
}

/**
 * @brief Set the location of the rooms with gold within the world.
 * 
 * @param gold_location The row and column value of the room containing the gold.
 */
void World::set_gold_location(pair<int, int> gold_location)
{
    gold_location = gold_location;
}

/**
 * @brief Generate random positions for the rooms within the world that will have the pits, wumpus and gold.
 * 
 */
void World::generate_position()
{
    srand((int)time(0));
    int iter = 3;
    vector<pair<int, int>> store;      // a set of position for storing wumpus, pit , gold
    pair<int, int> agentPosition;      // to hold the agent position
    pair<int, int> restrictedPosition; //to hold the restricted position adjcent to the agent
    agentPosition = make_pair(0, 0);
    //store.push_back(agentPosition);
    restrictedPosition = make_pair(1, 0);
    //store.push_back(restrictedPosition);
    pair<int, int> restrictedPosition2 = make_pair(0, 1);
    // store.push_back(restrictedPosition2);
    int j = 0;
    while (store.size() < 5)
    {
        int x, y;

        for (int i = 0; i < iter; ++i)
        {

            x = rand() % size;
            rand() % 15;
            y = rand() % size;
        }
        pair<int, int> newpair = make_pair(x, y);
        if (newpair != restrictedPosition && newpair != agentPosition && newpair != restrictedPosition2)
        {
            store.push_back(newpair);
            sort(store.begin(), store.end());
            store.erase(unique(store.begin(), store.end()), store.end());
        }
    }
    

    vector<pair<int, int>>::iterator it = store.end();
    --it;
    pair<int, int> pit3 = *it; //random position for pit
    --it;
    pair<int, int> wumpus = *it; //random position for wumpus
    --it;
    pair<int, int> pit2 = *it; //random position for pit
    --it;

    pair<int, int> gold = *it; //random position for gold
    --it;
    pair<int, int> pit1 = *it; //random position for pit

    //now lets map this positions into our rooms in the boxes

    //1- ASSIGNING WUMPUS
    create_wumpus(wumpus);

    //2- ASSIGNING pit
    create_pit(pit1);

    create_pit(pit2);

    create_pit(pit3);

    //3- ASSIGNING gold
    create_gold(gold);
}

/**
 * @brief Set a wumpus in a room. Set stench attributes in adjacent rooms.
 * 
 * @param wumpus The row and column value of the location of the wumpus.
 */
void World::create_wumpus(pair<int, int> wumpus)
{
    int pos[] = {wumpus.first, wumpus.second};
    int point = convert_to_1d(pos);
    //create the wumpus
    Occupant wumpu = Occupant::wumpus;

    boxes.at(pos[0]).at(pos[1]).set_occupant(wumpu);
    //cout<<pos[0]<<", "<<pos[1]<<" wumpus"<<endl;

    //initialize  stench on adjacent nodes

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for (int i = 0; i < adjacents.size(); i++)
    {
        vector<int> add = convert_to_2d(adjacents.at(i));
        int pos[] = {add.at(0), add.at(1)};
        boxes.at(pos[0]).at(pos[1]).set_stench(true);
        //cout<<pos[0]<<", "<<pos[1]<<" stench"<<endl;
    }
}

/**
 * @brief Sets a pit in a room. Sets breeze attributes in adjacent rooms.
 * 
 * @param pit The row and column value of the location of the pit.
 */
void World::create_pit(pair<int, int> pit)
{

    int pos[] = {pit.first, pit.second};
    int point = convert_to_1d(pos);
    //create the pit

    Occupant pitt = Occupant::pit;

    boxes.at(pos[0]).at(pos[1]).set_occupant(pitt);
    // cout<<pos[0]<<", "<<pos[1]<<" pit"<<endl;

    //initialize breez on adjacent nodes

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for (int i = 0; i < adjacents.size(); i++)
    {

        vector<int> add = convert_to_2d(adjacents.at(i));
        int pos[] = {add.at(0), add.at(1)};

        boxes.at(pos[0]).at(pos[1]).set_breeze(true);
        //  cout<<pos[0]<<", "<<pos[1]<<" breez"<<endl;
    }
}

/**
 * @brief Set a gold in a room.
 * 
 * @param gold 
 */
void World::create_gold(pair<int, int> gold)
{
    int pos[] = {gold.first, gold.second};
    int point = convert_to_1d(pos);
    //initialize glitter
    boxes.at(pos[0]).at(pos[1]).set_glitter(true);
    //cout << pos[0] << ", " << pos[1] << " glitter" << endl;
}
vector<int> World::get_adjacent_rooms(int positon)
{
    vector<int> room = convert_to_2d(positon);
    int i = room.at(0);
    int j = room.at(1);
    vector<int> adjacents;
    vector<pair<int, int>> adj;

    adj.push_back(make_pair(i + 1, j));
    adj.push_back(make_pair(i - 1, j));
    adj.push_back(make_pair(i, j + 1));
    adj.push_back(make_pair(i, j - 1));
    for (vector<pair<int, int>>::iterator iterr = adj.begin(); iterr != adj.end(); ++iterr)
    {
        int adjj[2];
        pair<int, int> item = *iterr;
        adjj[0] = item.first;
        adjj[1] = item.second;
        if (is_valid_position(adjj[0], adjj[1]))
        {
            adjacents.push_back(convert_to_1d(adjj));
        }
    }
    return adjacents;
}

/**
 * @brief Validates if a room accessed with certain row and column attributes is a valid entry. Returns bump if it isn't.
 * 
 * @param i Row attripute of a room.
 * @param j Column attribute of a room.
 * @return true The room exists in the constructed world.
 * @return false The room does not exist in the constructed world.
 */
bool World::is_valid_position(int i, int j)
{
    return (i >= 0 && j >= 0 && i < size && j < size);
}

/**
 * @brief Checks if there is a way between the agent and the gold as the World is constructed.
 * 
 * @param agent_pos         The initial position of the agent.
 * @param gold_position     The position of the room containing the gold in the world.
 * @return true             There is a traversal between the agent's initial position and the gold.
 * @return false            There is no valid traversal between the agent's initial position and the gold.
 */
bool check_percolaton(int agent_pos, int gold_position);

/**
 * @brief Converts 1D location of the rooms in the grid to 2D representation in terms of rows and columns.
 * 
 * @param position The index of the room in the world grid.
 * @return vector<int> The converted location of the room in row and column format.
 */
vector<int> World::convert_to_2d(int position)
{
    int i = position % size;
    int j = position / size;
    vector<int> arr = {i, j};
    return arr;
}

/**
 * @brief Converts the 2D representation of the room into it's 1D location (index) in the World grid.
 * 
 * @param pos       The row and column attributes of the room.
 * @return int      The index of the room within the world grid.
 */
int World::convert_to_1d(int pos[])
{
    int position = pos[0] + (pos[1] * size);
    return position;
}

/**
 * @brief Converts the 2D representation of the room into it's 1D location (index) in the World grid.
 * 
 * @param pos       The row and column attributes of the room.
 * @return int      The index of the room within the world grid.
 */
int World::convert_vector_to_1d(vector<int> pos)
{
    int position = pos[0] + (pos[1] * size);
    return position;
}

/**
 * @brief Removes the wumpus from the room within the world.
 * 
 */
void World::remove_wumpus(){
    pair<int,int> location=get_wumpus_location();
    boxes.at(location.first).at(location.second).set_occupant(Occupant::empty);
    int pos[]={location.first, location.second};
    vector<int> adjacents=get_adjacent_rooms(convert_to_1d(pos));
    for (int i = 0; i < adjacents.size(); i++)
    {
        vector<int> add = convert_to_2d(adjacents.at(i));
        int pos[] = {add.at(0), add.at(1)};
        boxes.at(pos[0]).at(pos[1]).set_stench(false);
        //cout<<pos[0]<<", "<<pos[1]<<" stench"<<endl;
    }

}
