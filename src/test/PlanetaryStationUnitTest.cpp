#include <cmath>

#include "../../include/test/PlanetaryStationUnitTest.h"

void testPlanetaryStation(PlanetaryStation ps, Point eStationUCS,
     Direction eNormal, Direction eLongitude, Direction eLatitude){
    assert(ps.stationUCS == eStationUCS);
    assert(ps.surfaceNormal == eNormal);
    assert(ps.longitudeTangent == eLongitude);
    assert(ps.latitudeTangent == eLatitude);
}