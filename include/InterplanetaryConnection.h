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
 * InterplanetaryConnection.h interface file of the InterplanetaryConnection module
 */

#ifndef INTERPLANETARY_CONNECTION_H
#define INTERPLANETARY_CONNECTION_H

#include "PlanetaryStation.h"


/*
 * Definition of data type InterplanetaryConnection type
 */
struct InterplanetaryConnection {
    // stations between which connection is established
    PlanetaryStation origin;
    PlanetaryStation destination;

    // Direction vector using UCS coordinates
    Direction connectionUCS;
    // Direction vector from the origin
    Direction connectionFromOrigin;
    // Direction vector from the destination
    Direction connectionFromDestination;



    /**
     * Gets an interplenary conection between the two planets, the origin planet and the destination planet
     * @param _origin is the origin planetary station
     * @param _destination is the destination planetary station
     * @returns an interplenary conection between the two planets, the origin planet and the destination planet
     */
    InterplanetaryConnection(PlanetaryStation _origin, PlanetaryStation _destination);



    /**
     * Default builder without parameters
     */
    InterplanetaryConnection();



    /**
     * @Gets if there is a collision against the orgin planet
     * @returns true if and only if there is a collision against the origin planet
     */
    bool collisionInOrigin();



    /**
     * @Gets if there is a collision against the destination planet
     * @returns true if and only if there is a collision against the destination planet
     */
    bool collisionInDestination();
};



#endif