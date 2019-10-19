#ifndef LOGICPARSER_H
#define LOGICPARSER_H
#include "sensor.h"
#include <vector>

using namespace std;

class logicParser
{
public:
    logicParser();
   
    bool preprocess(vector<Sensor> argument);
    bool validate(vector<Sensor> argument , Sensor deduction);
    Type get_type();


};

#endif;
