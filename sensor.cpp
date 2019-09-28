#include "sensor.h"
#include <vector>

using namespace std;

sensor::sensor() {}
sensor::sensor(pair<int, int> location, Type type) {
    location = location;
    sense = type;
}

void sensor::setType(Type type) { sense = type; }
Type sensor::get_type() {return sense;}
pair<int, int> sensor::get_Location() { return location;}
