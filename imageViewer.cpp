﻿// imageViewer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "Image.h"
#include "ppm.h"
#include "Filter.h"

#include "FilterGamma.h"
#include "FilterLinear.h"


using namespace std;
using namespace imaging;

//argc = numberOfArguments // argv = argument vector
int main(int argc, char * argv[]) {

	string inputFile;
	
	inputFile = argv[argc - 1];
	int dotfound = inputFile.find_first_of('.');
	if (dotfound <= -1 || inputFile.substr(inputFile.find_first_of('.')).compare(".ppm") != 0) {
		cerr << "Incorrect or non-existant file has been given !" << endl;
		return -1;

	}

	Image img;
	
	img.load(inputFile, "ppm"); 
	cout << "Image dimensions are " << img.getHeight() << " X " << img.getWidth() << endl;

	int i = 0;
	while (i < argc) {
		
		if (strcmp(argv[i], "-f") == 0) {
			i++;

			if (strcmp(argv[i], "linear") == 0) {
				Vec3<float> a, c;
				i++;
				//Converting strings to integers
				a.r = stof(argv[i]);
				i++;
				a.g = stof(argv[i]);
				i++;
				a.b = stof(argv[i]);
				i++;
				c.r = stof(argv[i]);
				i++;
				c.g = stof(argv[i]);
				i++;
				c.b = stof(argv[i]);
				
				FilterLinear filterLinear(a, c);

				img =  filterLinear << img;
				cout << "Linear Filter Applied" << endl;
			}

			if (strcmp(argv[i], "gamma") == 0) {
				i++;
				float gamma = stof(argv[i]);
				FilterGamma filterGamma(gamma);

				img = filterGamma << img;
				cout << "Gamma filter Applied" << endl;
			}
		}
		i++;
	}


	// Write image to a new file
	string tempFile = inputFile;
	string copypath = "filtered_" + tempFile;



	if (img.save(copypath, "ppm")) {
		cout << "New image : " << copypath << endl;
	}
	else {
		cout << "Write failed" << endl;
		return -1;
	}

	return 0;
}