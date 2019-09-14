#ifndef AGENT_H
#define AGENT_H

#include <tuple>


using namespace std;

enum class Direction
{
    left = 1,
    right,
    top,
    down
};
class Agent
{
    private:
        Direction direction;
        pair<int, int> location;
        bool alive;
        bool arrow;
        void set_location();
        void set_direction(Direction direction);
        void perceive_room();
    public:
        pair<int,int> get_location();
        Direction get_direction();
        // sensors
        bool is_alive();
        // actuators
        void move_forward();
        void move_backward();
        void turn_left();
        void turn_right();
        void shoot();

};
#endif;
