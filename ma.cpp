/*
g++ --std=c++11 -o sample3 Room.cpp World.cpp playableWorld.cpp sensor.cpp actions.cpp playGround.cpp main.cpp -lncurses

*/
#include "playGround.h"
#include "agent/IntelligentAgent/IA.h"
#include <iostream>
#include <curses.h>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;
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
        ui = ui + "\n\n\n\n\n\n\n\n\n\n";
}
void printUI()
{
    pair<int, int> location = pg.playableworld.agent_location;
    Room room = pg.playableworld.world.boxes.at(location.first - 1).at(location.second - 1);
    ui = ui + to_string(pg.playableworld.pl) + "\n";
    ui = ui + to_string(room.get_breeze()) + " " + to_string(room.get_stench()) + " " + to_string(room.has_pit()) + " " + to_string(room.has_wumpus());
    ui = ui + "your direction= " + pg.playableworld.get_agent_direction() + "\n";
    ui = ui + "arrow left= " + to_string(pg.arrow) + "\n";
    ui = ui + "location= " + to_string(pg.playableworld.agent_location.second) + "," + to_string(pg.playableworld.agent_location.first) + "\n";

    vector<vector<Room>>::reverse_iterator iter;
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

            if (r.get_breeze())
            {
                s = s + "B";
            }
            else
            {
                s = s + " ";
            }

            if (r.get_stench())
            {
                s = s + "S";
            }
            else
            {
                s = s + " ";
            }

            if (r.get_glitter())
            {
                s = s + "G";
            }
            else
            {
                s = s + " ";
            }
            if (here)
            {
                s = s + "YOU";
            }
            else
            {
                s = s + "   ";
            }
            if (r.has_pit())
            {
                s = s + "P";
            }
            else
            {
                s = s + " ";
            }

            if (r.has_wumpus())
            {
                s = s + "W";
            }
            else
            {
                s = s + " ";
            }

            string x = to_string(r.getLocation().first);
            string y = to_string(r.getLocation().second);
            // cout << setw(3) <<y<< setw(3) << "," << setw(3) << x<< setw(3) << s << setw(3) << "|";
            ui = ui + " " + y + "," + x + " " + s + "|";
            j++;
        }
        i++;
        //cout << endl;
        ui = ui + "\n";
        for (int i = 0; i < size; i++)
        {
            ui = ui + "______________";
        }
    }

    char disp[1000];
    strcpy(disp, ui.c_str());
    printw(disp);
    ClearScreen();
}
  actions decision_to_action(Decision decision){
    pair<int,int> target_location;
    actions action=actions;
    if(decision.move_to){
        target_location={decision.move_to.first,decision.move_to.second};
        action.move=true;

    }
    else{
        action.shoot=true;
    }
 if(target_location.first==pg.playableWorld.agent_location.first){
     if(target_location.second>pg.playableWorld.agent_location.second){
            pg.playableworld.turn_up();
     }
     else{
         pg.playableworld.turn_down();
     }
 }
 else if(target_location.first>pg.playableWorld.agent_location.first){
     pg.playableworld.turn_right();
 }
 else{
     pg.playableworld.turn_left();
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
    agent::IntelligentAgent intelligentAgent= agent::IntelligentAgent::IntelligentAgent();

    Sensor sensor=pg.get_initial_perception();
    Decision decision=intelligentAgent.go(pg.p);

    while (!pg.is_game_over())
    {   printUI();
        chrono::milliseconds timespan(1000); 
        this_thread::sleep_for(timespan);
        decision=intelligentAgent.decision;

        actions action=decision_to_action(decision);
        pg.action=action;
        pg.execute();
        
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
    cout << "enter a for agent or any character for manual playing" << endl;
    cin >> player;
    if (player == "a")
    {
        agent_player();
    }
    playableWorld playableworld = playableWorld(make_pair(1, 1), "top", world);
    //cout<<playableworld.world.boxes.at(0).at(0).get_breeze()<<endl;
    pg = PlayGround(player, playableworld);
    //cout<<pg.playableworld.world.boxes.at(0).at(0).get_breeze()<<endl;

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
    /*
    while (i<10){
    std::chrono::milliseconds timespan(1000); // or whatever

     std::this_thread::sleep_for(timespan);
    printUI();
    cout<<endl<<endl<<i++<<endl;
    }
    */

    printUI();
    initscr();
    keypad(stdscr, TRUE);
    // printUI();
    while (!pg.is_game_over())
    {

        // printUI();

        actions ac = actions();

        int ch = getch();
        switch (ch)
        {
        case 127:
        case '\b':
        case KEY_BACKSPACE:
            cout << "game interupted by player" << endl;
            return 1;
            break;

        case KEY_LEFT:

            pg.changeDir("left");
            pg.playableworld.turn_left();
            // printw("/n",pg.playableworld.get_agent_direction());
            ac.turnleft = true;
            //numOf_turns.at(0)++;

            break;

        case KEY_RIGHT:

            pg.changeDir("right");
            pg.playableworld.turn_right();
            //printw("/n",pg.playableworld.get_agent_direction());
            ac.turnright = true;
            break;

        case KEY_UP:

            pg.changeDir("up");
            pg.playableworld.turn_up();
            //printw("/n",pg.playableworld.get_agent_direction());
            ac.turnleft = true;

            break;

        case KEY_DOWN:

            pg.changeDir("down");
            pg.playableworld.turn_down();
            //printw("/n",pg.playableworld.get_agent_direction());
            ac.turnright = true;
            break;
        case 10:
            ac.move = true;
            pg.action = ac;
            // cout<<"to infer"<<endl;
            pg.execute();

            printUI();
            break;
        case KEY_F(1):
            cout << "touched" << endl;
            ac.shoot = true;
            pg.action = ac;
            pg.execute();
            printUI();
            break;
        }
    }

    endwin();
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