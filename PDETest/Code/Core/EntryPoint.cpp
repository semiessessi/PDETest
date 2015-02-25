#include <cstdio>

#include "Test/Test.h"
#include "Test/Ephemerides/Test_SunPosition.h"
#include "Test/Ephemerides/Test_MercuryPosition.h"
#include "Test/Ephemerides/Test_EarthPosition.h"
#include "Test/Ephemerides/Test_JupiterPosition.h"
#include "Test/Ephemerides/Test_SaturnPosition.h"
#include "Test/Ephemerides/Test_UranusPosition.h"
#include "Test/Ephemerides/Test_NeptunePosition.h"

int main( const char* const* const /*pszArguments*/, const int /*iArgumentCount*/ )
{
	// register a bunch of tests
    Test_SunPosition xTest_SunPosition;
    Test_MercuryPosition xTest_MercuryPosition;
    Test_EarthPosition xTest_EarthPosition;
	Test_JupiterPosition xTest_JupiterPosition;
	Test_SaturnPosition xTest_SaturnPosition;
    Test_UranusPosition xTest_UranusPosition;
	Test_NeptunePosition xTest_NeptunePosition;

    Test::Register( &xTest_SunPosition );
    Test::Register( &xTest_MercuryPosition );
    Test::Register( &xTest_EarthPosition );
	Test::Register( &xTest_JupiterPosition );
	Test::Register( &xTest_SaturnPosition );
    Test::Register( &xTest_UranusPosition );
	Test::Register( &xTest_NeptunePosition );

	return Test::RunAllTests() ? 0 : -1;
}
