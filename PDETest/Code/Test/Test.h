#ifndef TEST_H
#define TEST_H

#include <vector>

// some helper to give nice messages when tests fail

#define TEST_FAIL( szMessage ) Test::Fail( szMessage, __FILE__, __LINE__ )
#define TEST_WARNING( szMessage, ... ) printf( "Test warning: (%s:%d) :" szMessage "\r\n", __FILE__, __LINE__, ##__VA_ARGS__ )

// some base class for a test
class Test
{
public:

	virtual ~Test() {}

	virtual bool Run() { return true; }
	virtual const char* GetName() const { return "Null Test"; }

	static void Register( Test* const pxTest );
	static bool RunAllTests();

protected:

	static bool Fail( const char* const szReason, const char* const szFile, const int iLine );

private:

	static std::vector< Test* > sapxTests;

};

#endif
