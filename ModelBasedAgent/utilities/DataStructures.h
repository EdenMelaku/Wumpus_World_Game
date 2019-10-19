#ifndef DS_H
#define DS_H

#include <tuple>


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

    enum constraint
    {
        stench,
        breeze,
        glitter,
        bump,
        scream,
        wumpus,
        pit
    };

    enum movement_decision{
        move_to,
        shoot_at
    };
    struct Decision{
      movement_decision decision;
      std::pair<int, int> location;
    };

}
#endif
