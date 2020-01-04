#include "../include/Photon.h"

Photon::Photon(){}

Photon::Photon(RGB _flux, Point _location, Direction _sourceDir){
    flux = _flux;
    location = _location;
    sourceDir = _sourceDir;
}