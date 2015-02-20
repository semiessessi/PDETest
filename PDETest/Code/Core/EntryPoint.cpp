#include <cstdio>

#include "Test/Test.h"
#include "Test/Ephemerides/Test_JupiterPosition.h"
#include "Test/Ephemerides/Test_SaturnPosition.h"
#include "Test/Ephemerides/Test_UranusPosition.h"
#include "Test/Ephemerides/Test_NeptunePosition.h"

int main( const char* const* const /*pszArguments*/, const int /*iArgumentCount*/ )
{
	// register a bunch of tests
	Test_JupiterPosition xTest_JupiterPosition;
	Test_SaturnPosition xTest_SaturnPosition;
    Test_UranusPosition xTest_UranusPosition;
	Test_NeptunePosition xTest_NeptunePosition;

	Test::Register( &xTest_JupiterPosition );
	Test::Register( &xTest_SaturnPosition );
    Test::Register( &xTest_UranusPosition );
	Test::Register( &xTest_NeptunePosition );

	return Test::RunAllTests() ? 0 : -1;
}
