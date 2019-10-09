#include "../include/InterplanetaryConnection.h"
#include "../include/SharedOps.h"


InterplanetaryConnection::InterplanetaryConnection(PlanetaryStation _origin,
     PlanetaryStation _destination){
    origin = _origin;
    destination = _destination;
    connectionUCS = _destination.stationUCS -  _origin.stationUCS;
    cout << "connectionUCS " << connectionUCS.toString() << endl;
    connectionFromOrigin = Matrix3::trans(Matrix3::changeBase(_origin.longitudeTangent, _origin.surfaceNormal,
     _origin.latitudeTangent)) * connectionUCS;
    cout << "connectionFromOrigin " << connectionFromOrigin.toString() << endl;
    connectionFromDestination = Matrix3::trans(Matrix3::changeBase(_destination.longitudeTangent,
     _destination.surfaceNormal, _destination.latitudeTangent)) * connectionUCS;
    cout << "connectionFromDestination " << connectionFromDestination.toString() << endl;
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