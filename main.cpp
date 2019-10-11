/*
g++ --std=c++11 -o sample3 Room.cpp World.cpp playableWorld.cpp sensor.cpp actions.cpp playGround.cpp main.cpp -lncurses

*/
#include "playGround.h"
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
void printsep(int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "_______________";
        
    }
    
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << setw(15) << "|";
    }
    cout << endl;
}








void printUI()
{       pair<int, int> location=pg.playableworld.agent_location;
        Room room = pg.playableworld.world.boxes.at(location.first-1).at(location.second-1);
    cout<<pg.playableworld.pl<<endl;
    cout<<room.get_breeze()<<" "<<room.get_stench()<<" "<<room.has_pit()<<" "<<room.has_wumpus()<<endl;
    cout << "your direction= " << pg.playableworld.get_agent_direction() << endl;
    cout << "arrow left= " << pg.arrow << endl;
    cout << "location= " << pg.playableworld.agent_location.second<<","<< pg.playableworld.agent_location.first << endl;
    
    vector<vector<Room> >::reverse_iterator iter;
    int i=0;
    int r=3;

    for (iter=pg.playableworld.world.boxes.rbegin(); iter!=pg.playableworld.world.boxes.rend();++iter)
    {   
        printsep(size);
        vector<Room>::iterator i;
        vector<Room> line=*iter;
        int j=0;
        for (i=line.begin(); i !=line.end(); ++i)
        {  
            string s = "";
            Room r=*i;
             bool here = (r.getLocation()== pg.playableworld.agent_location);
        
             
                if (r.get_breeze())
                {
                    s = s + "B";
                }

                if (r.get_stench())
                {
                    s = s + "S";
                }

                if (r.get_glitter())
                {
                    s = s + "G";
                }

                if ( here)
                {
                    s = s + "YOU";
                }
                if (r.has_pit())
                {
                    s = s + "P";
                }

                if (r.has_wumpus())
                {
                    s = s + "W";
                }
            
            int x= r.getLocation().first;
            int y=r.getLocation().second;
            cout << setw(3) <<y<< setw(3) << "," << setw(3) << x<< setw(3) << s << setw(3) << "|";
            j++;
        }
        i++;
        cout << endl;
         for (int i = 0; i < size; i++)
    {
        cout << "______________";
        
    }
        
    }
    
}





void ClearScreen()
{
    int n;
    for (n = 0; n < 1; n++)
        cout << "\n\n\n\n\n\n\n\n\n\n";
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
        cout << "not supoorted yet" << endl;
        return 1;
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
    {   endwin();
        ClearScreen();
        printUI();
        initscr();
       keypad(stdscr, TRUE);  
        

        // printUI();
        vector<bool> arguments = {false, false, false, false};
        vector<int> numOf_turns = {0, 0};
        actions ac = actions(arguments.at(0), arguments.at(1), arguments.at(2), arguments.at(3), numOf_turns);

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
            printw("/n",pg.playableworld.get_agent_direction());
            ac.turnleft = true;
            numOf_turns.at(0)++;

            break;

        case KEY_RIGHT:

            pg.changeDir("right");
            pg.playableworld.turn_right();
            printw("/n",pg.playableworld.get_agent_direction());
            ac.turnright = true;
            numOf_turns.at(1)++;
            break;

         case KEY_UP:

            pg.changeDir("up");
            pg.playableworld.turn_up();
            printw("/n",pg.playableworld.get_agent_direction());
            ac.turnleft = true;
            numOf_turns.at(0)++;

            break;

        case KEY_DOWN:

            pg.changeDir("down");
            pg.playableworld.turn_down();
            printw("/n",pg.playableworld.get_agent_direction());
            ac.turnright = true;
            numOf_turns.at(1)++;
            break;
        case 10:
            ac.move = true;
            pg.action = ac;
            cout<<"to infer"<<endl;
            pg.execute();

            break;
        case KEY_F(1):
            cout<<"touched"<<endl;
            ac.shoot = true;
            pg.action = ac;
            pg.execute();

            break;
      
    }}

        endwin();
        if(pg.is_agent_dead) { cout<<"GAME OVER YOU ARE DEAD"<<endl;}
       
        else if(pg.is_gold_found) {cout<<"YOU FOUND THE GOLD"<<endl;
        }
         printUI();
        
}