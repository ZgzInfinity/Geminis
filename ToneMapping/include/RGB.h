#ifndef RGB_H
#define RGB_H

struct RGB {
    // Value of the red pixel
    float red;
    // Value of the green pixel
    float green;
    // Value of the blue pixel
    float blue;

    /*
     * Constructor 
     */
    RGB(const float _red, const float _green, const float _blue);

    RGB();
};

#endif