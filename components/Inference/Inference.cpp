#include "Inference.h"


namespace components{

using namespace DataStructures;

    /**
     * @brief Construct a new Inference:: Inference object
     * 
     * @param kb        Knowledgebase object that will be used to infer
     */
    Inference::Inference(KnowledgeBase kb)
    {
        current_kb = kb;
    }
    Decision Inference::infer()
    {
        Decision decision;
        
        //todo

        return decision;
    }
    /**
     * @brief Get adjacent rooms available in the knowledge base
     * 
     * @param room 
     * @return std::vector<std::pair<int,int>> 
     */
    std::vector<std::pair<int, int>> Inference::get_adjacent_rooms(std::pair<int, int> room)
    {
        std::vector<std::pair<int, int>> adjacent_rooms;
        //iterator in knowledgebase
    }
    /**
     * @brief Infer that wumpus exists in a room
     * 
     * @return true 
     * @return false 
     */
    bool Inference::infer_wumpus()
    {
        // todo
    }
    /**
     * @brief Infer that pit exists in a room
     * 
     * @return true 
     * @return false 
     */
    bool infer_pit()
    {
        // todo
    }
    /**
     * @brief Infer that pit exists in a room
     * 
     * @return true 
     * @return false 
     */
    bool infer_ok()
    {
        // todo
    }

}
