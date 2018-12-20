// imageViewer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "Image.h"
#include "ppm.h"
#include "Filter.h"


using namespace std;
using namespace imaging;


// Πρώτη λέξη το όνομα αρχείου, η δεύτερη το αρχείο PPM
int main(int argc, char* argv[])
{
	char *filename = new char[50];

	if (argv[argc] == NULL) {

		cout << "File name of the image to load :";
		cin >> filename;

	}

	cout << "input file : " << filename << endl;

	Image img;

	img.load(filename, "ppm");
	
	cout << "Image dimensions are " << img.getHeight() << " X " << img.getWidth() << endl;

/*	for (int i = 0; i < img.getHeight(); i++) {
		for (int y = 0; y < img.getWidth(); y++) {

			Color pixel = img.getPixel(i, y);//

			pixel = 1.0f - pixel;

			img.setPixel(i, y, pixel);//

		}
	}*/


	// Write image to a new file
	string tempFile = filename;
	string copypath = tempFile.substr(0, tempFile.find_first_of('.')) + "_neg.ppm";



	if (img.save(copypath, "ppm")) {
		cout << "New image : " << copypath << endl;
	}
	else {
		cout << "Write failed" << endl;
		return -1;
	}


	return 0;
}
