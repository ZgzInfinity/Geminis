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
  * ImageLoaderPPM.cpp implementation file of ImageLoaderPPM module
  */

#include "../include/ImageLoaderPPM.h"



/**
 * Builds an image in rgb format from a file in ppm format
 * @param path is the destination of the ppm file which contains the image
 * @returns an image in rgb format from a file in ppm format
 */
Image loadImagePPM(string path){
    // Reading flow of the file which contains the image
    ifstream f;
    // Open the file
    f.open(path);
    // Verify if the file has been opened correctly
    if (f.is_open()){
        // Correct
        int numResources = 0;
        int width, height;
        float rc, m = -1;
        string str;
        getline(f, str);
        while (!f.eof() && (numResources < 4 || f.peek() == '#')){
            if (f.peek() == '#'){
                // Read the line
                getline(f, str);
                // Control if the line stores the real maximum value of the image
                if (str.size() > 5 && str.substr(0, 5) == "#MAX="){
                    // Keeps the value 
                    m = stof(str.substr(5, str.size()));
                }
            }
            else {
                // It is an interesting field to read
                switch (numResources){
                    case 1:
                        // The width of the image
                        f >> width >> height;
                        numResources += 2;
                        break;
                    case 3:
                        // The real maximum value of the image
                        f >> rc;
                    default:
                        // Increment the number of read fields
                        numResources++;
                }
            }
        }
        // Start to read the matrix of the image
        //Pixel *matrix = new Pixel[width];
        vector<vector<RGB>> matrix(height, vector<RGB>(width));
        // Pixels of the three colors in RGB
        float red_pixel, green_pixel, blue_pixel;
        float convFactor = 1;
        if(m != -1){
            convFactor = m / rc;
        }
        // Actual indexes of the image matrix
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                // Reading a pixel of the matrix
                f >> red_pixel >> green_pixel >> blue_pixel;
                // Creation of the pixel (and convert to maximum m)
                matrix [i][j] = RGB(red_pixel * convFactor, green_pixel * convFactor,
                                      blue_pixel * convFactor);
            }
        }
        // Close the writting flow and return of the image
        f.close();
        return Image(true, width, height, rc, m, matrix);
    }
    else {
        // Error
        cerr << "Error while trying to open the file " << path << endl;
        exit(1);
    }
}