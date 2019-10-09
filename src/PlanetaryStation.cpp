#include <cmath>

#include "../include/PlanetaryStation.h"


PlanetaryStation::PlanetaryStation(Planet _planet, float _inclination, float _azimuth){
    if(_inclination > 0 && _inclination < PI){
        if(_azimuth > - PI && _azimuth <= PI){
            planet = _planet;
            inclination =_inclination;
            azimuth = _azimuth;
            stationUCS = position(_planet, _inclination, _azimuth + PI);
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
     Point stationLocal = Point(sin(i) * -cos(a), cos(i), sin(i) * sin(a));
     //cout << "stationLocal " << stationLocal.toString() << endl;
     Direction d1 = p.refCity - p.center;
     d1 = d1 / mod(d1);
     Direction d2 = p.axis / 2;
     d2 = d2 / mod(d2);
     Direction d3 = cross(d1, d2);
     Direction d4 = cross(d2, d3);
     Matrix4 b = Matrix4::changeBase(d4 * p.radius, d2 * p.radius, d3 * p.radius, p.center);
     //cout << "d4 " << d4.toString() << endl;
     //cout << "d3 " << d3.toString() << endl;
     //cout << "d2 " << d2.toString() << endl;
     //cout << "d1 " << d1.toString() << endl;
     return b * stationLocal;
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


