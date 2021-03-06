﻿#include <iostream>
#include <string.h>
#include "Vec3.h"
#include "ppm.h"
#include "Image.h"

using namespace std;
using namespace math;

typedef Vec3<float> Color;

// data accessors
namespace imaging
{

	Color * Image::getRawDataPtr() {
		Color * buffer = new Color[getWidth() * getHeight() * sizeof(Color)];
		return buffer;
	}

	Color Image::getPixel(unsigned int x, unsigned int y) const {

		Color  pixel_color;

		if (x < 0 || y < 0 || x > getHeight() || y > getWidth()) {

			pixel_color.r = 0;
			pixel_color.g = 0;
			pixel_color.b = 0;
			return pixel_color;
		}

		unsigned int position = x + getHeight() * y;

		pixel_color.r = buffer[position].r;
		pixel_color.g = buffer[position].g;
		pixel_color.b = buffer[position].b;

		return pixel_color;
	}

	void  Image::setPixel(unsigned int x, unsigned int y, Color &value) {

		if (x < 0 || y < 0 || x > getHeight() || y > getWidth()) {

			return;
		}
		unsigned int position = x + getHeight() * y;
		buffer[position].r = value.r;
		buffer[position].g = value.g;
		buffer[position].b = value.b;

		return;
	}



	// or use memcpy() instead ??
	void Image::setData(const Color * & data_ptr) {

		if ((getRawDataPtr() == nullptr) || (getWidth() == 0) || (getHeight() == 0)) {

			cout << "Exiting..." << endl;

			return;
		}
		if (buffer == NULL) {
			cerr << "buffer is null" << endl;
			return;
		}
		for (int i = 0; i < width * height; i++) {

			buffer[i] = data_ptr[i];

		}

	}


	//constructors & destructors

	Image::Image() : width(0), height(0) {
		buffer = nullptr;
	}


	Image::Image(unsigned int width, unsigned int height) {
		this->width = width;
		this->height = height;
	}


	Image::Image(unsigned int width, unsigned int height, const Color * data_ptr) {
		this->width = width;
		this->height = height;
		this->buffer = new Color[width*height * 3]; // γιατί έχω βάλει '3' ; // Image αντι για Color
		for (unsigned int i = 0; i < width*height; i++) { // μήπως setData(0) αντί του for ?? // setData(data_ptr)
			this->buffer[i] = data_ptr[i];
		}
		//  setData(data_ptr);
	}


	Image::Image(const Image &src) {
		this->height = src.getHeight();
		this->width = src.getWidth();

		buffer = new Color[width*height * 3];

		memcpy(buffer, src.buffer, width * height * sizeof(Color));
	}

	Image::~Image() {
		delete[] buffer;
	}


	Image & Image::operator = (const Image & right) { // Ουσιαστικά ορίζουμε τι συμβαίνει όταν γράφουμε  "Image img = "
		if (buffer != nullptr) { // μπορούμε χωρίς τον buffer μας
			delete[] buffer;
		}
		width = right.width;
		height = right.height;

		const Color * data_ptr = right.buffer;

		buffer = new Color[height*width];
		setData(data_ptr);

		return *this;

	}

	bool Image::load(const std::string & filename, const std::string & format) {
		//check if format is PPM
		if (filename.substr(filename.find_first_of('.')).compare(".ppm") != 0) {
			cerr << "Only PPM format is supported" << endl;
			return false;
		}

		const char * input = filename.c_str(); // converts filename to a typical c string. ( char [] )

		int w;
		int h;

		float * floatBuffer = ReadPPM(input, &w, &h);

		width = w;
		height = h;

		int size = w * h * 3;
		//int size2 = w * h * sizeof(Color);

		if (floatBuffer == nullptr) { // or NULL
			cerr << "file read failed !" << "\n";
			return false;
		}

		buffer = getRawDataPtr();


		for (int i = 0, y = 0; i < size; i += 3, y++) {
			
			buffer[y].r = floatBuffer[i];
			buffer[y].g = floatBuffer[i + 1];
			buffer[y].b = floatBuffer[i + 2];

		}

		delete[] floatBuffer;

		return true;
	}

	bool Image::save(const std::string & filename, const std::string & format) {

		//check if format is PPM
		if  (filename.substr(filename.find_first_of('.')).compare(".ppm") != 0){
			cerr << "Only PPM format is supported" << endl;
			return false;
		}
		if (buffer == NULL) {
			cerr << "buffer is NULL" << endl;
			return false;
		}

		const char * output = filename.c_str();


		int size = width * height * 3;
		int size2 = width * height * sizeof(Color);



		float * floatbuffer = new float[size];

		for (int i = 0, y = 0; i < size && y < size2; i += 3, y++) {

			floatbuffer[i] = buffer[y].r;
			floatbuffer[i + 1] = buffer[y].g;
			floatbuffer[i + 2] = buffer[y].b;
		}




		int w = width, h = height;
		bool writedone = WritePPM(floatbuffer, w, h, output);

		delete[] floatbuffer;

		return writedone;

	}

}