#include "Image.h"
#include <iostream>
#include <string>


const unsigned int getWidth() const {
  return width;
}

const unsigned int getHeight() const {
  return height;
}

// data accessors

// δεν ξέρω αν είναι σωστό
Color * getRawDataPtr(){
  return (Color *)Array<Color>::getRawDataPtr(); // return buffer;
}
// δεν ξέρω αν είναι σωστό
Color getPixel(unsigned int x, unsigned int y) const{
  Color pixel;
  if ( 0 <= x <= getWidth()  && 0 <= y <= getHeight() ){
    pixel.r = buffer[3*y*getWidth() + 3*x]; // μέθοδος getWidth // getHeight
    pixel.g = buffer[3*y*getWidth() + 3*x+1];
    pixel.b = buffer[3*y*getWidth() + 3*x+2];
    return pixel;
  }
  pixel.r = 0;
  pixel.g = 0;
  pixel.b = 0;
  return pixel;

}

// δεν ξέρω αν είναι σωστό
void setPixel(unsigned int x, unsigned int y, Color & value){
  if ( 0 <= x <= getWidth()  && 0 <= y <= getHeight() ){
    buffer[3 * y*getWidth() + 3 * x] = value.r;
    buffer[3 * y*getWidth() + 3 * x] = value.g;
    buffer[3 * y*getWidth() + 3 * x] = value.b;
  }
}

void setData(const Color * & data_ptr){

}


//constructors & destructors


Image() {
  buffer = nullptr;
  //
}

Image(unsigned int width, unsigned int height) {
  this->width = width;
  this->height = height;
}

Image(unsigned int width, unsigned int height, const Color * data_ptr){
  this->width = width;
  this->height = height;
  //buffer = new Image[width*height*3];
  //setData(data_ptr);
}

Image(const Image &src){
  this->height = src.getHeight();
	this->width = src.getWidth();
  buffer = new Image[width*height*3];
  int i = 0;
  while (i < width*height * 3){
		buffer[i] = *(src.getRawDataPtr() + i);
		i++;
	}
}

~Image(){
  delete[] buffer;
}


//Image & operator = (const Image & right);

bool load (const std::string & filename, const std::string & format){

}

bool save (const std:: string & filename, const std::string & format){}
