#include "KB.h"
#include <iostream>


namespace components{

using namespace DataStructures; 

    KnowledgeBase::KnowledgeBase(){
        ;
    }
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
        // std::cout << "----------------" << std::endl;
        // std::cout << room.first << "," << room.second << std::endl;
        // std::cout << "in kb, breeze: " << knowledge.breeze << std::endl;
        // std::cout << "in kb, bump: " << knowledge.bump << std::endl;
        // std::cout << "in kb, stench: " << knowledge.stench << std::endl;

        data[room] = knowledge;
        
        // std::cout << "after assignment, breeze: " << data[room].breeze << std::endl;
        // std::cout << "after assignment, bump: " << data[room].bump << std::endl;
        // std::cout << "after assignment, stench: " << data[room].stench << std::endl;
        // std::cout << "-----------------" << std::endl;
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

    bool KnowledgeBase::get_specific_percept_info(std::pair<int, int> room, DataStructures::constraint specific_knowledge){
        if(specific_knowledge == DataStructures::constraint::breeze) return KnowledgeBase::get_information_breeze(room);
        else if(specific_knowledge == DataStructures::constraint::bump) return KnowledgeBase::get_information_bump(room);
        else if(specific_knowledge == DataStructures::constraint::glitter) return KnowledgeBase::get_information_glitter(room);
        else if(specific_knowledge == DataStructures::constraint::pit) return KnowledgeBase::get_information_pit(room);
        else if(specific_knowledge == DataStructures::constraint::scream) return KnowledgeBase::get_information_scream(room);
        else if(specific_knowledge == DataStructures::constraint::stench) return KnowledgeBase::get_information_stench(room);
        else if(specific_knowledge == DataStructures::constraint::wumpus) return KnowledgeBase::get_information_wumpus(room);
        else return false;
    }

    bool KnowledgeBase::get_information_stench(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.stench;
    }
    bool KnowledgeBase::get_information_breeze(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.breeze;
    }
    bool KnowledgeBase::get_information_glitter(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.glitter;
    }
    bool KnowledgeBase::get_information_bump(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.bump;
    }
    bool KnowledgeBase::get_information_scream(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.scream;
    }
    bool KnowledgeBase::get_information_possible_wumpus(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.possible_wumpus;
    }
    bool KnowledgeBase::get_information_wumpus(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.wumpus;
    }
    bool KnowledgeBase::get_information_possible_pit(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.possible_pit;
    }
    bool KnowledgeBase::get_information_pit(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.pit;
    }
    bool KnowledgeBase::get_information_gold(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.gold;
    }
    bool KnowledgeBase::get_information_ok(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.ok;
    }
    bool KnowledgeBase::get_information_visited(std::pair<int, int> room)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        return k.visited;
    }

    void KnowledgeBase::change_information_stench(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.stench = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_breeze(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.breeze = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_glitter(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.glitter = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_bump(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.bump = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_scream(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.scream = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_possible_wumpus(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.possible_wumpus = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_wumpus(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.wumpus = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_possible_pit(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.possible_pit = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_pit(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.pit = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_gold(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.gold = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_ok(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.ok = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }
    void KnowledgeBase::change_information_visited(std::pair<int, int> room, bool value)
    {
        Knowledge k = KnowledgeBase::get_room_information(room);
        k.visited = value;
        KnowledgeBase::add_into_knowledgebase(room, k);
    }

}
