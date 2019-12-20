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

#include <vector>
#include "Direction.h"
#include "Point.h"
#include "SharedOps.h"
#include "RGB.h"
#include "Image.h"


const int DIM_TRIANGLE = 2;
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

    
    /**
     * Build a triangle type object without texture
     * @param _p0 is a the first vertex of the triangle
     * @param _pu is a the second vertex of the triangle
     * @param _pv is a the third vertex of the triangle
     * @param _s0 is the coordinate s of the frst vertex of the triangle in the texture image
     * @param _su is the coordinate s of the second vertex of the triangle in the texture image
     * @param _sv is the coordinate s of the third vertex of the triangle in the texture image
     * @param _t0 is the coordinate t of the frst vertex of the triangle in the texture image
     * @param _tu is the coordinate t of the second vertex of the triangle in the texture image
     * @param _tv is the coordinate t of the third vertex of the triangle in the texture image
     * @returns a Triangle type object
     *
    Triangle(const Point _p0, const Point _pu, const Point _pv, Image* _texture,
             const float _s0, const float _su, const float _sv,
             const float _t0, const float _tu, const float _tv);
             */

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
inline void calculateBaricentricCordinates(const Point& origin, const Direction& rayDir, const float& t,const int& i, 
                                           const int& texH, const int & texW, int& rowTex, int& colTex,
                                           Triangle triangleList[])
{
    Point contactPoint, bary;
    float area0uv, areaPuv, areaPv0, x, y;

    // Intersection point in the triangle
    contactPoint = origin + rayDir * t;

    // Calculation of the area of the triangle
    area0uv = dot(triangleList[i].normal, cross((triangleList[i].pu - triangleList[i].p0), 
                 (triangleList[i].pv - triangleList[i].p0)));
    areaPuv = dot(triangleList[i].normal, cross((triangleList[i].pu - contactPoint), 
                 (triangleList[i].pv - contactPoint)));
    areaPv0 = dot(triangleList[i].normal, cross((triangleList[i].pv - contactPoint), 
                 (triangleList[i].p0 - contactPoint)));

    // Obtantion of the barycentric coordinates
    bary.c[0] = areaPuv / area0uv; 
    bary.c[1] = areaPv0 / area0uv;
    bary.c[2] = 1.0f - bary.c[0] - bary.c[1]; 

    // Converting the 3D coordinates of the triangle into 2D 
    x = bary.c[0] * triangleList[i].s0 + bary.c[1] * triangleList[i].su + bary.c[2] * triangleList[i].sv;
    y = bary.c[0] * triangleList[i].t0 + bary.c[1] * triangleList[i].tu + bary.c[2] * triangleList[i].tv;

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
 * @param row is the row index
 * @param col is the col index
 * @param texH is the height of the texture image
 * @param texW is the width of the texture image
 * @param pixelCenter is the size of the pixel 
 * @param distances is the matrix which stores de distances between the rays and the 
 *        pixels of the image
 * @param textureImg is a matrix that contains the texture image
 * @param img is the matrix which contains the image 
 * @param triangleList is the list which stores all the triangles in the scene
 * @param randomRR // TODO
 * @param nearestTriangle is the nearest object found in path intersection
 * @param nearestObject is the code for the nearest object found in path intersection
 */
inline void intersectionRayTriangle(const Point& origin, Point& bary, Direction& rayDir,
                                    const int& texH, const int& texW, const Point& pixelCenter, 
                                    float& minDistance, vector<vector<RGB>>& textureImg,
                                    vector<vector<RGB>>& img, Triangle triangleList[],
                                    Triangle& nearestTriangle, int& nearestObject)
{
    Direction h, s, q;
    float a, b, c, d;
    // Triangle intersection
    for(int i = 0; i < DIM_TRIANGLE; i++){
        h = cross(rayDir, triangleList[i].edge2);
        a = dot(triangleList[i].edge1, h);
        if (a > -LIMIT && a < LIMIT){
            continue;    // This ray is parallel to this triangle.
        }
        b = 1.0/a;
        s = origin - triangleList[i].p0;
        c = b * dot(s, h);
        if (c < 0.0 || c > 1.0){
            continue;
        }
        q = cross(s, triangleList[i].edge1);
        d = b * dot(rayDir, q);
        if (d < 0.0 || c + d > 1.0){
            continue;
        }
        // At this stage we can compute t to find out where the intersection point is on the line.
        float t = b * dot(triangleList[i].edge2, q);

        if (t > LIMIT && t < 1 / LIMIT) // ray intersection
        {
            if(t < minDistance){
                //cout << "op" << i << endl;
                // Its a near intersection and it is saved with the correct emission
                if(triangleList[i].texture == nullptr){
                    minDistance = t;
                }
                else{
                    int rowTex, colTex;
                    calculateBaricentricCordinates(origin, rayDir, t, i, texH, texW, rowTex, colTex, triangleList);
                    // RGB obtained from texture
                    // textureImg[rowTex][colTex];
                    float color[3];
                    color[0] = textureImg[rowTex][colTex].red;
                    color[1] = textureImg[rowTex][colTex].green;
                    color[2] = textureImg[rowTex][colTex].blue;
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
                    triangleList[i].kdr = color[0] * triangleList[i].maxkd / max;
                    triangleList[i].kdg = color[1] * triangleList[i].maxkd / max;
                    triangleList[i].kdb = color[2] * triangleList[i].maxkd / max;
                    triangleList[i].ksr = color[0] * triangleList[i].maxks / max;
                    triangleList[i].ksg = color[1] * triangleList[i].maxks / max;
                    triangleList[i].ksb = color[2] * triangleList[i].maxks / max;
                }

                // Update nearest object
                nearestTriangle = triangleList[i];
                nearestObject =  3;
            }
        }
    }
}

#endif