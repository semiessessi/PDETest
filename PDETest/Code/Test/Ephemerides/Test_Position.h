#ifndef TEST_POSITION_H
#define TEST_POSITION_H

#define POSITION_TEST( Model, Name, ApproxMag ) \
	{ \
	    Model xModel; \
	    const int iTestCaseCount = sizeof( kaxTestValues ) / sizeof( kaxTestValues[ 0 ] ); \
	    const double dApproximateMagnitude = ApproxMag; \
	    double dError = 0; \
        for( int i = 0; i < iTestCaseCount; ++i ) \
	    { \
			const EphemerisVector4 xTestPosition = xModel.CalculatePosition( DPVector4( 0.0, 0.0, 0.0, kaxTestValues[ i ].mdJDT ) ); \
		    const double dDistance = ( xTestPosition.xyz() \
		    - EphemerisVector4( kaxTestValues[ i ].mdEclipticX, kaxTestValues[ i ].mdEclipticY, kaxTestValues[ i ].mdEclipticZ ).xyz() ) \
				.Magnitude(); \
		    \
		    dError += dDistance; \
			if( dDistance >( 0.5 * dApproximateMagnitude ) ) \
			{ \
				return TEST_FAIL( "Error in position greater than 50%!" ); \
			} \
			else if( dDistance > ( 0.1 * dApproximateMagnitude ) ) \
			{ \
				return TEST_FAIL( "Error in position greater than 10%!" ); \
			} \
			else if( dDistance > ( 0.02 * dApproximateMagnitude ) ) \
		    { \
				return TEST_FAIL( "Error in position greater than 2%!" ); \
		    } \
	    } \
	    const double dAverageError = dError / static_cast< double >( iTestCaseCount ); \
	    printf( "Error in " Name " model across test cases was on average %.2f%% (%.4f AU)\r\n", 100.0  * dAverageError / dApproximateMagnitude, dAverageError ); \
	}

#endif
