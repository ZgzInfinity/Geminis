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
 * InterplanetaryConnectionUnitTest.cpp implementation file of InterplanetaryConnectionUnitTest module
 */

#include "../../include/test/InterplanetaryConnectionUnitTest.h"
#include "../include/SharedOps.h"



/**
 * proves that all operations working with interplanetary connections work correctly
 */
void testInterplanetaryConnection(InterplanetaryConnection ipc, Direction eConnectionUCS,
    Direction eConnectionOrigin, Direction eConnectionDestination, bool eCollisionOrigin,
    bool eCollisionDestination){
    assert(ipc.connectionUCS == eConnectionUCS);
    assert(ipc.connectionFromOrigin == eConnectionOrigin);
    assert(ipc.collisionInOrigin() == eCollisionOrigin);
    assert(ipc.collisionInDestination() == eCollisionDestination);
}
