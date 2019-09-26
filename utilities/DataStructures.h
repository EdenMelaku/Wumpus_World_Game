#ifndef DS_H
#define DS_H


namespace DataStructures{

    struct Knowledge
    {
        bool stench = false;
        bool breeze = false;
        bool glitter = false;
        bool bump = false;
        bool scream = false;
        bool possible_wumpus = false;
        bool wumpus = false;
        bool possible_pit = false;
        bool pit = false;
        bool gold = false;
        bool ok = false;
        bool visited = false;
    };

    struct Percepts
    {
        bool stench = false;
        bool breeze = false;
        bool glitter = false;
        bool bump = false;
        bool scream = false;
        bool wumpus = false;
    };
    
    enum class Decision{
        move_left,
        move_right,
        move_up
    };
    
}
#endif;
