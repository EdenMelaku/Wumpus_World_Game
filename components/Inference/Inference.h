#ifndef INFERENCE_H
#define INFERENCE_H

#include <map>
#include <set>
#include <vector>
#include "KB.h"


namespace components{

class Inference
{
    private:
        KnowledgeBase current_kb;
    public:
        Inference();
        ~Inference();
        std::vector<std::pair<int,int>> get_adjacent_rooms(std::pair<int, int> room);
        bool infer_wumpus();
        bool infer_pit();
        bool infer_ok();
        bool infer_gold();
};

} 
#endif;
