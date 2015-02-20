#include "Test_JupiterPosition.h"

#include "Test_Position.h"

#include "Ephemerides/Jupiter/JupiterSchlyterModel.h"
#include "Ephemerides/Jupiter/JupiterVSOP87Model.h"

bool Test_JupiterPosition::Run()
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
		{ 4.934524007378320E+00, -5.311597514420612E-01, -1.083492434637036E-01, 2442413.500000000 },
		{ -4.710612553711103E+00, 2.579951983171591E+00, 9.486453299341881E-02, 2444239.500000000 },
		{ 2.076646654792283E+00, -4.709715747747291E+00, -2.709926272873371E-02, 2446066.500000000 },
		{ -5.677743650091845E-01, 5.119672032779075E+00, -8.513377625691008E-03, 2447892.500000000 },
		{ -2.793268469520481E+00, -4.591333046206624E+00, 8.157271426589674E-02, 2449718.500000000 },
		{ 3.996320930871260E+00, 2.932561639470049E+00, -1.016170891898448E-01, 2451544.500000000 },
		{ -5.408661581991377E+00, -6.556621060145548E-01, 1.237442078713980E-01, 2453371.500000000 },
		{ 4.505317309954709E+00, -2.163554804008311E+00, -9.190496087672803E-02, 2455197.500000000 },
		{ -3.726727838294460E+00, 3.793260458560339E+00, 6.756038085931930E-02, 2457023.500000000 },
		{ 5.223486043533112E-01, -5.193583285834395E+00, 9.853731748366628E-03, 2458849.500000000 },
		{ 1.050303519555381E+00, 4.966542119788040E+00, -4.409887883300617E-02, 2460676.500000000 },
	};

	POSITION_TEST( JupiterSchlyterOrbitalEphemeris, "Jupiter Schlyter", 5.4 );
	POSITION_TEST( JupiterVSOP87OrbitalEphemeris, "Jupiter VSOP87", 5.4 );

	return true;
}
