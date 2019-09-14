#ifndef AGENT_H
#define AGENT_H

#include <tuple>
#include <vector>


using namespace std;

enum class Direction
{
    left = 1,
    right,
    top,
    down
};
class Agent
{
private:
    pair<int, int> agent_location;
    string agent_direction;
    bool is_alive;
    bool has_arrow;
    vector<string> senses;
public:
    // getter and setter for agent location attribute
    pair<int,int> get_agent_location();
    void set_agent_location(pair<int, int> agent_location);

    // getter and setter for agent direction attribute
    string get_agent_direction();
    string set_agent_direction(string agent_direction);

    // getter and setter for is_alive
    bool get_is_alive();
    void set_is_alive(bool is_alive);

    // getter and setter for has_arrow
    bool get_has_arrow();
    void set_has_arrow(bool has_arrow);

    // getter and setter for senses;
    vector<string> get_senses();
    void set_senses(vector<string> senses);

    // sensors
    void percieve_room(pair<int, int> room_location);

    // knowledge base propositional logic
    // inference/reasoning
    bool tableaux_calculator(string propositional_logic);
    // actuators/actions
};
#endif;
