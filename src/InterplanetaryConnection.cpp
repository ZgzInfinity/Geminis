#include "../include/InterplanetaryConnection.h"
#include "../include/SharedOps.h"


InterplanetaryConnection::InterplanetaryConnection(PlanetaryStation _origin,
     PlanetaryStation _destination){
    origin = _origin;
    destination = _destination;
    connectionUCS = _origin.stationUCS -  _destination.stationUCS;
    Matrix3 t = t.reverse(t.changeBase(_origin.longitudeTangent, _origin.latitudeTangent, _origin.surfaceNormal));
    connectionFromOrigin = t * connectionUCS;
    t = t.reverse(t.changeBase(_destination.longitudeTangent, _destination.latitudeTangent, _destination.surfaceNormal));
    connectionFromDestination = t * connectionUCS;
    /*
    Matrix3 t;
    t.matrixChangeOfBase(_origin.longitudeTangent, _origin.latitudeTangent,
     _origin.surfaceNormal, _origin.stationUCS);
    connectionFromOrigin = t * connectionUCS;
    t.matrixChangeOfBase(_destination.longitudeTangent, _destination.latitudeTangent,
     _destination.surfaceNormal, _destination.stationUCS);
    connectionFromDestination = t * connectionUCS;
    */
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