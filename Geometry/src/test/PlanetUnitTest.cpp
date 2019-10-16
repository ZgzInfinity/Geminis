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
 * Planet.cpp implementation file of Planet module
 */

#include "../../include/test/PlanetUnitTest.h"



/**
 * test if a planet is correct based on its radio
 * @param p is the planet to validate 
 * @param expectedRadius is the expected radius od the planet
 */
void testPlanet(Planet p, float expectedRadius){
    assert(p.radius == expectedRadius);
}