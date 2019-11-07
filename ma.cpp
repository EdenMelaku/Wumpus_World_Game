/*
g++ --std=c++11 -o sample3 Room.cpp World.cpp playableWorld.cpp sensor.cpp actions.cpp playGround.cpp main.cpp -lncurses

*/
#include "ModelBasedAgent/IntelligentAgent/IA.h"
#include "ModelBasedAgent/components/Actuator/Actuator.h"
#include "Game/playGround.h"
#include <iostream>

#include <string.h>
#include <thread>
#include <chrono>
#include <iomanip>


using namespace std;

// using namespace agent;

int size;
string player;
PlayGround pg;
World world;
vector<sensor> sensors;
string ui = " ";
void printsep(int size)
{
    for (int i = 0; i < size; i++)
    {
        string app = "_______________";
        ui = ui + app;
    }

    ui = ui + "\n";

    for (int i = 0; i < size; i++)
    {
        ui = ui + "             |";
    }

    ui = ui + "\n";
}
void ClearScreen()
{
    int n;
    for (n = 0; n < 1; n++)
        ui = ui + "\n\n\n\n";
}
void printUI()
{
    pair<int, int> location = pg.playableworld.agent_location;
    int b=9;
    Room room = pg.playableworld.world.boxes.at(location.first - 1).at(location.second - 1);
    cout<<ui<< pg.playableworld.pl<< "\n";
    cout<< "your direction= " << pg.playableworld.get_agent_direction() << "\n";
    cout<<"arrow left= " <<pg.arrow<<  "\n";
    cout<<"location= " <<pg.playableworld.agent_location.second<< ",";   
    cout<<pg.playableworld.agent_location.first<<"\n";

    vector<vector<Room> >::reverse_iterator iter;
    int i = 0;
    int r = 3;

    for (iter = pg.playableworld.world.boxes.rbegin(); iter != pg.playableworld.world.boxes.rend(); ++iter)
    {
        printsep(size);
        vector<Room>::iterator i;
        vector<Room> line = *iter;
        int j = 0;
        for (i = line.begin(); i != line.end(); ++i)
        {
            string s = "";
            Room r = *i;
            bool here = (r.getLocation() == pg.playableworld.agent_location);

            if (r.get_breeze()) s = s + "B"; 
            //else s = s + " "; 
            if (r.get_stench()) s = s + "S"; 
           // else  s = s + " "; 
            if (r.get_glitter())  s = s + "G"; 
           // else  s = s + " "; 
            if (here) s = s + "YOU";
           // else s = s + "   ";
            if (r.has_pit()) s = s + "P";
            //else s = s + " ";
            if (r.has_wumpus()) s = s + "W";
            //else s = s + " ";

            int x = r.getLocation().first;
            int y = r.getLocation().second;
            cout << setw(3) <<y<< setw(3) << "," << setw(3) << x<< setw(3) << s << setw(3) << "|";
            //cout<<" " << y << "," << x << " " << s << "|";
            j++;
        }
        i++;
        
        ui="";
        for (int i = 0; i < size; i++)
        {
            ui = ui + "______________";
        }
       // cout<<ui;
        cout << endl;
    }

 
    ClearScreen();
}
  actions decision_to_action(DataStructures::Decision decision){
    pair<int,int> target_location;
    actions action=actions();
    target_location=make_pair(decision.location.first+1, decision.location.second+1);

      if(decision.decision== DataStructures::movement_decision::move_to){
        action.move=true;
    }
    else{
        action.shoot=true;
    }
 if(target_location.first==pg.playableworld.agent_location.first){
     if(target_location.second>pg.playableworld.agent_location.second){
            pg.playableworld.turn_up();
            action.turnup=true;
     }
     else{
         pg.playableworld.turn_down();
         action.turndown=true;
     }
 }
 else if(target_location.first>pg.playableworld.agent_location.first){
     pg.playableworld.turn_right();
     action.turnright=true;
 }
 else{
     pg.playableworld.turn_left();
     action.turnleft=true;
 }
      return action;
}
void reset_percepts(){

  pg.p.scream=false;
  pg.p.wumpus=false;
  pg.p.glitter=false;
  pg.p.stench=false;
  pg.p.breeze=false;
  pg.p.bump=false;
}
void agent_player()
{   player="agent";

    playableWorld playableworld = playableWorld(make_pair(1, 1), "top", world);
    pg = PlayGround(player, playableworld);
    components::Actuator actuator;
    agent::IntelligentAgent intelligentAgent;

    for (int i = 0; i < size; i++)
    {
        vector<bool> vis;
        for (int j = 0; j < size; j++)
        {

            vis.push_back(true);
        }
        pg.visiblity.push_back(vis);
    }
    int i = 0;

    vector<sensor> sensor=pg.get_initial_perception();
    DataStructures::Decision decision = intelligentAgent.go(pg.playableworld.agent_location, pg.p);
    cout<<"before"<<endl;
    printUI();
        cout<<"delay for second"<<endl;

    while (!pg.is_game_over())
    {   printUI();
        chrono::milliseconds timespan(1000);
        this_thread::sleep_for(timespan);
        intelligentAgent.go(pg.playableworld.agent_location,pg.p);
        decision=intelligentAgent.decision;
        actions action=decision_to_action(decision);
        pg.action=action;
        pg.execute();
        if(action.move) cout<<"move"<<" ->";
        if(action.shoot) cout<<"shoot"<<"->";
        if(action.turnleft) cout<<"left";
        if(action.turnright) cout<<"right";
        if(action.turnup) cout<<"up";
        if(action.turndown) cout<<"down";
        cout<<"------- location="<<decision.location.first<<","<<decision.location.second;
        cout<<endl;
        
    }
    if (pg.is_agent_dead)
    {
        cout << "GAME OVER YOU ARE DEAD" << endl;
    }

    else if (pg.is_gold_found)
    {
        cout << "YOU FOUND THE GOLD" << endl;
    }
    printUI();
}

int main()
{
    cout << "enter size of wumpus world" << endl;
    cin >> size;
    world = World(size);

        agent_player();
    
    
}