

#ifndef PIXEL_H
#define PIXEL_H

struct Pixel {
    // Value of the red pixel
    float red_pixel;
    // Value of the green pixel
    float green_pixel;
    // Value of the blue pixel
    float blue_pixel;

    /*
     * Constructor 
     */
    Pixel(const float _red_pixel, const float _green_pixel, const float _blue_pixel);

    Pixel();
};

#endif