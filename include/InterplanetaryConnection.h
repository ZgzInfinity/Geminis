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

struct InterplanetaryConnection
{
    PlanetaryStation origin;
    PlanetaryStation destination;

    Direction connectionUCS;
    Direction connectionFromOrigin;
    Direction connectionFromDestination;



    InterplanetaryConnection(PlanetaryStation _origin, PlanetaryStation _destination);

    /**
     * Default builder without parameters
     */
    InterplanetaryConnection();


    bool collisionInOrigin();

    bool collisionInDestination();
};



#endif