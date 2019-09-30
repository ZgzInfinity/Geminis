#include "../include/InterplanetaryConnection.h"


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
    connectionFromDestination = mul(t, connectionUCS);
}

/**
 * Default builder without parameters
 */
InterplanetaryConnection::InterplanetaryConnection(){}