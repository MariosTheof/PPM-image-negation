#include <iostream>
#include <array>
#include "Image.h"
#include "ppm.h"
#include "Color.h"

using namespace std;
using namespace imaging;

// Πρώτη λέξη το όνομα αρχείου, η δεύτερη το αρχείο PPM
int main(int argc, char* argv[])
{
    unsigned int width, height;
    char *filename = new char[50];

    char * test = new char [10];
    test = "Hey man !";
    cout << test;

    if ( argv[argc] == NULL )  {

		cout << "File name of the image to load :";
		cin >> filename;

	  }

   /* if (argc < 2 ){
      cerr << "Only 2 arguments in execution needed" << endl;
      return 0; // or nullptr // or false instead
    }*/

    //filename = argv[argc - /* 1 */]; // filename will be the last argument // μάλλον είναι -1 άμα μπαίνει κατευθείαν από κονσόλα
    cout << "input file : " << filename << endl;

    Image * inputImage = new Image(); // maybe switch name to image
    inputImage->load(filename, "ppm");
    /*
    Simply saying: To access members of a structure, use the dot operator.
    To access members of a structure through a pointer, use the arrow operator.
    */
    width = inputImage->getWidth();
    height = inputImage->getHeight();

    cout << "Image dimensions are : " << width << " x " << height << endl;

    Color * negativeImageColor = inputImage->getRawDataPtr();

    for (int i =0; i < width*height ; i++){
        negativeImageColor[i].r = 1.0f - negativeImageColor[i].r;
        negativeImageColor[i].g = 1.0f - negativeImageColor[i].g;
        negativeImageColor[i].b = 1.0f - negativeImageColor[i].b;
    }

    const Color * constNegativeImageColor = negativeImageColor;
    Image * negativeImage = new Image();

    negativeImage->setData(constNegativeImageColor);



    /*
    // Write image to a new file
    string tempFile = filename;
    string copypath = tempFile.substr(0, tempFile.find_first_of('.')) + "_neg.ppm";



    if (*inputImage >> copypath){ // return WritePPM  // or smth?
      cout << "New image : " << copypath << endl;
    }else {
      cout << "Write failled" << endl;
    }
    */
    system("pause");
    return 0;
}
