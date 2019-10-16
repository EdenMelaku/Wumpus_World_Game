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
    std::set<std::pair<int, int>> ok_rooms;
    std::pair<int, int> wumpus_room;
    std::set<std::pair<int, int>> pit_rooms;

    KnowledgeBase& current_kb;

    // std::vector<std::pair<int, int>> get_adjacent_rooms(std::pair<int, int> current_room);
    std::pair<int, int> find_possible_move(std::pair<int, int> current_room);
    void rule_matching(std::pair<int, int> room);
  public:
    Inference(KnowledgeBase& kb);
    DataStructures::Decision infer(std::pair<int, int> current_room);
};

}
#endif
