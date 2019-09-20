#ifndef KNOWLEDGEBASE_H
#define KNOWLEDGEBASE_H

#include <map>
#include <set>


using namespace std;

struct Knowledge
{
    bool stench = false;
    bool breeze = false;
    bool glitter = false;
    bool bump = false;
    bool scream = false;
    bool wumpus = false;
    bool pit = false;
    bool gold = false;
    bool ok = false;
    bool visited = false;
};
class KnowledgeBase
{
    /*
    *
    * This class holds the data structure of the agent's knowledgebase and methods for manipulating it.
    * The data structure is held in the member knowledgebase.
    * Knowledgebase is a mapping from rooms to the information gathered about that room. 
    * A room is represented by a pair<int, int> as row, col representation.
    * The information collected about each room is held in the value of the map using the Knowledge struct.
    * The knowledge struct (written above) contains all the possible perceptions that can be attributed to a room by the agent after perceptions within the wumpus world.
    * 
    */
    private:
        map<pair<int, int>, Knowledge> knowledgebase; 
    public:
        map<pair<int, int>, Knowledge> get_knowledgebase();
        void add_into_knowledgebase(pair<int, int> room, Knowledge knowledge);
        void change_percepts(pair<int, int> room, Knowledge knowledge);
        Knowledge get_percepts(pair<int, int> room);
};  
#endif;
