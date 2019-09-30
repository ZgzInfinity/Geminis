#ifndef PLANETARY_STATION_H
#define PLANETARY_STATION_H

#include "Planet.h"

struct PlanetaryStation {
    Planet planet;
    float inclination;
    float azimuth;
    Point stationUCS;
    Direction surfaceNormal;
    Direction longitudeTangent;
    Direction latitudeTangent;


    PlanetaryStation(Planet _planet, float _inclination, float _azimuth);


    PlanetaryStation();
};

Point position(Planet p, float i, float a);

Direction normal(Point _stationUCS, Point _center);

Direction longitude(Planet p, Point _stationUCS);


#endif /* PLANETARY_STATION_H */