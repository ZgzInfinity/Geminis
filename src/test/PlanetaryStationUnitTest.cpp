#include <cmath>

#include "../../include/test/PlanetaryStationUnitTest.h"

void testPlanetaryStation(PlanetaryStation ps, Point eStationUCS,
     Direction eNormal, Direction eLongitude, Direction eLatitude){
    //cout << "Given: " << ps.stationUCS.toString() << " - Expected: " << eStationUCS.toString() << endl;
    assert(ps.stationUCS == eStationUCS);
    //cout << "Given: " << ps.surfaceNormal.toString() << " - Expected: " << eNormal.toString() << endl;
    assert(ps.surfaceNormal == eNormal);
    //cout << "Given: " << ps.longitudeTangent.toString() << " - Expected: " << eLongitude.toString() << endl;
    assert(ps.longitudeTangent == eLongitude);
    //cout << "Given: " << ps.latitudeTangent.toString() << " - Expected: " << eLatitude.toString() << endl;
    assert(ps.latitudeTangent == eLatitude);
}