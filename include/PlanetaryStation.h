#ifndef PLANETARY_STATION_H
#define PLANETARY_STATION_H

#include "Planet.h"

struct PlanetaryStation {
    Planet planet;
    float inclination;
    float azimuth;
    Point stationUCS;
    Direction surfaceNormal;


    PlanetaryStation(Planet _planet, float _inclination, float _azimuth);


    PlanetaryStation();
};


#endif /* PLANETARY_STATION_H */