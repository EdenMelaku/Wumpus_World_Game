#ifndef ENV_H
#define ENV_H

#include "World.h"


class Environment
{
    public:
        Environment();
    private:
        pair<int, int> agent_location;
        pair<int, int> wumpus_location;
        vector<pair<int, int>> pit_locations;
        pair<int, int> gold_location;
        bool is_wumpus_dead;
        bool is_agent_dead;
};

#endif
