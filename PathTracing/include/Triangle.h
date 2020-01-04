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
 * Triangle.h interface file of Triangle module
 */


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <list>
#include <vector>
#include "Direction.h"
#include "Point.h"
#include "SharedOps.h"
#include "RGB.h"
#include "Image.h"


const float LIMIT = 0.0005;


/*
 * Definition of data type Plane
 */
struct Triangle {
    // The normal direction vector 
    Direction normal, edge1, edge2;
    // Distance between the plane and the origin point
    // float distance2origin;
    // Color emission ray
    RGB emission;

    // Vertexes of the triangle
    Point p0, pu, pv;

    // Pointer to texture image
    Image* texture;

    // Texture coordinates
    float s0, su, sv, t0, tu, tv;

    // is it a light source?
    bool emitsLight;

    // Material properties
    // Diffuse coefficient by RGB channel
    float kdr, kdg, kdb, maxkd;
    // Specular coefficient by RGB channel
    float ksr, ksg, ksb, shininess, maxks;
    // Perfect specular (k)
    float kps;
    // Refraction (k, refraction index)
    float krf, ri;



    /**
     * Default builder without parameters
     */
    Triangle();



    /**
     *Build a triangle type object without texture
     * @param _p0 is a the first vertex of the triangle
     * @param _pu is a the second vertex of the triangle
     * @param _pv is a the third vertex of the triangle
     * @param _emission is a color emission ray
     * @returns a Triangle type object
     */
    Triangle(const Point _p0, const Point _pu, const Point _pv, const RGB _emission);



    Triangle(const Point _p0, const Point _pu, const Point _pv,  float _kdr, float _kdg, float _kdb,
             float _ksr, float _ksg, float _ksb, float _shininess, float _kps, float _krf, float _ri);


    Triangle(const Point _p0, const Point _pu, const Point _pv, Image* _texture,
                   float _maxkd, float _maxks, float _shininess, float _kps,
                   float _krf, float _ri,
                   const float _s0, const float _su, const float _sv,
                   const float _t0, const float _tu, const float _tv);

};



/**
 * Calculates the barycentric coordinates and obtains the coordinates of the 
 * texture image in 2D in order to obtain the texture color which is going to be printed in 
 * these coordinates
 * @param origin is the point of the space where the camera is located
 * @param rayDir is  the direction of the ray thrown from the camera
 * @param t is the row index
 * @param i index of the triangle with which you are checking whether or not there is an intersection
 * @param texH is the height of the texture image
 * @param texW is the width of the texture image
 * @param rowTex is the row index in the texture image
 * @param colTex is the column index in the texture image
 * @param triangleList is the list which stores all the triangle in the scene
 * @param randomRR is the random value for russian roulette
 */
inline void calculateBaricentricCordinates(const Point& origin, const Direction& rayDir, const float& t,const Triangle& triangle, 
                                           const int& texH, const int & texW, int& rowTex, int& colTex)
{
    Point contactPoint, bary;
    float area0uv, areaPuv, areaPv0, x, y;

    // Intersection point in the triangle
    contactPoint = origin + rayDir * t;

    // Calculation of the area of the triangle
    area0uv = dot(triangle.normal, cross((triangle.pu - triangle.p0), 
                 (triangle.pv - triangle.p0)));
    areaPuv = dot(triangle.normal, cross((triangle.pu - contactPoint), 
                 (triangle.pv - contactPoint)));
    areaPv0 = dot(triangle.normal, cross((triangle.pv - contactPoint), 
                 (triangle.p0 - contactPoint)));

    // Obtantion of the barycentric coordinates
    bary.c[0] = areaPuv / area0uv; 
    bary.c[1] = areaPv0 / area0uv;
    bary.c[2] = 1.0f - bary.c[0] - bary.c[1]; 

    // Converting the 3D coordinates of the triangle into 2D 
    x = bary.c[0] * triangle.s0 + bary.c[1] * triangle.su + bary.c[2] * triangle.sv;
    y = bary.c[0] * triangle.t0 + bary.c[1] * triangle.tu + bary.c[2] * triangle.tv;

    // Coordinates in the texture image
    rowTex = int(((texH - 1) * (1.f - y)));
    colTex = int((texW - 1) * x);
}



