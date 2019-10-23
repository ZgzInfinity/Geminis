#ifndef LAB_H
#define LAB_H

struct LAB {
    // Value of the red pixel
    float l;
    // Value of the green pixel
    float a;
    // Value of the blue pixel
    float b;

    /*
     * Constructor 
     */
    LAB(const float _l, const float _a, const float _b);

    LAB();
};

#endif