#include <cmath>

#include "../include/PlanetaryStation.h"


PlanetaryStation::PlanetaryStation(Planet _planet, float _inclination, float _azimuth){
    if(_inclination > 0 && _inclination < PI){
        if(_azimuth > - PI && _azimuth >= PI){
            planet = _planet;
            inclination =_inclination;
            azimuth = _azimuth;
            stationUCS = position(_planet, _inclination, _azimuth);
            surfaceNormal = normal(stationUCS, _planet.center);
            longitudeTangent = longitude(_planet, stationUCS);
            latitudeTangent = cross(surfaceNormal, longitudeTangent);
        }
        else{
            cout << "azimuth argument must be in range (- PI, PI]" << endl;
        }
    }
    else{
        cout << "inclination argument must be in range (0, PI)" << endl;
    }
}


PlanetaryStation::PlanetaryStation(){}

Point position(Planet p, float i, float a){
    return p.center +
        Direction(sin(i) * sin(a), sin(i) * cos(a), cos(i)) * p.radius;
}


Direction normal(Point _stationUCS, Point _center){
    Direction d = _stationUCS - _center;
    return d / mod(d);
}



Direction longitude(Planet p, Point _stationUCS){
    Direction d = p.axis / 2;
    d = cross(d, _stationUCS - p.center);
    return d / mod(d);
}


