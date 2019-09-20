#include "KB.h"


map<int, set<Percepts>> KnowledgeBase::get_knowledgebase()
{
    return knowledgebase;
}
void KnowledgeBase::add_into_knowledgebase(int room, set<Percepts> perceptions)
{
    knowledgebase[room] = perceptions;
}
void KnowledgeBase::change_percepts(int room, set<Percepts> perceptions)
{
    knowledgebase[room] = perceptions;
}
set<Percepts> KnowledgeBase::get_percepts(int room)
{
    return knowledgebase[room];
}
