/*
this is a wumpus world Environment implementation code .


*/

#include <cstdlib>
#include <string>
#include <vector>
#include<iostream>
#include <bits/stdc++.h>
#include <set>
#include <ctime>
#include "Room.h"
#include "World.h"
using namespace std;
World::World(){
    ;
}
World::World(int size)
{   World::size=size;
    init_empty_world();
    generate_position();
    World::pos = 0;
 
    // check_percolaton();
}
//initializes an empty box with no position information
void World::init_empty_world()
{
    int count = size;
    for (int i = 0; i < count; i++){
        vector<Room> vecs;
        for (int j = 0; j < count; j++){
            Room common = Room(i, j);
            vecs.push_back(common);
            
        }
        boxes.push_back(vecs);
    }
}
// getter and setter for wumpus_location attribute
pair<int, int> World::get_wumpus_location()
{
    return wumpus_location;
}
void World::set_wumpus_location(pair<int, int> wumpus_location)
{
    World::wumpus_location = wumpus_location;
}

// getter and setter for pit_locations attribute
vector<pair<int, int>> World::get_pit_locations()
{
    return World::pit_locations;
}
void World::set_pit_locations(vector<pair<int, int>> pit_locations)
{
    World::pit_locations = pit_locations;
}

// getter and setter for gold_location attribute
pair<int, int> World::get_gold_location()
{
    return World::gold_location;
}
void World::set_gold_location(pair<int, int> gold_location)
{
    World::gold_location = gold_location;
}

//generates random positions along with sensor information
void World::generate_position()
{
    srand((int)time(0));
    int iter = 3;
    vector<pair<int,int> > store;         // a set of position for storing wumpus, pit , gold
    pair<int,int> agentPosition;      // to hold the agent position
    pair<int,int> restrictedPosition; //to hold the restricted position adjcent to the agent
    agentPosition=make_pair(0,0);
    //store.push_back(agentPosition);
    restrictedPosition=make_pair(1,0);
    //store.push_back(restrictedPosition);
    pair<int,int>restrictedPosition2=make_pair(0,1);
   // store.push_back(restrictedPosition2);
    int j = 0;
    while (store.size() < 5) { 
                   int x,y;

        for (int i = 0; i < iter; ++i) { 

         x=rand() % size;
        rand() % 15; 
         y=rand() % size;
        }
        pair<int,int> newpair=make_pair(x,y);
        if(newpair!=restrictedPosition && newpair!=agentPosition && newpair!=restrictedPosition2){store.push_back(newpair);
        sort( store.begin(), store.end() );
        store.erase( unique( store.begin(), store.end() ), store.end() );
}
    
    }
          for(int i=0;i<store.size();i++){
              cout<<store.at(i).first<<","<<store.at(i).second<<endl;
          }  

    
    vector<pair<int,int> >::iterator it = store.end();
    --it;
    pair<int,int> pit3 = *it; //random position for pit
    --it;
    pair<int,int> wumpus = *it; //random position for wumpus
    --it; 
     pair<int,int> pit2 = *it; //random position for pit
    --it;

    pair<int,int> gold = *it; //random position for gold
    --it;
    pair<int,int> pit1 = *it; //random position for pit
    
    //now lets map this positions into our rooms in the boxes

    //1- ASSIGNING WUMPUS
    create_wumpus(wumpus);
        cout<<"here1"<<endl;

    //2- ASSIGNING pit
    create_pit(pit1);
        cout<<"here2"<<endl;

    create_pit(pit2);
        cout<<"here3"<<endl;

    create_pit(pit3);
        cout<<"here4"<<endl;

    //3- ASSIGNING gold
    create_gold(gold);
            cout<<"here5"<<endl;

}
//creates a wumpus room at position and initialize a stench in adjacent rooms
void World::create_wumpus(pair<int,int> wumpus)
{  
    int pos[] = {wumpus.first, wumpus.second};
    int point = convert_to_1d(pos);
    //create the wumpus
    Occupant wumpu = Occupant::wumpus;
    cout<<"wumpus"<<point<<endl;
    
    boxes.at(pos[0]).at(pos[1]).set_occupant(wumpu);
             cout<<pos[0]<<", "<<pos[1]<<" wumpus"<<endl;

   
    //initialize  stench on adjacent nodes

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for (int i = 0; i < adjacents.size(); i++){
        vector<int> add= convert_to_2d (adjacents.at(i));
        int pos[] = {add.at(0), add.at(1)};
         boxes.at(pos[0]).at(pos[1]).set_stench(true);
         cout<<pos[0]<<", "<<pos[1]<<" stench"<<endl;
   }
}
//creates a pit room at position and initialize a breez in adjacent rooms
void World::create_pit(pair<int,int> pit)
{

    int pos[] = {pit.first, pit.second};
    int point = convert_to_1d(pos);
    //create the pit

    Occupant pitt = Occupant::pit;
   
      boxes.at(pos[0]).at(pos[1]).set_occupant(pitt);
         cout<<pos[0]<<", "<<pos[1]<<" pit"<<endl;

    //initialize breez on adjacent nodes
             cout<<"he"<<endl;

    //gets adjacent nodes
    vector<int> adjacents = get_adjacent_rooms(point);
    for (int i = 0; i < adjacents.size(); i++)
    {            

        vector<int> add= convert_to_2d (adjacents.at(i));
        int pos[] = {add.at(0), add.at(1)};
            

          boxes.at(pos[0]).at(pos[1]).set_breeze(true);
                               cout<<pos[0]<<", "<<pos[1]<<" breez"<<endl;


    }
}
//creates a gold room at position and initialize a glitter in the rooms
void World::create_gold(pair<int,int> gold)
{
    int pos[] = {gold.first, gold.second};
    int point = convert_to_1d(pos);
    //initialize glitter
      boxes.at(pos[0]).at(pos[1]).set_glitter(true);
               cout<<pos[0]<<", "<<pos[1]<<" glitter"<<endl;

}
vector<int> World::get_adjacent_rooms(int positon)
{
    vector<int> room = convert_to_2d(positon);
    int i = room.at(0);
    int j = room.at(1);
    vector<int> adjacents;
    vector<pair<int,int>  >adj;
    
    adj.push_back(make_pair(i + 1,j));
    adj.push_back(make_pair(i - 1, j));
    adj.push_back(make_pair(i, j + 1));
    adj.push_back(make_pair(i, j - 1));
    for (vector<pair<int,int> >::iterator iterr = adj.begin(); iterr != adj.end(); ++iterr)
    {
        int adjj[2];
        pair<int, int> item=*iterr;
        adjj[0] = item.first;
        adjj[1] = item.second;
        if (is_valid_position(adjj[0], adjj[1]) ) {
              adjacents.push_back(convert_to_1d(adjj));
        }
    }
    return adjacents;
}
//validates is a position is valid or not if not valid then bump
bool World::is_valid_position(int i, int j)
{
    return (i >= 0 && j >= 0 && i < size && j <  size);
   
}
//checks if there is a way between the agent position(0,0) and the gold at
bool check_percolaton(int agent_pos, int gold_position);
//converts 1d position to 2d
vector<int> World::convert_to_2d(int position)
{
    int i = position % size;
    int j = position / size;
    vector<int> arr = {i, j};
    return arr;
}
//converts 2d position to 1d
int World::convert_to_1d(int pos[])
{
    int position = pos[0] + (pos[1] * size);
    return position;
}

//converts 2d position to 1d
int World::convert_vector_to_1d(vector<int> pos)
{
    int position = pos[0] + (pos[1] * size);
    return position;
}
