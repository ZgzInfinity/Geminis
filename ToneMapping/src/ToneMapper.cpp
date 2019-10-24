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
  * ToneMapper.cpp implementation file of ToneMapper module
  */

#include <fstream>
#include <cmath>
#include "../include/ToneMapper.h"



/*
 * Constructor of the ToneMapper
 */
ToneMapper::ToneMapper(Image _image){
    image = _image;
}



// https://stackoverflow.com/questions/7880264/convert-lab-color-to-rgb
// http://www.easyrgb.com/index.php?X=MATH&H=01#text1


/*
 * Builds an image with lab format equivalent to the image in rgb format
 * @param rgb is the image in rgb format
 * @param m is the real maximun value of the image
 * @returns an image with lab format equivalent to the image in rgb format
 */
LAB rgb2lab(RGB rgb, float m){

    float var_R = rgb.red / m;
    float var_G = rgb.green / m;
    float var_B = rgb.blue / m;

    if ( var_R > 0.04045 ) var_R = pow( (( var_R + 0.055 ) / 1.055 ), 2.4 );
    else                   var_R = var_R / 12.92;
    if ( var_G > 0.04045 ) var_G = pow( ( ( var_G + 0.055 ) / 1.055 ), 2.4);
    else                   var_G = var_G / 12.92;
    if ( var_B > 0.04045 ) var_B = pow( ( ( var_B + 0.055 ) / 1.055 ), 2.4);
    else                   var_B = var_B / 12.92;

    var_R = var_R * 100.;
    var_G = var_G * 100.;
    var_B = var_B * 100.;

    float X = var_R * 0.4124 + var_G * 0.3576 + var_B * 0.1805;
    float Y = var_R * 0.2126 + var_G * 0.7152 + var_B * 0.0722;
    float Z = var_R * 0.0193 + var_G * 0.1192 + var_B * 0.9505;


    float var_X = X / 95.047 ;
    float var_Y = Y / 100.000;          
    float var_Z = Z / 108.883;          

    if ( var_X > 0.008856 ) var_X = pow(var_X , ( 1./3. ) );
    else                    var_X = ( 7.787 * var_X ) + ( 16. / 116. );
    if ( var_Y > 0.008856 ) var_Y = pow(var_Y , ( 1./3. ));
    else                    var_Y = ( 7.787 * var_Y ) + ( 16. / 116. );
    if ( var_Z > 0.008856 ) var_Z = pow(var_Z , ( 1./3. ));
    else                    var_Z = ( 7.787 * var_Z ) + ( 16. / 116. );

    return LAB(( 116. * var_Y ) - 16., 500. * ( var_X - var_Y ), 200. * ( var_Y - var_Z ));
}



// https://stackoverflow.com/questions/7880264/convert-lab-color-to-rgb
// http://www.easyrgb.com/index.php?X=MATH&H=01#text1


/*
 * Builds an image with rgb format equivalent to the image in lab format
 * @param rgb is the image in rgb format
 * @param m is the real maximun value of the image
 * @returns an image with rgb format equivalent to the image in rgb format
 */
RGB lab2rgb(LAB lab){

    float var_Y = ( lab.l + 16. ) / 116.;
    float var_X = lab.a / 500. + var_Y;
    float var_Z = var_Y - lab.b / 200.;

    if ( pow(var_Y,3) > 0.008856 ) var_Y = pow(var_Y,3);
    else                      var_Y = ( var_Y - 16. / 116. ) / 7.787;
    if ( pow(var_X,3) > 0.008856 ) var_X = pow(var_X,3);
    else                      var_X = ( var_X - 16. / 116. ) / 7.787;
    if ( pow(var_Z,3) > 0.008856 ) var_Z = pow(var_Z,3);
    else                      var_Z = ( var_Z - 16. / 116. ) / 7.787;

    float X = 95.047 * var_X ;    
    float Y = 100.000 * var_Y  ;   
    float Z = 108.883 * var_Z ;    


    var_X = X / 100. ;       
    var_Y = Y / 100. ;       
    var_Z = Z / 100. ;      

    float var_R = var_X *  3.2406 + var_Y * -1.5372 + var_Z * -0.4986;
    float var_G = var_X * -0.9689 + var_Y *  1.8758 + var_Z *  0.0415;
    float var_B = var_X *  0.0557 + var_Y * -0.2040 + var_Z *  1.0570;

    if ( var_R > 0.0031308 ) var_R = 1.055 * pow(var_R , ( 1 / 2.4 ))  - 0.055;
    else                     var_R = 12.92 * var_R;
    if ( var_G > 0.0031308 ) var_G = 1.055 * pow(var_G , ( 1 / 2.4 ) )  - 0.055;
    else                     var_G = 12.92 * var_G;
    if ( var_B > 0.0031308 ) var_B = 1.055 * pow( var_B , ( 1 / 2.4 ) ) - 0.055;
    else                     var_B = 12.92 * var_B;

    return RGB(var_R * 255., var_G * 255., var_B * 255.);
}



/*
 * Applies the clamping technique to the image and it has generated 
 * a ppm file name <<outputfile>> which stores the new image
 * @param outputFile is the name of the file resulting from applying 
 *         the clamping technique to the image
 */
