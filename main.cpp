#include <iostream>
#include <array>
#include "Image.h"
#include "ppm.h"
#include "Color.h"

using namespace std;
using namespace imaging;

/*
TODO save() always produces false ??
TODO pixel πράξεις dont exactly produce negative filter for the images
*/


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

    Image img;
    img.load(filename, "ppm");
const Color c(1, 1, 1);
	cout << img.getHeight() << endl << img.getWidth() << endl;

	for (int i = 0 ; i <img.getHeight() ; i++ ) {
		for (int y = 0; y < img.getWidth(); y++) {

            Color pixel = img.getPixel(i,y);

            pixel[0] = 1.0f - pixel[0];
            pixel[1] = 1.0f - pixel[1];
            pixel[2] = 1.0f - pixel[2];

            img.setPixel(i,y , pixel);

		}

	}

	//img.save(filename, "ppm");



    // Write image to a new file
    string tempFile = filename;
    string copypath = tempFile.substr(0, tempFile.find_first_of('.')) + "_neg.ppm";



    if (img.save(copypath, "ppm")){
      cout << "New image : " << copypath << endl;
    }else {
      cout << "Write failed" << endl;
      return -1;
    }


    return 0;
}
