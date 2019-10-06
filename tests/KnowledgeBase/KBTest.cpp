#include "KBTest.h"
#include <map>
#include <set>
#include <typeinfo>


typedef std::map<std::pair<int, int>, DataStructures::Knowledge> datatype;

void KBTest::test_creation(void)
{
    components::KnowledgeBase kb = components::KnowledgeBase();
    
    TS_ASSERT_EQUALS(1 + 1, 2);
    // TS_ASSERT_EQUALS(typeid(kb.get_data()).name(), datatype);
}