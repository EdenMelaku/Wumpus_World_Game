#ifndef KNOWLEDGEBASE_TEST_H
#define KNOWLEDGEBASE_TEST_H

#include <cxxtest/TestSuite.h>
#include "../../components/KnowledgeBase/KB.h"


class KBTest: public CxxTest::TestSuite
{
    public:
        void test_creation(void);

};

#endif