/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


#include "../include/ImageLoaderPPM.h"
#include "../include/ToneMapper.h"
#include <cmath>
#include <algorithm>

using namespace std;


/*
 * Program that takes a ppm file passed by parameter.
 * This file is transformed from RGB format to LAB format
 * and apllies different techniques of image treatment like
 * clamping, equalization, gamma curve, equalization and clamping 
 * or clamping with gamma
 */
int main(int argc, char *argv[]){
    // Verification of the number of arguments
    if(argc == 2){
        // Correct number of arguments

        // Stores the name of the file
        string fileName;
        fileName.assign(argv[1]);
        Image image = loadImagePPM(argv[1]);
        cout << "Image loaded succesfully" << endl;
        // Construction on the image 
        vector<vector<RGB>> matrix = image.getImg();
        // Creation of the tone mapper 
        ToneMapper tm = ToneMapper(image);
        tm.equalizeClamp(75, fileName);
        cout << "Image tone mapped" << endl;
        return 0;
    }
    else{
        // Wrong number of parameters
        cerr << "Wrong number of parameters. Given " << argc - 1  << ", expected 1 (file path)" << endl;
        return 1;
    }
}