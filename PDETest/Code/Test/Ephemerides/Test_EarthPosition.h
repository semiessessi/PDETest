#ifndef TEST_EARTH_POSITION_H
#define TEST_EARTH_POSITION_H

#include "Test/Test.h"

class Test_EarthPosition
: public Test
{

public:

	virtual bool Run();
	virtual const char* GetName() const { return "Earth Position"; }

};

#endif
