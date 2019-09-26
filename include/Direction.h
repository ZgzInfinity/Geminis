#ifndef DIRECTION_H
#define DIRECTION_H

struct Direction {
    float c[4];
    Direction(float x, float y, float z);
    Direction();
};

Direction add(Direction d, Direction e);
Direction sub(Direction d, Direction e);
Direction mul(Direction d, float s);
Direction div(Direction d, float s);
float mod(Direction d);
float modMul(Direction d, float s);
float dot(Direction d, Direction e);
float dot(float dmod, float emod, float beta);
float modCross(Direction d, Direction e, float beta);
float modCross(float dmod, float emod, float beta);
Direction cross(Direction d, Direction e);

#endif /* DIRECTION_H */