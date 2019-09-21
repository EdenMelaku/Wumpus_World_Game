#ifndef INFERENCE_H
#define INFERENCE_H

#include <map>
#include <set>
#include <vector>
#include "KB.h"

using namespace std;

struct response{
  pair<int, int> move_to = selected_room;
  pair<int, int> shoot_to = selected_room;
  KnowledgeBase updated_knowledge_base = updated_knowledge_base;
};

class Inference
{
private:
    vector<pair<int, int>> adjacent_rooms;
    vector<pair<int, int>> adjacent_ok_rooms;
    vector<pair<int, int>> adjacent_visited_rooms;
    pair<int, int> wumpus_room;
    KnowledgeBase knowledge_base;
public:
  Inference(KnowledgeBase KnowledgeBase);
  vector<pair<int, int>> get_adjacent_rooms(pair<int, int> current_room);
  vector<pair<int, int>> get_adjacent_ok_rooms(pair<int, int> current_room);
  vector<pair<int, int>> get_adjacent_visited_rooms(pair<int, int> current_room);

  void inference(Knowledge room_knowledge, pair<int, int> current_room);
};
#endif;
