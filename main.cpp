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

    Image * image = new Image();

    image->load(filename, "ppm");
    /*
    Simply saying: To access members of a structure, use the dot operator.
    To access members of a structure through a pointer, use the arrow operator.
    */
    width = image->getWidth();
    height = image->getHeight();

    cout << "Image dimensions are : " << width << " x " << height << endl;

    Color * negativeImageColorBuffer = image->getRawDataPtr();

    for (int i =0; i < width*height ; i++){
        float r = negativeImageColorBuffer[i].r; //αν δεν το θέσω σε float τότε δεν το πιάνει ως αριθμό
        float g = negativeImageColorBuffer[i].g;
        float b = negativeImageColorBuffer[i].b;

        negativeImageColorBuffer[i].r = 1.0f - r;
        negativeImageColorBuffer[i].g = 1.0f - g;
        negativeImageColorBuffer[i].b = 1.0f - b;
    }

    const Color * constNegativeImageColor = negativeImageColorBuffer;
    Image * negativeImage = new Image(width, height);

    negativeImage->setData(constNegativeImageColor);




    // Write image to a new file
    string tempFile = filename;
    string copypath = tempFile.substr(0, tempFile.find_first_of('.')) + "_neg.ppm";



    if (!negativeImage->save(copypath, "ppm")){
      cout << "New image : " << copypath << endl;
    }else {
      cout << "Write failed" << endl;
      return -1;
    }


    return 0;
}
