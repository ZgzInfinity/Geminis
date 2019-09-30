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
    return add(p.center,
        Point(p.radius * sin(i) * sin(a), p.radius * sin(i) * cos(a), p.radius * cos(i)));
}


Direction normal(Point _stationUCS, Point _center){
    Direction d = sub(_stationUCS, _center);
    return div(d, mod(d));
}



Direction longitude(Planet p, Point _stationUCS){
    Direction d = div(p.axis, 2);
    Matrix t = Matrix();
    t.matrixTranslation(p.center.c[0], p.center.c[1], p.center.c[2]);
    d = cross(mul(t, d), sub(_stationUCS, p.center));
    t.matrixTranslation(_stationUCS.c[0], _stationUCS.c[1], _stationUCS.c[2]);
    d = mul(t, d);
    return div(d, mod(d));
}


