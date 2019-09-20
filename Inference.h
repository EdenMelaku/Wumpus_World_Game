#ifndef INFERENCE_H
#define INFERENCE_H

#include <map>
#include <set>
#include <vector>
#include "KB.h"


using namespace std;

class Inference
{
    private:
        KnowledgeBase current_kb;
    public:
      Inference();
      ~Inference();
      vector<pair<int,int>> get_adjacent_rooms(pair<int, int> room);
      bool infer_wumpus();
      bool infer_pit();
      bool infer_ok();
      bool infer_gold();
};  
#endif;
