#include "../include/ToneMapper.h"

#include <fstream>

ToneMapper::ToneMapper(Image _image){
    image = _image;
}

void ToneMapper::clamping(){
    vector<vector<Pixel>> matrix = image.getImg();
    ofstream f;
    f.open("media/example.ppm");
    f << "P3" << endl;
    f << image.getWidth() << " " << image.getHeight() << endl;
    f << "255" << endl;
    float rc = 255;
    float m = image.getM();
    float factor = rc / m;
    for (int i = 0; i < image.getHeight(); i++){
        for (int j = 0; j < image.getWidth(); j++){
            if(matrix [i][j].red_pixel > 1.f){
                matrix [i][j].red_pixel = 1.f;
            }
            f << matrix [i][j].red_pixel << " ";
            if(matrix [i][j].green_pixel > 1.f){
                matrix [i][j].green_pixel = 1.f;
            }
            f << matrix [i][j].red_pixel << " ";
            if(matrix [i][j].blue_pixel > 1.f){
                matrix [i][j].blue_pixel = 1.f;
            }
            f << matrix [i][j].red_pixel << "     ";
        }
    }
    f.close();
}

void ToneMapper::equalization(){
    vector<vector<Pixel>> matrix = image.getImg();
    ofstream f;
    f.open("media/example.ppm");
    f << "P3" << endl;
    f << image.getWidth() << " " << image.getHeight() << endl;
    f << "255" << endl;
    float rc = 255;
    float m = image.getM();
    float factor = rc / m;
    for (int i = 0; i < image.getHeight(); i++){
        for (int j = 0; j < image.getWidth(); j++){
            matrix [i][j].red_pixel = matrix [i][j].red_pixel * factor * 0.2126;
            f << matrix [i][j].red_pixel << " ";
            matrix [i][j].green_pixel = matrix [i][j].green_pixel * factor * 0.7152;
            f << matrix [i][j].red_pixel << " ";
            matrix [i][j].blue_pixel = matrix [i][j].blue_pixel * factor * 0.0722;
            f << matrix [i][j].red_pixel << "     ";
        }
    }
    f.close();
}

void ToneMapper::equalizeClamp(const float v){

}

void ToneMapper::gammaCurve(){

}

void ToneMapper::clampGamma(const float v){

}