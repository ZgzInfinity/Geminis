/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include "../include/ImageSceneLoader.h"



/**
 * Render a cornell box scene with hard shadows
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * Computes a scene with hard shadows phenomenon
 */
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

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
}



/**
 * Render a cornell box scene with prism objects using triangles
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with prism objects
 */
void sceneDefinitionPrism(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
     // Definition of the planes which are going to appear in the scene 
    Plane leftWall = Plane(Direction(0, 0, 1), 2, 0.9, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(leftWall);
    Plane rightWall = Plane(Direction(0, 0,-1), 2, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
    planeList.push_back(rightWall);
    // Plane ceiling = Plane(Direction(0, -1, 0), 2, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0, 0, 1);
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
    Sphere rightSphere = Sphere(Point(2.25, -0.60, 1), 0.4, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(1.75, -1, 0.5), Point(1.75, -1, 1.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(1.75, -1, 1.5), Point(2.75, -1, 1.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t2);
    // Definition of the triangles which are going to appear in the scene 
    Triangle t3 = Triangle(Point(1.75, -2, 0.5), Point(1.75, -2, 1.5), 
                           Point(1.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t3);
    Triangle t4 = Triangle(Point(1.75, -2, 1.5), Point(1.75, -1, 1.5), 
                           Point(1.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t4);
    // Definition of the triangles which are going to appear in the scene 
    Triangle t5 = Triangle(Point(2.75, -2, 0.5), Point(1.75, -2, 0.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t5);
    Triangle t6 = Triangle(Point(1.75, -2, 0.5), Point(1.75, -1, 0.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t6);
    // Definition of the triangles which are going to appear in the scene 
    Triangle t7 = Triangle(Point(1.75, -2, 1.5), Point(2.75, -2, 1.5), 
                           Point(1.75, -1, 1.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t7);
    Triangle t8 = Triangle(Point(2.75, -2, 1.5), Point(2.75, -1, 1.5), 
                           Point(1.75, -1, 1.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t8);
}



/**
 * Render a cornell box scene with prism objects using triangles and multiple lights
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with prism objects using triangles and multiple lights
 */
void sceneDefinitionPrismMultipleLigths(list<Plane>& planeList, list<Sphere>& sphereList, list<Triangle>& triangleList, list<DirectLight>& directLightList, Image* textureList[]){
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
    Sphere rightSphere = Sphere(Point(2.25, -0.60, 1), 0.4, 0.0, 0.0, 0.0, 0, 0, 0, 0.0, 0.20, 0.70, 1.5);
    sphereList.push_back(rightSphere);

    // Definition of the triangles which are going to appear in the scene 
    Triangle t1 = Triangle(Point(1.75, -1, 0.5), Point(1.75, -1, 1.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t1);
    Triangle t2 = Triangle(Point(1.75, -1, 1.5), Point(2.75, -1, 1.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t2);
    // Definition of the triangles which are going to appear in the scene 
    Triangle t3 = Triangle(Point(1.75, -2, 0.5), Point(1.75, -2, 1.5), 
                           Point(1.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t3);
    Triangle t4 = Triangle(Point(1.75, -2, 1.5), Point(1.75, -1, 1.5), 
                           Point(1.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t4);
    // Definition of the triangles which are going to appear in the scene 
    Triangle t5 = Triangle(Point(2.75, -2, 0.5), Point(1.75, -2, 0.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t5);
    Triangle t6 = Triangle(Point(1.75, -2, 0.5), Point(1.75, -1, 0.5), 
                           Point(2.75, -1, 0.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t6);
    // Definition of the triangles which are going to appear in the scene 
    Triangle t7 = Triangle(Point(1.75, -2, 1.5), Point(2.75, -2, 1.5), 
                           Point(1.75, -1, 1.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t7);
    Triangle t8 = Triangle(Point(2.75, -2, 1.5), Point(2.75, -1, 1.5), 
                           Point(1.75, -1, 1.5), 0, 0.6, 0.9, 0, 0, 0, 1, 0, 0, 1);
    triangleList.push_back(t8);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0.5), RGB(100, 100, 100));
    directLightList.push_back(d1);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d2 = DirectLight(Point(2.5, 1, -0.5), RGB(100, 0, 0));
    directLightList.push_back(d2);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d3 = DirectLight(Point(3, 1, 0.5), RGB(0, 100, 0));
    directLightList.push_back(d3);

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d4 = DirectLight(Point(3, 1, -0.5), RGB(0, 0, 100));
    directLightList.push_back(d4);
}



/**
 * Render a cornell box scene with delta materials
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with delta materials
 */
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



/**
 * Render a cornell box scene with multiple lights
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with multiple lights
 */
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



/**
 * Render a cornell box scene with soft shadows
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with soft shadows
 */
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

}



/**
 * Render a cornell box scene with specular materials
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a scene with specular materials
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

    // Definition of the direct lights which are going to appear in the scene
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
}



/**
 * Render a standard cornell box scene 
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a standard scene with specular materials
 */
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



/**
 * Render a scene without delimited planes 
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a standard scene without delimited planes
 */
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



/**
 * Render a scene with more primitive objects
 * @param planetList is a list which stores the planes of the scene
 * @param sphereList is a list which stores the spheres of the scene
 * @param triangleList is a list which stores the triangles of the scene
 * @param directLightList is a list which stores the direct lights of the scene
 * @param textureList is a list which stores the textures of the image
 * Computes a standard scene with more primitive objects
 */
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

    // Definition of the direct lights which are going to appear in the scene 
    DirectLight d1 = DirectLight(Point(2.5, 1, 0), RGB(100, 100, 100));
    directLightList.push_back(d1);
}