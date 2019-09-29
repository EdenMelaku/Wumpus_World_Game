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
        cout << "__________";
        
    }
    
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << "|";
    }
    cout << endl;
}
void printUI()
{
    cout << "your direction= " << pg.playableworld.get_agent_direction() << endl;
    cout << "arrow left= " << pg.arrow << endl;
    cout << "location= " << pg.playableworld.get_agent_location().first<<","<< pg.playableworld.get_agent_location().first << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        printsep(size);
        for (int j = 0; j < size; j++)
        {
            string s = "";
             bool here=(pg.playableworld.get_agent_location().first==i)&&(pg.playableworld.get_agent_location().second==j);
            if (pg.visiblity.at(i).at(j))
            {

                if (pg.playableworld.world.boxes.at(i).at(j).get_breeze())
                {
                    s = s + "B";
                }

                if (pg.playableworld.world.boxes.at(i).at(j).get_stench())
                {
                    s = s + "S";
                }

                if (pg.playableworld.world.boxes.at(i).at(j).get_glitter())
                {
                    s = s + "G";
                }

                if ( here)
                {
                    s = s + "YOU";
                }
                if (pg.playableworld.world.boxes.at(i).at(j).has_pit())
                {
                    s = s + "P";
                }

                if (pg.playableworld.world.boxes.at(i).at(j).has_wumpus())
                {
                    s = s + "W";
                }
            }
            cout << setw(2) << i << setw(2) << "," << setw(2) << j << setw(2) << s << setw(2) << "|";
        }
        cout << endl;
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
    playableWorld playableworld = playableWorld(make_pair(0, 0), "top", world);
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
        printUI();
 
        initscr();
       keypad(stdscr, TRUE);  
        ClearScreen();

        // printUI();
        vector<bool> arguments = {false, false, false, false};
        vector<int> numOf_turns = {0, 0};
        actions ac = actions(arguments.at(0), arguments.at(1), arguments.at(2), arguments.at(3), numOf_turns);

        int ch = getch();
        switch (ch)
        {

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
        case 10:
            ac.move = true;
            pg.action = ac;
            cout<<"to infer"<<endl;
            pg.infer();

            break;

        case 's':
            ac.shoot = true;
            pg.action = ac;
            pg.infer();
            break;
        }
    }

    return 1;
}