
/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include "../include/PathTracer.h"


using namespace std;

const int NUMBER_PARAMETERS = 5;

void sceneDefinitionHardShadows(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(background);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6,  0.7, 0.7, 0.7, 0.2, 0.2, 0.2, 1, 0, 0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    /*
    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(49.99, -7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, -7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 0, 0, 0 , 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(49.99, 7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, 7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 1, 1, 0, 1);
    triangleList.push_back(t2);
    */

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
}

void sceneDefinitionSquareLight(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(background);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6,  0.7, 0.7, 0.7, 0.2, 0.2, 0.2, 1, 0, 0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    
    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(1.5, 1.999, -1), Point(1.5, 1.999, 1), 
                           Point(3.5, 1.999, -1), RGB(500, 500, 500));
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(1.5, 1.999, 1), Point(3.5, 1.999, 1), 
                           Point(3.5, 1.999, -1), RGB(500, 500, 500));
    triangleList.push_back(t2);
}

void sceneDefinitionDeltaMaterials(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0, 1);
    planeList.push_back(background);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.9, 0.0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.0, 0.9, 1.5);
    sphereList.push_back(rightSphere);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0.5), RGB(100, 100, 100));
    directLightList.push_back(d1);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d2 = DirectLight(Point(3, 1, -0.5), RGB(100, 0, 0));
    directLightList.push_back(d2);


    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d3 = DirectLight(Point(1, 1, 0.5), RGB(0, 100, 0));
    directLightList.push_back(d3);


    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d4 = DirectLight(Point(4, 1, -0.5), RGB(0, 0, 100));
    directLightList.push_back(d4);
}



void sceneDefinitionMultipleLights(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(background);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6,  0.7, 0.7, 0.7, 0.2, 0.2, 0.2, 1, 0, 0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    /*
    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(49.99, -7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, -7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 0, 0, 0 , 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(49.99, 7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, 7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 1, 1, 0, 1);
    triangleList.push_back(t2);
    */

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0.5), RGB(100, 100, 100));
    directLightList.push_back(d1);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d2 = DirectLight(Point(3, 1, -0.5), RGB(100, 0, 0));
    directLightList.push_back(d2);


    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d3 = DirectLight(Point(1, 1, 0.5), RGB(0, 100, 0));
    directLightList.push_back(d3);


    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d4 = DirectLight(Point(4, 1, -0.5), RGB(0, 0, 100));
    directLightList.push_back(d4);
}


void sceneDefinitionSoftShadows(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, RGB(255, 255, 255));
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(background);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6,  0.7, 0.7, 0.7, 0.2, 0.2, 0.2, 1, 0, 0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    /*
    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(49.99, -7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, -7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 0, 0, 0 , 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(49.99, 7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, 7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 1, 1, 0, 1);
    triangleList.push_back(t2);
    */

    // Definition of the direct lights which are going to appear in the scene
    /*
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
    */
}
/*
void sceneDefinitionBrickWall(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, RGB(255, 255, 255));
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(floor);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6,  0.7, 0.7, 0.7, 0.2, 0.2, 0.2, 1, 0, 0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(5, -2, -2), Point(5, -2, 2), 
                            Point(5, 2, -2), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                                0, 1, 0, 0, 0 , 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(5, 2, -2), Point(5, -2, 2), 
                            Point(5, 2, 2), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                            0, 1, 1, 1, 0, 1);
    triangleList.push_back(t2);
}
*/
void sceneDefinitionSpecular(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0, 1);
    planeList.push_back(background);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6,  0.2, 0.2, 0.2, 0.7, 0.7, 0.7, 2, 0, 0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    /*
    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(49.99, -7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, -7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 0, 0, 0 , 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(49.99, 7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, 7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 1, 1, 0, 1);
    triangleList.push_back(t2);
    */

    // Definition of the direct lights which are going to appear in the scene
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
}

