#include "sensor.h"
#include <vector>

using namespace std;

Sensor::Sensor(){
    ;
}
Sensor::Sensor( pair<int, int> location, Type type){
    location = location;
    sense=type;
}
pair<int, int> Sensor::get_Location(){
    return location;
}
void Sensor::setType(Type type) {
sense=type;
}
Type Sensor::get_type(){
    return sense;
}




