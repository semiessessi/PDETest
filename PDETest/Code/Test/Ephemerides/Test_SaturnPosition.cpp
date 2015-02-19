#include "Test_SaturnPosition.h"

#include "Ephemerides/Saturn/SaturnSchlyterModel.h"

bool Test_SaturnPosition::Run( )
{
	// SE: test the Schlyter model a bit, make sure it is correct against
	// a whole bunch of test values...

	// source of test data is JPL HORIZONS
	static const struct TestValue
	{
		double mdEclipticX;
		double mdEclipticY;
		double mdEclipticZ;
		double mdJDT;

	} kaxTestValues[] =
	{
		
		{ -2.426101134710925E+00, 8.696599760908482E+00, -5.570983877091697E-02, 2442413.500000000 },
		{ -9.299613115111459E+00, 1.403447594015825E+00, 3.450248763214140E-01, 2444239.500000000 },
		{-6.249527954209951E+00, -7.672358424911746E+00, 3.822060348864328E-01, 2446066.500000000 },
		{ 2.806990563274245E+00, -9.625656869216501E+00, 5.620495822306721E-02, 2447892.500000000 },
		{ 9.252581715211209E+00, -2.821619242960689E+00, -3.186803253329581E-01, 2449718.500000000 },
		{ 6.401415581709835E+00, 6.565252126065102E+00, -3.689217019413101E-01, 2451544.500000000 },
		{ -3.582478254991705E+00, 8.317200850787753E+00, -2.145229821996940E-03, 2453371.500000000 },
		{ -9.468005651167521E+00, 2.616115654392180E-01, 3.722148061258548E-01, 2455197.500000000 },
		{ -5.405311405676102E+00, -8.350094141167506E+00, 3.603094632803097E-01, 2457023.500000000 },
		{ 3.793444245292612E+00, -9.280656295021023E+00, 1.035624039124833E-02, 2458849.500000000 },
		{ 9.455339111133359E+00, -1.769524475883949E+00, -3.456974044128207E-01, 2460676.500000000 },
	};

	SaturnSchlyterOrbitalEphemeris xSchlyterModel;
	const int iTestCaseCount = sizeof( kaxTestValues ) / sizeof( kaxTestValues[ 0 ] );
	const double dApproximateMagnitude = 5.4;
	double dError = 0;
	for( int i = 0; i < iTestCaseCount; ++i )
	{
		const EphemerisVector4 xTestPosition = xSchlyterModel.CalculatePosition( DPVector4( 0.0, 0.0, 0.0, kaxTestValues[ i ].mdJDT ) );
		const double dDistance = ( xTestPosition.xyz( )
			- EphemerisVector4( kaxTestValues[ i ].mdEclipticX, kaxTestValues[ i ].mdEclipticY, kaxTestValues[ i ].mdEclipticZ ).xyz( ) )
			.Magnitude( );

		dError += dDistance;
		if( dDistance > 0.1 )
		{
			return TEST_FAIL( "Error in position greater than 0.1 AU!" );
		}

		if( dDistance > 0.01 )
		{
			TEST_WARNING( "Error in position is greater than 0.01 AU! - was %f", dDistance );
		}
	}
	const double dAverageError = dError / static_cast< double >( iTestCaseCount );
	printf( "Error in Saturn Schlyter model across test cases was on average %.2f%% (%.4f AU)\r\n", 100.0  * dAverageError / dApproximateMagnitude, dAverageError );

	return true;
}
