#include <cmath>
#include "../include/Direction.h"

Direction::Direction(float x, float y, float z) {
    c[0] = x;
    c[1] = y;
    c[2] = z;
    c[3] = 0;
}

Direction::Direction(){}

Direction add(Direction d, Direction e){
    return Direction(d.c[0] + e.c[0], d.c[1] + e.c[1], d.c[2] + e.c[2]);
}

Direction sub(Direction d, Direction e){
    return Direction(d.c[0] - e.c[0], d.c[1] - e.c[1], d.c[2] - e.c[2]);
}

Direction mul(Direction d, float s){
    return Direction(d.c[0] * s, d.c[1] * s, d.c[2] * s);
}

Direction div(Direction d, float s){
    if(s != 0){
        return Direction(d.c[0] / s, d.c[1] / s, d.c[2] / s);
    }
    else{
        return Direction(-1, -1, -1); // Error, can't divide by 0
    }
}

float mod(Direction d){
    return sqrt(d.c[0] * d.c[0] + d.c[1] * d.c[1] + d.c[2] * d.c[2]);
}

float modMul(Direction d, float s){
    return mod(d) * s;
}

float dot(Direction d, Direction e){
    return d.c[0] * e.c[0] + d.c[1] * e.c[1] + d.c[2] * e.c[2];
}

float dot(float dmod, float emod, float beta){
    return dmod * emod * cos(beta);
}

float modCross(Direction d, Direction e, float beta){
    return mod(d) * mod(e) * sin(beta);
}

float modCross(float dmod, float emod, float beta){
    return dmod * emod * sin(beta);
}

Direction cross(Direction d, Direction e){
    return Direction(d.c[1] * e.c[2] - d.c[2] * e.c[1],
        d.c[2] * e.c[0] - d.c[0] * e.c[2], d.c[0] * e.c[1] - d.c[1] * e.c[0]);
}

