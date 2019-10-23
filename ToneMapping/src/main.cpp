#include "../include/ImageLoaderPPM.h"
#include "../include/ToneMapper.h"
#include <cmath>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[]){
    
    if(argc == 2){
        Image image = loadImagePPM(argv[1]);
        // Small test
        cout << image.getIsHDR() << endl;
        cout << image.getWidth() << endl;
        cout << image.getHeight() << endl;
        cout << image.getRc() << endl;
        cout << image.getM() << endl;
        vector<vector<RGB>> matrix = image.getImg();
        cout << matrix[0][0].red << " " << matrix[0][0].green << " " << matrix[0][0].blue << endl;
        cout << "Task finished" << endl;
        ToneMapper tm = ToneMapper(image);
        tm.equalization();
        return 0;
    }
    else{
        cerr << "Wrong number of parameters. Given " << argc - 1  << ", expected 1 (file path)" << endl;
        return 1;
    }
}