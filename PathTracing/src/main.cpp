
/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include <iostream>
#include <thread>
#include "../include/PathTracer.h"
#include "../include/ImageSceneLoader.h"

using namespace std;

const int NUMBER_PARAMETERS = 6;
const int NUM_THREADS = 10;


int main(int argc, char* argv[]){
    // Verification of the number of parameters
    if (argc != NUMBER_PARAMETERS){
        // Incorrect
        cerr << "Wrong number of parameters" << endl;
        cerr << "Invoke like pathTracing <rays per pixel> <width of image> <height of image>" 
             << " <scene_code> <path of the file>" << endl;
    }
    else {
        // Correct
        // Definition of the vectors of the space with the origin point
        Direction d_k = Direction(1.65, 0, 0);
        // Direction d_k = Direction(3.5, 0, 0);
        //Point origin = Point(-1.5, 2, 2);
        Point camera = Point(-3, 0, 0);

        // Number of rays per pixel
        int PPP = atoi(argv[1]);

        // Image resolution
        float width = atof(argv[2]);
        float height = atof(argv[3]);
        float pixelSize;
        int rc = 0;

        // Projection plane direction vectors
        Direction leftPP, upPP;
        
        // Calculation of the components of the vectors that form the projection plane
        // The smallest vector is taken as a reference in function of the width and height values
        if (width > height){
            leftPP = Direction(0, 0, - width / height);
            upPP = Direction(0, 1, 0);
            pixelSize = mod(upPP) / (height / 2.f);
        }
        else {
            leftPP = Direction(0, 0, -1);
            upPP = Direction(0, height / width, 0);
            pixelSize = mod(leftPP) / (width / 2.f);
        }

        // Lists with the objects represented in the scene
        list<Plane> planeList;
        list<Sphere> sphereList;
        list<Triangle> triangleList;
        list<DirectLight> directLightList;

        // Load of the file which contains the texture format
        Image brickTexture = loadImagePPM("textures/brick_wall.ppm");
        Image* textureList[2];
        textureList[0] = &brickTexture;

        int sceneNumber = atoi(argv[4]);

        // Chosing scene to render
        switch (sceneNumber){
        case 1:
            // Standard scene
            sceneDefinition(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 2:
            // Scene with multiple lights
            sceneDefinitionMultipleLights(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 3:
            // Scene with hard shadows
            sceneDefinitionHardShadows(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 4:
            // Scene with soft shadows
            sceneDefinitionSoftShadows(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 5:
            // Scene with specular objects
            sceneDefinitionSpecular(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 6:
            // Standard scene
            sceneDefinitionOpenSpace(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 7:
            // Scene without planes
            sceneDefinitionMoreObjects(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 8:
            // Scene with delta materials
            sceneDefinitionDeltaMaterials(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 9:
            // Scene with prism objects and multiple point lights
            sceneDefinitionPrismMultipleLigths(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        case 10:
            // Scene with prism objects
            sceneDefinitionPrism(planeList, sphereList, triangleList, directLightList, textureList);
            break;
        default:
            // Incorrect scene
            cerr << "Incorrect code of scene" << endl;
        }

        // Matrix of the image that is going to be built
        vector<vector<RGB>> img(height, vector<RGB>(width));
        
        // Vector of threads
        thread P[NUM_THREADS];

        // Number of rows computed by each thread
        int part = height / NUM_THREADS;
        // Index of the image 
        int i1, i2;

        // Call path tracing algorithm
        for (int i = 0; i < NUM_THREADS; i++){
            // A thread computes path tracing algorithm in a part of the scene
            i1 = part * i;
            i2 = i1 + part - 1;
            P[i] = thread(&pathTracer, ref(PPP), ref(width), height, i1, i2, ref(img), ref(planeList), 
                                       ref(sphereList), ref(triangleList), ref(directLightList),
                                       ref(camera), ref(d_k), ref(leftPP), ref(upPP), ref(pixelSize), ref(rc));
        }

        // Wait until all threads have finished
        for (int i = 0; i < NUM_THREADS; i++){
            P[i].join();
        }

        // Creation of the image and saving in a ppm format file
        Image image = Image(true, width, height, rc, rc, img);
        image.printImage(argv[5]);
        cout << endl;
    }
    // Final execution of the programm
    return 0;
}