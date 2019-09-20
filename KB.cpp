#include "KB.h"


map<pair<int,int>, Knowledge> KnowledgeBase::get_knowledgebase()
{
    return knowledgebase;
}
void KnowledgeBase::add_into_knowledgebase(pair<int,int> room, Knowledge knowledge)
{
    knowledgebase[room] = knowledge;
}
void KnowledgeBase::change_percepts(pair<int, int> room, Knowledge knowledge)
{
    knowledgebase[room] = knowledge;
}
Knowledge KnowledgeBase::get_percepts(pair<int, int> room)
{
    return knowledgebase[room];
}
