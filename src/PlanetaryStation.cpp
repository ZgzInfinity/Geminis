/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 

/*
 * PlanetaryStation.cpp implementation file of the PlanetaryStation module
 */

#include <cmath>
#include "../include/PlanetaryStation.h"



/**
 * Gets a PlanetaryStation in a specific planet using the angles of inclination and azimuth
 * @param p is the planet where the planetary station is going to be located
 * @param _inclination is the angle with respect to the planetary axis (that connects thesouth pole to the north pole), 
 * similar to the Earth’s latitude but measured from theaxis instead of the equator. It is measured in radians within 
 * the range(0,π).
 * @param _azimuth he angle around the globe with respect to a specific 0−meridian, similar to the Earth’s longitude 
 * It is measured in radians within the range(−π,π].
 * @returns a PlanetaryStation in a specific planet using the angles of inclination and azimuth
 */
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



/**
 * Default builder without parameters
 */
PlanetaryStation::PlanetaryStation(){}



/**
 * Gets the position of a planetary station depending of the planet information,
 * the inclination and the azimuth
 * @param p is the where the station is going to be located
 * @param i is the inclination
 * @param a is the azimuth
 * @returns the position of a planetary station depending of the planet information,
 * the inclination and the azimuth
 */
Point position(Planet p, float i, float a){
     Point stationLocal = Point(sin(i) * -cos(a), cos(i), sin(i) * sin(a));
     Direction d1 = p.refCity - p.center;
     d1 = d1 / mod(d1);
     Direction d2 = p.axis / 2;
     d2 = d2 / mod(d2);
     Direction d3 = cross(d1, d2);
     Direction d4 = cross(d2, d3);
     Matrix4 b = Matrix4::changeBase(d4 * p.radius, d2 * p.radius, d3 * p.radius, p.center);
     return b * stationLocal;
}



/**
 * Gets the Direction vector surface normal which is tangent to surface of the planet
 * @param _stationUCS is the position in UCS coordinates where the station is localted
 * @param _center is the center of the planet
 * @returns the Direction vector surface normal which is tangent to surface of the planet
 */ 
Direction normal(Point _stationUCS, Point _center){
    Direction d = _stationUCS - _center;
    return d / mod(d);
}



/**
 * Gets the Direction vector longitude which is the direction tangent to the surface of the planet
 * and perpendicular to the planet’s axis (modulus is 1). This tangent follows the positive variation 
 * of the azimuth (and no variation of the inclination).
 * @param p is the where the station is going to be located
 * @param _stationUCS is the position in UCS coordinates where the station is localted
 * @returns the Direction vector longitude which is the direction tangent to the surface of the planet
 * and perpendicular to the planet’s axis (modulus is 1). This tangent follows the positive variation 
 * of the azimuth (and no variation of the inclination).
 */
Direction longitude(Planet p, Point _stationUCS){
    Direction d = p.axis / 2;
    d = cross(d, _stationUCS - p.center);
    return d / mod(d);
}


