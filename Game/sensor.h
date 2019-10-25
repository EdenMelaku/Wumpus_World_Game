#ifndef sensorInterface_H
#define sensorInterface_H

#include <tuple>


using namespace std;

enum class Type
{

    W,
    P,
    G,
    B,
    S,
    scream
};
class sensor
{
public:
    sensor();
    sensor(std::pair<int, int> location, Type type);
    pair<int, int> get_Location();
    Type get_type();
    void setType(Type type);
private:
    pair<int, int> location;
    Type sense;
};

#endif
