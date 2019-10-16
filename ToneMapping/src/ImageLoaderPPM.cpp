#include "../include/ImageLoaderPPM.h"


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
        float rc, m = 0;
        while (!f.eof() && (numResources < 4 || f.peek() == '#')){
            if (f.peek() == '#'){
                // Read the line
                string str;
                getline(f, str);
                // Control if the line stores the real maximum value of the image
                if (str.size() > 5 && str.substr(0, 5) == "#MAX="){
                    // Keeps the value 
                    m = stof(str.substr(6, str.size()));
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
        Pixel **matrix;
        // Pixels of the three colors in RGB
        float red_pixel, green_pixel, blue_pixel;
        // Actual indexes of the image matrix
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                // Reading a pixel of the matrix
                f >> red_pixel >> green_pixel >> blue_pixel;
                // Creation of the pixel
                matrix [i][j] = Pixel(red_pixel, green_pixel, blue_pixel);
            }
        }
        f.close();
        return Image(true, width, height, rc, m, matrix);
    }
    else {
        // Error
        cerr << "Error while trying to open the file " << path << endl;
        return Image();
    }
}