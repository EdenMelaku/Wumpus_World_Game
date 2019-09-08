#ifndef ROOM_H
#define ROOM_H

#include <tuple>


using namespace std;

enum class Occupant
{
    wumpus = 1,
    pit,
    gold
};
class Room
{
public:
        Room(int row, int column);
        pair<int, int> getLocation();
        void make_breeze();
        bool has_breeze();
        void make_stench();
        bool has_stench();
        void make_glitter();
        bool has_glitter();
        void set_occupant(Occupant occupant);
        bool has_wumpus();
        bool has_pit();
        bool has_gold();
    private:
        pair<int, int> location;
        Occupant occupant;
        Occupant get_occupant();
        bool breeze;
        bool stench;
        bool glitter;
};

#endif;