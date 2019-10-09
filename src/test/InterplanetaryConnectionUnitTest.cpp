#include "../../include/test/InterplanetaryConnectionUnitTest.h"
#include "../include/SharedOps.h"

void testInterplanetaryConnection(InterplanetaryConnection ipc, Direction eConnectionUCS,
     Direction eConnectionOrigin, Direction eConnectionDestination){
    assert(ipc.connectionUCS == eConnectionUCS);
    assert(ipc.connectionFromOrigin == eConnectionOrigin);
    assert(ipc.connectionFromDestination == eConnectionDestination);
}