void sceneDefinition(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 7, 0.8, 0.0, 0, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 7, 0.0, 0.8, 0.0, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
    planeList.push_back(rightWall);
    // Plane ceiling = Plane(Direction(0, -1, 0), 7, RGB(255, 255, 255));
    Plane ceiling = Plane(Direction(0, -1, 0), 7, RGB(255, 255, 255));
    planeList.push_back(ceiling);
    // Plane floor = Plane(Direction(0, 1, 0), 7, 0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
    Plane floor = Plane(Direction(0, 1, 0), 7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 50, 0, 0, 0, 0, 0, 0, 0, 0.9, 0, 1);
    planeList.push_back(background);

    Plane behind = Plane(Direction(1, 0, 0), 10, 0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 0.1, 0, 0, 1);
    planeList.push_back(behind);



    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(40, -5, -3), 2,  0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 1, 0, 0, 1);
    Sphere rightSphere = Sphere(Point(32, -5, 3), 2, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.0, 0.9, 1.5);
    sphereList.push_back(leftSphere);
    sphereList.push_back(rightSphere);

    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(49.99, -7, -7), Point(49.99, -7, 7), 
                            Point(49.99, 7, -7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                                0, 1, 0, 0, 0 , 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(49.99, 7, -7), Point(49.99, -7, 7), 
                            Point(49.99, 7, 7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                            0, 1, 1, 1, 0, 1);
    triangleList.push_back(t2);
}

void sceneDefinitionOpenSpace(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){

    // Definition of the spheres which are going to appear in the scene 
    Sphere leftSphere = Sphere(Point(3, -1.40, -1), 0.6,  0.7, 0.7, 0.7, 0.2, 0.2, 0.2, 1, 0, 0, 1);
    sphereList.push_back(leftSphere);
    Sphere rightSphere = Sphere(Point(2, -1.40, 1), 0.6, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
}

void sceneDefinitionMoreObjects(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    Plane ceiling = Plane(Direction(0, -1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(ceiling);
    Plane floor = Plane(Direction(0, 1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(floor);
    Plane background = Plane(Direction(-1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(background);
    Plane behind = Plane(Direction(1, 0, 0), 5, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(behind);
    

    // Definition of the spheres which are going to appear in the scene 
    Sphere sphere1 = Sphere(Point(3, -1.40, -1), 0.2,  0.7, 0.7, 0.7, 0.2, 0.2, 0.2, 1, 0, 0, 1);
    sphereList.push_back(sphere1);
    Sphere sphere2 = Sphere(Point(2.5, -1.40, 1), 0.2, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(sphere2);
    Sphere sphere3 = Sphere(Point(2.5, -1.40, 0), 0.2, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(sphere3);
    Sphere sphere4 = Sphere(Point(2.5, -1.40, -1.5), 0.2, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(sphere4);
    Sphere sphere5 = Sphere(Point(1.5, -1.40, 1.5), 0.2, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(sphere5);
    Sphere sphere6 = Sphere(Point(1.5, -1.40, 1.5), 0.2, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(sphere6);
    Sphere sphere7 = Sphere(Point(1.5, -1.40, -1.5), 0.2, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(sphere7);

    /*
    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(49.99, -7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, -7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 0, 0, 0 , 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(49.99, 7, -7), Point(49.99, -7, 7), 
                           Point(49.99, 7, 7), textureList[0], 0.8, 0.1, 0.1, 0, 0, 1,
                           0, 1, 1, 1, 0, 1);
    triangleList.push_back(t2);
    */

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
}





// http://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/

// https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm

// https://gamedev.stackexchange.com/questions/23743/whats-the-most-efficient-way-to-find-barycentric-coordinates

int main(int argc, char* argv[]){
    // Verification of the number of parameters
    if (argc != NUMBER_PARAMETERS){
        // Incorrect
        cerr << "Wrong number of parameters" << endl;
        cerr << "Invoke like pathTracing <rays per pixel> <width of image> <height of image>" 
             << "path of the file" << endl;
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
        Image* textureList[1];
        textureList[0] = &brickTexture;

        //sceneDefinition(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionHardShadows(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionSoftShadows(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionMultipleLights(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionHardShadows(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionSoftShadows(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionSpecular(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionBrickWall(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinition(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionOpenSpace(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionMoreObjects(planeList, sphereList, triangleList, directLightList, textureList);
        // sceneDefinitionDeltaMaterials(planeList, sphereList, triangleList, directLightList, textureList);
        sceneDefinitionSquareLight(planeList, sphereList, triangleList, directLightList, textureList);

        // Matrix of the image that is going to be built
        vector<vector<RGB>> img(height, vector<RGB>(width));
        
        // Call path tracing algorithm
        pathTracer(PPP, width, height, img, planeList, sphereList, triangleList, directLightList,
                   camera, d_k, leftPP, upPP, pixelSize, rc);

        // Creation of the image and saving in a ppm format file
        Image image = Image(true, width, height, rc, rc, img);
        image.printImage(argv[4]);
    }
    // Final execution of the programm
    return 0;
}