void ToneMapper::clamping(string outputFile){
    outputFile = outputFile.substr(0, outputFile.size() - 4);
    outputFile += "Clamping.ppm";
    vector<vector<RGB>> matrix = image.getImg();
    LAB lab;
    RGB rgb;
    ofstream f;
    f.open(outputFile);
    f << "P3" << endl;
    f << image.getWidth() << " " << image.getHeight() << endl;
    f << "255" << endl;
    float v = 25500.f / image.getM();
    for (int i = 0; i < image.getHeight(); i++){
        for (int j = 0; j < image.getWidth(); j++){
            lab = rgb2lab(matrix[i][j], image.getM());
            if (lab.l > v){
                lab.l = 100;
                lab.a = 0;
                lab.b = 0;
            }
            else {
                lab.l = (lab.l * 100.f) / v;
                // lab.l = 100.f - (((100.f - lab.l) * 100.f) / (100.f - v));
            }
            rgb = lab2rgb(lab);
            f << rgb.red << " " << rgb.green << " " << rgb.blue << "     ";
        }
    }
    f.close();
}



/*
 * Applies the equalization technique to the image and it has generated 
 * a ppm file name <<outputfile>> which stores the new image
 * @param outputFile is the name of the file resulting from applying 
 *        the equalization technique to the image
 */
void ToneMapper::equalization(string outputFile){
    outputFile = outputFile.substr(0, outputFile.size() - 4);
    outputFile += "Equalization.ppm";
    vector<vector<RGB>> matrix = image.getImg();
    LAB lab;
    RGB rgb;
    ofstream f;
    f.open(outputFile);
    f << "P3" << endl;
    f << image.getWidth() << " " << image.getHeight() << endl;
    f << "255" << endl;
    for (int i = 0; i < image.getHeight(); i++){
        for (int j = 0; j < image.getWidth(); j++){
            lab = rgb2lab(matrix[i][j], image.getM());
            rgb = lab2rgb(lab);
            f << rgb.red << " " << rgb.green << " " << rgb.blue << "     ";
        }
    }
    f.close();
}



/*
 * Applies the equalization and clamping techniques to the image and it has generated 
 * a ppm file name <<outputfile>> which stores the new image
 * @param outputFile is the name of the file resulting from applying 
 *        the equalization and clamping techniques to the image
 * @param v is the dimension value for the clamping
 */
void ToneMapper::equalizeClamp(const float v, string outputFile){
    outputFile = outputFile.substr(0, outputFile.size() - 4);
    outputFile += "EqualizeClamp.ppm";
    vector<vector<RGB>> matrix = image.getImg();
    LAB lab;
    RGB rgb;
    ofstream f;
    f.open(outputFile);
    f << "P3" << endl;
    f << image.getWidth() << " " << image.getHeight() << endl;
    f << "255" << endl;
    for (int i = 0; i < image.getHeight(); i++){
        for (int j = 0; j < image.getWidth(); j++){
            lab = rgb2lab(matrix[i][j], image.getM());
            if (lab.l > v){
                lab.l = 100;
                lab.a = 0;
                lab.b = 0;
            }
            else {
                lab.l = (lab.l * 100.f) / v;
                // lab.l = 100.f - (((100.f - lab.l) * 100.f) / (100.f - v));
            }
            rgb = lab2rgb(lab);
            f << rgb.red << " " << rgb.green << " " << rgb.blue << "     ";
        }
    }
    f.close();
}



/*
 * Applies the gamma curve technique to the image and it has generated 
 * a ppm file name <<outputfile>> which stores the new image
 * @param outputFile is the name of the file resulting from applying 
 *        the curve gamma technique to the image
 */
void ToneMapper::gammaCurve(string outputFile){
    outputFile = outputFile.substr(0, outputFile.size() - 4);
    outputFile += "GammaCurve.ppm";
    vector<vector<RGB>> matrix = image.getImg();
    LAB lab;
    RGB rgb;
    ofstream f;
    f.open(outputFile);
    f << "P3" << endl;
    f << image.getWidth() << " " << image.getHeight() << endl;
    f << "255" << endl;
    for (int i = 0; i < image.getHeight(); i++){
        for (int j = 0; j < image.getWidth(); j++){
            lab = rgb2lab(matrix[i][j], image.getM());
            lab.l = 100.f * pow((lab.l / 100.f), 2.2);
            rgb = lab2rgb(lab);
            f << rgb.red << " " << rgb.green << " " << rgb.blue << "     ";
        }
    }
    f.close();
}



/*
 * Applies the clamping and gamma curve techniques to the image and it has generated 
 * a ppm file name <<outputfile>> which stores the new image
 * @param outputFile is the name of the file resulting from applying 
 *        the clamping and gamma curve technique to the image
 * @param v is the dimension value for the clamping
 */
void ToneMapper::clampGamma(const float v, string outputFile){
    outputFile = outputFile.substr(0, outputFile.size() - 4);
    outputFile += "ClampGamma.ppm";
    vector<vector<RGB>> matrix = image.getImg();
    LAB lab;
    RGB rgb;
    ofstream f;
    f.open(outputFile);
    f << "P3" << endl;
    f << image.getWidth() << " " << image.getHeight() << endl;
    f << "255" << endl;
    for (int i = 0; i < image.getHeight(); i++){
        for (int j = 0; j < image.getWidth(); j++){
            lab = rgb2lab(matrix[i][j], image.getM());
            if (lab.l > v){
                lab.l = 100;
                lab.a = 0;
                lab.b = 0;
            }
            else {
                lab.l = (lab.l * 100.f) / v;
                lab.l = 100.f * pow((lab.l / 100.f), 2.2);
            }
            rgb = lab2rgb(lab);
            f << rgb.red << " " << rgb.green << " " << rgb.blue << "     ";
        }
    }
    f.close();
}