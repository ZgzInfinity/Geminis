#include "../include/InterplanetaryConnection.h"
#include "../include/SharedOps.h"


InterplanetaryConnection::InterplanetaryConnection(PlanetaryStation _origin,
     PlanetaryStation _destination){
    origin = _origin;
    destination = _destination;
    connectionUCS = _origin.stationUCS -  _destination.stationUCS;
    connectionFromOrigin = Matrix3::trans(Matrix3::changeBase(_origin.longitudeTangent, _origin.latitudeTangent,
     _origin.surfaceNormal)) * connectionUCS;
    connectionFromDestination = Matrix3::trans(Matrix3::changeBase(_destination.longitudeTangent,
     _destination.latitudeTangent, _destination.surfaceNormal)) * connectionUCS;
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