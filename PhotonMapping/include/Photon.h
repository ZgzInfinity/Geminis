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
 * Photon.h interface file of the Photon module
 */

#ifndef PHOTON_H
#define PHOTON_H

#include "RGB.h"
#include "Point.h"
#include "Direction.h"

struct Photon{
    RGB flux;
    Point location;
    Direction sourceDir;


    Photon();

    Photon(RGB _flux, Point _location, Direction _sourceDir);

};

#endif