/*
g++ --std=c++11 -o sample3 Room.cpp World.cpp playableWorld.cpp sensor.cpp actions.cpp playGround.cpp main.cpp -lncurses

*/
#include "ModelBasedAgent/IntelligentAgent/IA.h"
#include "Game/playGround.h"
#include <iostream>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <thread>
#include <chrono>
#include <iomanip>


using namespace std;
int main(){
cout << "sth";
}
//using namespace agent;

// int size;
// string player;
// PlayGround pg;
// World world;
// vector<sensor> sensors;
// string ui = " ";
// void printsep(int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         string app = "_______________";
//         ui = ui + app;
//     }

//     ui = ui + "\n";

//     for (int i = 0; i < size; i++)
//     {
//         ui = ui + "             |";
//     }

//     ui = ui + "\n";
// }
// void ClearScreen()
// {
//     int n;
//     for (n = 0; n < 1; n++)
//         ui = ui + "\n\n\n\n\n\n\n\n\n\n";
// }
// void printUI()
// {
//     pair<int, int> location = pg.playableworld.agent_location;
//     int b=9;
//     ostringstream values;
//     Room room = pg.playableworld.world.boxes.at(location.first - 1).at(location.second - 1);
//     values<<pg.playableworld.pl;
//     ui = ui + values.str() + "\n";

//     ui = ui + "your direction= " + pg.playableworld.get_agent_direction() + "\n";
//     values<<pg.arrow;
//     ui = ui + "arrow left= " + values.str() + "\n";
//     values<<pg.playableworld.agent_location.second;
//     ui = ui + "location= " + values.str() + ",";
//     values<<pg.playableworld.agent_location.first;
//     ui=ui+ values.str() + "\n";

//     vector<vector<Room> >::reverse_iterator iter;
//     int i = 0;
//     int r = 3;

//     for (iter = pg.playableworld.world.boxes.rbegin(); iter != pg.playableworld.world.boxes.rend(); ++iter)
//     {
//         printsep(size);
//         vector<Room>::iterator i;
//         vector<Room> line = *iter;
//         int j = 0;
//         for (i = line.begin(); i != line.end(); ++i)
//         {
//             string s = "";
//             Room r = *i;
//             bool here = (r.getLocation() == pg.playableworld.agent_location);

//             if (r.get_breeze()) s = s + "B"; 
//             else s = s + " "; 
//             if (r.get_stench()) s = s + "S"; 
//             else  s = s + " "; 
//             if (r.get_glitter())  s = s + "G"; 
//             else  s = s + " "; 
//             if (here) s = s + "YOU";
//             else s = s + "   ";
//             if (r.has_pit()) s = s + "P";
//             else s = s + " ";
//             if (r.has_wumpus()) s = s + "W";
//             else s = s + " ";

//             values<<r.getLocation().first;
//             string x = values.str();
//             values<<r.getLocation().second;
//             string y = values.str();
//             // cout << setw(3) <<y<< setw(3) << "," << setw(3) << x<< setw(3) << s << setw(3) << "|";
//             ui = ui + " " + y + "," + x + " " + s + "|";
//             j++;
//         }
//         i++;
//         //cout << endl;
//         ui = ui + "\n";
//         for (int i = 0; i < size; i++)
//         {
//             ui = ui + "______________";
//         }
//     }

//     char disp[1000];
//     strcpy(disp, ui.c_str());
//     printw(disp);
//     ClearScreen();
// }
//   actions decision_to_action(DataStructures::Decision decision){
//     pair<int,int> target_location;
//     actions action=actions();
//     target_location=make_pair(decision.location.first, decision.location.second);

//       if(decision.decision== DataStructures::movement_decision::move_to){
//         action.move=true;
//     }
//     else{
//         action.shoot=true;
//     }
//  if(target_location.first==pg.playableworld.agent_location.first){
//      if(target_location.second>pg.playableworld.agent_location.second){
//             pg.playableworld.turn_up();
//      }
//      else{
//          pg.playableworld.turn_down();
//      }
//  }
//  else if(target_location.first>pg.playableworld.agent_location.first){
//      pg.playableworld.turn_right();
//  }
//  else{
//      pg.playableworld.turn_left();
//  }
//       return action;
// }
// void reset_percepts(){

//   pg.p.scream=false;
//   pg.p.wumpus=false;
//   pg.p.glitter=false;
//   pg.p.stench=false;
//   pg.p.breeze=false;
//   pg.p.bump=false;
// }
// void agent_player()
// {   player="agent";

//     playableWorld playableworld = playableWorld(make_pair(1, 1), "top", world);
//     pg = PlayGround(player, playableworld);
//     components::Actuator actuator;
//     agent::IntelligentAgent intelligentAgent;

//     for (int i = 0; i < size; i++)
//     {
//         vector<bool> vis;
//         for (int j = 0; j < size; j++)
//         {

//             vis.push_back(true);
//         }
//         pg.visiblity.push_back(vis);
//     }
//     int i = 0;

//     vector<sensor> sensor=pg.get_initial_perception();
//     DataStructures::Decision decision=intelligentAgent.go(pg.playableworld.agent_location, pg.p);

//     while (!pg.is_game_over())
//     {   printUI();
//         chrono::milliseconds timespan(1000); 
//         this_thread::sleep_for(timespan);
//         intelligentAgent.go(pg.playableworld.agent_location,pg.p);
//         decision=intelligentAgent.decision;
//         actions action=decision_to_action(decision);
//         pg.action=action;
//         pg.execute();
        
//     }
//     if (pg.is_agent_dead)
//     {
//         cout << "GAME OVER YOU ARE DEAD" << endl;
//     }

//     else if (pg.is_gold_found)
//     {
//         cout << "YOU FOUND THE GOLD" << endl;
//     }
//     printUI();
// }

// int main()
// {
//     cout << "enter size of wumpus world" << endl;
//     cin >> size;
//     world = World(size);
    
//         agent_player();
    
    
// }