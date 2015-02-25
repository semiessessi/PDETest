#ifndef TEST_SUN_POSITION_H
#define TEST_SUN_POSITION_H

#include "Test/Test.h"

class Test_SunPosition
: public Test
{

public:

    virtual bool Run();
    virtual const char* GetName() const { return "Sun Position"; }

};

#endif
