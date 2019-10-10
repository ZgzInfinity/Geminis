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
 * PlanetaryStation.h interface file of the PlanetaryStation module
 */


#ifndef PLANETARY_STATION_H
#define PLANETARY_STATION_H

#include "Planet.h"


/*
 * Definition of data type PlanetaryStation
 */
struct PlanetaryStation {
    Planet planet;
    float inclination;
    float azimuth;
    Point stationUCS;
    Direction surfaceNormal;
    Direction longitudeTangent;
    Direction latitudeTangent;



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
    PlanetaryStation(Planet _planet, float _inclination, float _azimuth);



    /**
     * Default builder without parameters
     */
    PlanetaryStation();

};



/**
 * Gets the position of a planetary station depending of the planet information,
 * the inclination and the azimuth
 * @param p is the where the station is going to be located
 * @param i is the inclination
 * @param a is the azimuth
 * @returns the position of a planetary station depending of the planet information,
 * the inclination and the azimuth
 */
Point position(Planet p, float i, float a);



/**
 * Gets the Direction vector surface normal which is tangent to surface of the planet
 * @param _stationUCS is the position in UCS coordinates where the station is localted
 * @param _center is the center of the planet
 * @returns the Direction vector surface normal which is tangent to surface of the planet
 */ 
Direction normal(Point _stationUCS, Point _center);



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
Direction longitude(Planet p, Point _stationUCS);


#endif 