/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 

#ifndef IMAGE_SCENE_LOADER_H
#define IMAGE_SCENE_LOADER_H


#include <vector>
#include <iostream>
#include <cstring>
#include <list>
#include <iomanip>
#include <cfloat>
#include <random>
#include <chrono>
#include <algorithm>
#include "../include/Matrix4.h"
#include "../include/SharedOps.h"
#include "../include/Plane.h"
#include "../include/Sphere.h"
#include "../include/Triangle.h"
#include "../include/Image.h"
#include "../include/ImageLoaderPPM.h"
#include "../include/DirectLight.h"

/**
 * Render a cornell box scene with hard shadows
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * Computes a scene with hard shadows phenomenon
 */
void sceneDefinitionHardShadows(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);



/**
 * Render a cornell box scene with prism objects using triangles
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with prism objects
 */
void sceneDefinitionPrism(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);




/**
 * Render a cornell box scene with prism objects using triangles and multiple lights
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with prism objects using triangles and multiple lights
 */
void sceneDefinitionPrismMultipleLigths(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);



/**
 * Render a cornell box scene with delta materials
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with delta materials
 */
void sceneDefinitionDeltaMaterials(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);



/**
 * Render a cornell box scene with multiple lights
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with multiple lights
 */
void sceneDefinitionMultipleLights(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);



/**
 * Render a cornell box scene with soft shadows
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with soft shadows
 */
void sceneDefinitionSoftShadows(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);




/**
 * Render a cornell box scene with specular materials
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with specular materials
 */
void sceneDefinitionSpecular(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);




/**
 * Render a standard cornell box scene 
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a standard scene with specular materials
 */
void sceneDefinition(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);




/**
 * Render a scene without delimited planes 
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a standard scene without delimited planes
 */
void sceneDefinitionOpenSpace(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);



/**
 * Render a scene with more primitive objects
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a standard scene with more primitive objects
 */
void sceneDefinitionMoreObjects(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]);

#endif