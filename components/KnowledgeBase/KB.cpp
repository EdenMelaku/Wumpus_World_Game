#include "KB.h"


namespace components{

using namespace DataStructures; 

    /**
     * @brief Get knowledgebase data structure
     * 
     * @return std::map<std::pair<int,int>, Knowledge>  the knowledgebase data structure 
     */
    std::map<std::pair<int,int>, Knowledge> KnowledgeBase::get_data()
    {
        return data;
    }
    /**
     * @brief Add information into the knowledgebase data structure
     * 
     * @param room          room to add information to
     * @param knowledge     information of the room
     */
    void KnowledgeBase::add_into_knowledgebase(std::pair<int,int> room, Knowledge knowledge)
    {
        data[room] = knowledge;
    }
    /**
     * @brief Change room information
     * 
     * @param room          room to change information of
     * @param knowledge     information of the room
     */
    void KnowledgeBase::change_room_information(std::pair<int, int> room, Knowledge knowledge)
    {
        data[room] = knowledge;
    }
    /**
     * @brief Get information associated with the room
     * 
     * @param room          room to get information of
     * @return Knowledge    information of the room passed as a parameter
     */
    Knowledge KnowledgeBase::get_room_information(std::pair<int, int> room)
    {
        return data[room];
    }

}
