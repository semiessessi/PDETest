#include "Test_UranusPosition.h"

#include "Test_Position.h"

#include "Ephemerides/Uranus/UranusSchlyterModel.h"
#include "Ephemerides/Uranus/UranusVSOP87Model.h"

bool Test_UranusPosition::Run()
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
        { -1.744494606137659E+01, 5.498664244302127E+00, 2.468697155084433E-01, 2438761.500000000 },
        { -1.820862623160955E+01, -1.932694831642582E+00, 2.291419665548961E-01, 2440587.500000000 },
        { -1.608678590816671E+01, -9.060738917515621E+00, 1.751034308722026E-01, 2442413.500000000 },
        { -1.147378867218803E+01, -1.479319014920409E+01, 9.392518493267031E-02, 2444239.500000000 },
        { -5.146422337614633E+00, -1.833496435485122E+01, -1.343182778771124E-03, 2446066.500000000 },
        { 1.913483230555892E+00, -1.928481728883514E+01, -9.641652183617810E-02, 2447892.500000000 },
        { 8.724807955568814E+00, -1.764410594853045E+01, -1.785928056287178E-01, 2449718.500000000 },
        { 1.442337837469543E+01, -1.373845031068660E+01, -2.379222848768564E-01, 2451544.500000000 },
        { 1.834097165506202E+01, -8.126114079422257E+00, -2.678223403776396E-01, 2453371.500000000 },
        { 2.003287449549033E+01, -1.529803134401229E+00, -2.652254428900401E-01, 2455197.500000000 },
        { 1.930657031688398E+01, 5.250508028437853E+00, -2.306220923682022E-01, 2457023.500000000 },
        { 1.622169845371836E+01, 1.138647555794172E+01, -1.678644752297388E-01, 2458849.500000000 },
        { 1.109790468119819E+01, 1.608957561046608E+01, -8.401843959325274E-02, 2460676.500000000 },
        { 4.529379022261322E+00, 1.867918507805232E+01, 1.068543184616370E-02, 2462502.500000000 },
        { -2.653645431899764E+00, 1.869683064535701E+01, 1.037628602742831E-01, 2464328.500000000 },
    };

    POSITION_TEST( UranusSchlyterOrbitalEphemeris, "Uranus Schlyter", 19.0 );
	POSITION_TEST( UranusVSOP87DOrbitalEphemeris, "Uranus VSOP87D (truncated)", 19.0 );

    return true;
}
