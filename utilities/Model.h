#ifndef MODEL_H
#define MODEL_H

#include <tuple>
#include <set>


namespace Model{

    enum class Rule{
        Wumpus,
        Pit
    };
    std::set<std::pair<int, int>, bool> conclusion;


}
#endif
