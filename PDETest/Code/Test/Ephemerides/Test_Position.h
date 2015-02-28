#ifndef TEST_POSITION_H
#define TEST_POSITION_H

#include "Time/ProfileTimer.h"

#define POSITION_TEST( Model, Name, ApproxMag ) \
	{ \
	    Model xModel; \
	    const int iTestCaseCount = sizeof( kaxTestValues ) / sizeof( kaxTestValues[ 0 ] ); \
	    const double dApproximateMagnitude = ApproxMag; \
	    double dError = 0; \
        double dMaxError = -1e26; \
        double dMinError = 1e26; \
        const double dStartTime = GetProfileTimer( ); \
        for( int i = 0; i < iTestCaseCount; ++i ) \
        { \
            const EphemerisVector4 xTestPosition = xModel.CalculateNoLightTimePosition( DPVector4( 0.0, 0.0, 0.0, kaxTestValues[ i ].mdJDT ) ); \
		    const double dDistance = ( xTestPosition.xyz() \
		    - EphemerisVector4( kaxTestValues[ i ].mdEclipticX, kaxTestValues[ i ].mdEclipticY, kaxTestValues[ i ].mdEclipticZ ).xyz() ) \
				.Magnitude(); \
		    \
            dMaxError = ( dMaxError > dDistance ) ? dMaxError : dDistance; \
            dMinError = ( dMinError < dDistance ) ? dMinError : dDistance; \
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
        const double dEndTime = GetProfileTimer(); \
	    const double dAverageError = dError / static_cast< double >( iTestCaseCount ); \
        const double dAverageTimeUS = 1000.0 * 1000.0 * ( dEndTime - dStartTime ) / static_cast< double >( iTestCaseCount ); \
        printf( "\r\n" ); \
        printf( "\r\n" ); \
        printf( "-----------------------------------------------------------------------------\r\n" ); \
	    printf( "Average error in " Name " model = %.6f%%\r\n", 100.0  * dAverageError / dApproximateMagnitude ); \
        printf( "\r\n" ); \
        printf( "Min = %.10f%% (%.10fAU)\r\n", 100.0  * dMinError / dApproximateMagnitude, dMinError ); \
        printf( "Max = %.10f%% (%.10fAU)\r\n", 100.0  * dMaxError / dApproximateMagnitude, dMaxError ); \
        printf( "\r\n" ); \
        printf( "Average run time was %.12fus\r\n", dAverageTimeUS ); \
        printf( "-----------------------------------------------------------------------------\r\n" ); \
        printf( "\r\n" ); \
        printf( "\r\n" ); \
	}

#endif
