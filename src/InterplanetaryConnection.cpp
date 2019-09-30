#include "../include/InterplanetaryConnection.h"
#include "../include/SharedOps.h"


InterplanetaryConnection::InterplanetaryConnection(PlanetaryStation _origin,
     PlanetaryStation _destination){
    origin = _origin;
    destination = _destination;
    connectionUCS = sub(_origin.stationUCS, _destination.stationUCS);
    Matrix t;
    t.matrixChangeOfBase(_origin.longitudeTangent, _origin.latitudeTangent,
     _origin.surfaceNormal, _origin.stationUCS);
    connectionFromOrigin = mul(t, connectionUCS);
    t.matrixChangeOfBase(_destination.longitudeTangent, _destination.latitudeTangent,
     _destination.surfaceNormal, _destination.stationUCS);
    //connectionFromDestination = mul(t, connectionUCS);
    connectionFromDestination = mul(t, sub(_destination.stationUCS, _origin.stationUCS));
}

/**
 * Default builder without parameters
 */
InterplanetaryConnection::InterplanetaryConnection(){}

bool InterplanetaryConnection::collisionInOrigin(){
    return acos(dot(origin.surfaceNormal, connectionFromOrigin) / 
    (mod(origin.surfaceNormal) * mod(connectionFromOrigin))) > PI / 2; 
}

bool InterplanetaryConnection::collisionInDestination(){
    return acos(dot(destination.surfaceNormal, connectionFromDestination) / 
    (mod(destination.surfaceNormal) * mod(connectionFromDestination))) > PI / 2; 
}