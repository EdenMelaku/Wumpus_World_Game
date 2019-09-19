#ifndef ROOM_H
#define ROOM_H

#include <tuple>


using namespace std;

enum class Occupant
{
    empty = 0,
    wumpus,
    pit,
    gold
};
class Room
{
    public:
        Room(int row, int column);
        pair<int, int> getLocation();
        bool get_breeze();
        void set_breeze(bool value);
        bool get_stench();
        void set_stench(bool value);
        bool get_glitter();
        void set_glitter(bool value);
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
