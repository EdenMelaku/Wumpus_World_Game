#ifndef INFERENCE_H
#define INFERENCE_H

#include <map>
#include <set>
#include <vector>
#include "../KnowledgeBase/KB.h"
#include "../../utilities/DataStructures.h"


namespace components{

class Inference
{
  /*
  *
  * This class used to infer possible action to be performed by the agent.
  * and it also updates the knowledgebase with the infered parameters
  *
  */
  private:
    std::vector<std::pair<int, int>> adjacent_rooms;
    std::pair<int, int> wumpus_room;
    KnowledgeBase current_kb;

    bool is_valid_position(int i, int j);
    std::vector<std::pair<int, int>> get_adjacent_rooms(std::pair<int, int> current_room);
    std::pair<int, int> find_possible_move(std::pair<int, int> current_room);

  public:
    Inference(KnowledgeBase current_kb);
    DataStructures::Decision infer(std::pair<int, int> current_room);
};
}
#endif
