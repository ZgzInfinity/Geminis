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
 * InterplanetaryConnectionUnitTest.h interface file of the InterplanetaryConnectionUnitTest module
 */

#ifndef INTERPLANETARY_CONNECTION_UNIT_TEST_H
#define INTERPLANETARY_CONNECTION_UNIT_TEST_H

#include <cassert>
#include "../PlanetaryStation.h"
#include "../InterplanetaryConnection.h"



/**
 * proves that all operations working with interplanetary connections work correctly
 */
void testInterplanetaryConnection(InterplanetaryConnection ipc, Direction eConnectionUCS,
     Direction eConnectionOrigin, Direction eConnectionDestination, bool eCollisionOrigin,
     bool eCollisionDestination);





#endif