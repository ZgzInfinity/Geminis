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
 * Planet.h interface file of Planet module
 */

#ifndef PLANET_UNIT_TEST_H
#define PLANET_UNIT_TEST_H

#include <cassert>
#include <iostream>
#include "../Direction.h"
#include "../Point.h"
#include "../SharedOps.h"
#include "../Planet.h"



/**
 * test if a planet is correct based on its radio
 * @param p is the planet to validate 
 * @param expectedRadius is the expected radius od the planet
 */
void testPlanet(Planet p, float expectedRadius);


#endif 