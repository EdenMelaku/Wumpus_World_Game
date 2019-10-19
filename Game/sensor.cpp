#include "sensor.h"
#include <vector>

using namespace std;

sensor::sensor() {}
sensor::sensor(pair<int, int> locationn, Type typee) {
    location = locationn;
    sense = typee;
}

void sensor::setType(Type type) { sense = type; }
Type sensor::get_type() {return sense;}
pair<int, int> sensor::get_Location() { return location;}
