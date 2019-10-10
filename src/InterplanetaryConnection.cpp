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
 * InterplanetaryConnection.cpp implementation file of the InterplanetaryConnection module
 */

#include "../include/InterplanetaryConnection.h"
#include "../include/SharedOps.h"



/**
 * Gets an interplenary conection between the two planets, the origin planet and the destination planet
 * @param _origin is the origin planetary station
 * @param _destination is the destination planetary station
 * @returns an interplenary conection between the two planets, the origin planet and the destination planet
 */
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



/**
 * @Gets if there is a collision against the orgin planet
 * @returns true if and only if there is a collision against the origin planet
 */
bool InterplanetaryConnection::collisionInOrigin(){
    return acos(dot(origin.surfaceNormal, connectionFromOrigin) / 
    (mod(origin.surfaceNormal) * mod(connectionFromOrigin))) > PI / 2; 
}



/**
 * @Gets if there is a collision against the destination planet
 * @returns true if and only if there is a collision against the destination planet
 */
bool InterplanetaryConnection::collisionInDestination(){
    return acos(dot(destination.surfaceNormal, connectionFromDestination) / 
    (mod(destination.surfaceNormal) * mod(connectionFromDestination))) > PI / 2; 
}