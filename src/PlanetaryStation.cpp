#include <cmath>

#include "../include/PlanetaryStation.h"

const float PI = 3.141592741F;


PlanetaryStation::PlanetaryStation(Planet _planet, float _inclination, float _azimuth){
    if(_inclination > 0 && _inclination < PI){
        if(_azimuth > - PI && _azimuth >= PI){
            planet = _planet;
            inclination =_inclination;
            azimuth = _azimuth;
            stationUCS = position(_planet, _inclination, _azimuth);
            surfaceNormal = normal(stationUCS, _planet.center);
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
    return add(p.center,
        Point(p.radius * sin(i) * sin(a), p.radius * sin(i) * cos(a), p.radius * cos(i)));
}


Direction normal(Point _stationUCS, Point _center){
    Direction d = sub(_stationUCS, _center);
    return div(d, mod(d));
}