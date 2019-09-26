#include "../include/Direction.h"

Direction::Direction(float x, float y, float z) {
    c[0] = x;
    c[1] = y;
    c[2] = z;
    c[3] = 0;
}

Direction Direction::add(Direction d, Direction e){

}

Direction Direction::sub(Direction d, Direction e){

}

Direction Direction::mul(Direction d, float s){

}

Direction Direction::div(Direction d, float s){

}

float Direction::modulus(Direction d){

}

float Direction::modulusMul(Direction d, float s){

}

float Direction::dot(Direction d, Direction e){

}

float Direction::dot(float dmod, float emod, float beta){

}

float Direction::modulusCross(Direction d, Direction e, float beta){

}

float Direction::modulusCross(float dmod, float emod, float beta){

}

Direction Direction::cross(Direction d, Direction e){

}