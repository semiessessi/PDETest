#include "Test_NeptunePosition.h"

#include "Test_Position.h"

#include "Ephemerides/Neptune/NeptuneSchlyterModel.h"

bool Test_NeptunePosition::Run()
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
		{ -2.013739620899849E+01, -2.265671219402949E+01, 9.304449813643269E-01, 2438761.500000000 },
		{ -1.555788530035916E+01, -2.600847733277623E+01, 8.939620901430338E-01, 2440587.500000000 },
		{ -1.042862456922064E+01, -2.844104444112792E+01, 8.258860825054125E-01, 2442413.500000000 },
		{ -4.930321910162986E+00, -2.986690598819883E+01, 7.285764890944982E-01, 2444239.500000000 },
		{ 7.458608473539911E-01, -3.023301646748362E+01, 6.053427137031213E-01, 2446066.500000000 },
		{ 6.392148189457224E+00, -2.952250033567742E+01, 4.606199851517884E-01, 2447892.500000000 },
		{ 1.180982698754985E+01, -2.775701427865907E+01, 2.994270592720987E-01, 2449718.500000000 },
		{ 1.680361722443347E+01, -2.499544331300537E+01, 1.274774641152608E-01, 2451544.500000000 },
		{ 2.119373744060909E+01, -2.133052943885693E+01, -4.916841350223711E-02, 2453371.500000000 },
		{ 2.481340387248673E+01, -1.689465167940639E+01, -2.239362661221648E-01, 2455197.500000000 },
		{ 2.752968744587270E+01, -1.184376032691615E+01, -3.905497988181240E-01, 2457023.500000000 },
		{ 2.923901119121590E+01, -6.359747719944839E+00, -5.428752697978658E-01, 2458849.500000000 },
		{ 2.987419256953164E+01, -6.390971156408377E-01, -6.753191255915647E-01, 2460676.500000000 },
		{ 2.940683898548725E+01, 5.101905311370520E+00, -7.827754781746551E-01, 2462502.500000000 },
		{ 2.785142896618660E+01, 1.065409369795068E+01, -8.612688568520366E-01, 2464328.500000000 },
	};

	POSITION_TEST( NeptuneSchlyterOrbitalEphemeris, "Neptune Schlyter", 30.0 );

	return true;
}