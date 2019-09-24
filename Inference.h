#ifndef INFERENCE_H
#define INFERENCE_H

#include <map>
#include <set>
#include <vector>
#include "KB.h"

using namespace std;

struct Response{
  pair<int, int> move_to;
  pair<int, int> shoot_at;
  map<pair<int, int>, Knowledge> updated_knowledge;
};

class Inference
{
private:
  vector<pair<int, int >> adjacent_rooms;
  vector<pair<int, int>> adjacent_ok_rooms;
  vector<pair<int, int>> adjacent_visited_rooms;

  pair<int, int> wumpus_room;
  KnowledgeBase knowledge_base; // knowledge base object
  map<pair<int, int>, Knowledge> knowledge; // the actual rooms knowledge base

public:
  Inference(KnowledgeBase Knowledge_base);
  bool is_valid_position(int i, int j);
  vector<pair<int, int>> get_adjacent_rooms(pair<int, int> current_room);
  pair<int, int> find_possible_move(pair<int, int> current_room);
  Response inference(pair<int, int> current_room);
};
#endif;
