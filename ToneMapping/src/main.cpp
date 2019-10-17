#include "../include/ImageLoaderPPM.h"

int main(int argc, char *argv[]){
    if(argc == 1){
        Image image = loadImagePPM(argv[1]);
        // Small test
        cout << image.getIsHDR() << endl;
        cout << image.getWidth() << endl;
        cout << image.getHeight() << endl;
        cout << image.getRc() << endl;
        cout << image.getM() << endl;
        vector<vector<Pixel>> matrix = image.getImg();
        cout << matrix[0][0].red_pixel << " " << matrix[0][0].green_pixel << " " << matrix[0][0].blue_pixel << endl;
        cout << "Task finished" << endl;
        return 0;
    }
    else{
        cerr << "Wrong number of parameters. Given " << argc - 1  << ", expected 1 (file path)" << endl;
        return 1;
    }
}