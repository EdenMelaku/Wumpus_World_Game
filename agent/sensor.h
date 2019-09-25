#ifndef SENSOR_H
#define SENSOR_H

using namespace std;

enum class Type
{

    W,
    P,
    G,
    B,
    S,
    v,

    OK,
    scream
};
class Sensor
{
public:
    Sensor();
    Sensor(pair<int, int> location, Type type);

    pair<int, int> get_Location();
    Type get_type();
    void setType(Type type);

private:
    pair<int, int> location;
    Type sense;
};

#endif;
