/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 

#ifndef PHOTON_MAPPER_H
#define PHOTON_MAPPER_H

#include <list>
#include <random>
#include <chrono>
#include "Photon.h"
#include "DirectLight.h"

const int numRays = 100;


inline void photonMapper(list<Photon>& photonList, list<DirectLight>& directLightList){

    // Generation random numbers
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // Aleatory number for the rays and russian roulette
    float xCoord, yCoord, zCoord;
    Direction rayDir;
    
    for(const auto& directLight : directLightList){
        for(int i = 0; i < numRays; i++){
            // Calculate new ray from light source

            // Generation of the random values
            xCoord = uniform_real_distribution<float>(-1, 1)(rng);
            yCoord = uniform_real_distribution<float>(-1, 1)(rng);
            zCoord = uniform_real_distribution<float>(-1, 1)(rng);

            Point randomPoint = Point(directLight.location.c[0] + xCoord,
                                      directLight.location.c[1] + yCoord,
                                      directLight.location.c[2] + zCoord);
            rayDir = randomPoint - directLight.location;

            if(mod(rayDir) > 1.f){
                // Out of the box (invalid ray)
                i--;
                continue;
            }

            // Normalize rayDir
            rayDir = rayDir / mod(rayDir);
            
            




        }
    }


}


#endif