/**
 * Calculates all the intersections between the rays thrown by the camera 
 * and the triangles of the scene
 * @param origin is the point of the space where the camera is located
 * @param bary is the point where the ray intersects a triangle
 * @param rayDir is  the direction of the ray thrown from the camera
 * @param pixelCenter is the size of the pixel 
 * @param triangleList is the list which stores all the triangles in the scene
 * @param nearestTriangle is the nearest object found in path intersection
 * @param nearestObject is the code for the nearest object found in path intersection
 */
inline void intersectionRayTriangle(const Point& origin, Point& bary, Direction& rayDir,
                                    const Point& pixelCenter, float& minDistance,
                                    list<Triangle>& triangleList, Triangle& nearestTriangle,
                                    int& nearestObject)
{
    Direction h, s, q;
    float a, b, c, d;
    // Triangle intersection
    for(auto& triangle : triangleList){
        h = cross(rayDir, triangle.edge2);
        a = dot(triangle.edge1, h);
        if (a > -LIMIT && a < LIMIT){
            continue;    // This ray is parallel to this triangle.
        }
        b = 1.0/a;
        s = origin - triangle.p0;
        c = b * dot(s, h);
        if (c < 0.0 || c > 1.0){
            continue;
        }
        q = cross(s, triangle.edge1);
        d = b * dot(rayDir, q);
        if (d < 0.0 || c + d > 1.0){
            continue;
        }
        // At this stage we can compute t to find out where the intersection point is on the line.
        float t = b * dot(triangle.edge2, q);

        if (t > LIMIT && t < 1 / LIMIT) // ray intersection
        {
            if(t < minDistance){
                // Its a near intersection and it is saved with the correct emission
                if(triangle.texture == nullptr){
                    minDistance = t;
                }
                else{
                    // Dimensions of the texture image
                    int texH = triangle.texture->getHeight();
                    int texW = triangle.texture->getWidth();


                    int rowTex, colTex;
                    calculateBaricentricCordinates(origin, rayDir, t, triangle, texH, texW, rowTex, colTex);
                    // RGB obtained from texture
                    float color[3];
                    color[0] = triangle.texture->img[rowTex][colTex].red;
                    color[1] = triangle.texture->img[rowTex][colTex].green;
                    color[2] = triangle.texture->img[rowTex][colTex].blue;
                    float max;
                    if(color[0] > color[1]){
                        max = color[0];
                    }
                    else{
                        max = color[1];
                    }
                    if(max < color[2]){
                        max = color[2];
                    }
                    // Assign coefficients dynamically
                    triangle.kdr = color[0] * triangle.maxkd / max;
                    triangle.kdg = color[1] * triangle.maxkd / max;
                    triangle.kdb = color[2] * triangle.maxkd / max;
                    triangle.ksr = color[0] * triangle.maxks / max;
                    triangle.ksg = color[1] * triangle.maxks / max;
                    triangle.ksb = color[2] * triangle.maxks / max;
                }

                // Update nearest object
                nearestTriangle = triangle;
                nearestObject =  3;
            }
        }
    }
}



inline void updateNearestTriangle(Triangle& nearestTriangle, float& productR, float& productG, float& productB,
            bool& pathFinished, float& diffuseUB, float& specularUB, float& perfectSpecularUB,
            float& refractionUB, Point& intersection, Point& origin, Direction& rayDir, float& minDistance,
            Direction& normal, float& random1, float& random2, Direction& x, Direction& y, float& kdr,
            float& kdg, float& kdb, float& ksr, float& ksg, float& ksb, float& shininess, float& ri)
{
    if(nearestTriangle.emitsLight){
        productR *= nearestTriangle.emission.red;
        productG *= nearestTriangle.emission.green;
        productB *= nearestTriangle.emission.blue;
        // Path finished (reach emitting object)
        pathFinished = true;
    }
    else{
        diffuseUB = nearestTriangle.maxkd;
        specularUB = diffuseUB + nearestTriangle.maxks;
        perfectSpecularUB = specularUB + nearestTriangle.kps;
        refractionUB = perfectSpecularUB + nearestTriangle.krf;
        intersection = origin + (rayDir * minDistance);
        normal = nearestTriangle.normal / mod(nearestTriangle.normal);
        x = nearestTriangle.edge1 / mod(nearestTriangle.edge1);
        y = cross(normal, x);
        kdr = nearestTriangle.kdr;
        kdg = nearestTriangle.kdg;
        kdb = nearestTriangle.kdb;
        ksr = nearestTriangle.ksr;
        ksg = nearestTriangle.ksg;
        ksb = nearestTriangle.ksb;
        shininess = nearestTriangle.shininess;
        ri = nearestTriangle.ri;
    }
}

#endif