#include "Test.h"

#include <cstdio>

std::vector< Test* > Test::sapxTests;

void Test::Register( Test* const pxTest )
{
	sapxTests.push_back( pxTest );
}

bool Test::RunAllTests()
{
	printf( "Running tests.\r\n" );
	bool bAllTestsPassed = true;
	for( int i = 0; i < static_cast< int >( sapxTests.size() ); ++i )
	{
		printf( "Running test: %s\r\n", sapxTests[ i ]->GetName() );
		if( !sapxTests[ i ]->Run() )
		{
			printf( "A test has failed! Aborting further tests...\r\n" );
			bAllTestsPassed = false;
			break;
		}
	}

	if( bAllTestsPassed )
	{
		printf( "All tests passed! " );
	}

	printf( "Done.\r\n" );

	return bAllTestsPassed;
}

bool Test::Fail( const char* const szReason, const char* const szFile, const int iLine )
{
	printf( "Failed test: %s (%s:%d)\r\n", szReason, szFile, iLine );
	return false;
}
