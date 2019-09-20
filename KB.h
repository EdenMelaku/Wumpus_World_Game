#ifndef KNOWLEDGEBASE_H
#define KNOWLEDGEBASE_H

#include <map>
#include <set>


using namespace std;

enum class Percepts
{
    stench = false,
    breeze = false,
    glitter = false,
    bump = false,
    scream = false,
    wumpus = false,
    pit = false,
    gold = false
};
class KnowledgeBase
{
    private:
        map<int, set<Percepts>> knowledgebase;
    public:
        map<int, set<Percepts>> get_knowledgebase();
        void add_into_knowledgebase(int room, set<Percepts> perceptions);
        void change_percepts(int room, set<Percepts> perceptions);
        set<Percepts> get_percepts(int room);
};  
#endif;
