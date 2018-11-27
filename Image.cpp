#include "Image.h"
#include "Color.h"
#include <iostream>
#include <string.h>


// data accessors
namespace imaging
{

Color * Image::getRawDataPtr(){
  return buffer;
}

// Ίσως πρέπει να φύγουν τα '3'.
Color Image::getPixel(unsigned int x, unsigned int y) const{
  Color pixel;
  if ( 0 <= x <= getWidth()  && 0 <= y <= getHeight() ){
    pixel.r = buffer[3*y*getWidth() + 3*x].r; // ίσως πρέπει να φύγουν τα '+' ;;
    pixel.g = buffer[3*y*getWidth() + 3*x+1].g;
    pixel.b = buffer[3*y*getWidth() + 3*x+2].b;
    return pixel;
  }
  pixel.r = 0;
  pixel.g = 0;
  pixel.b = 0;
  return pixel;

}

// Ίσως πρέπει να φύγουν τα '3'.
void Image::setPixel(unsigned int x, unsigned int y, Color & value){
  if ( 0 <= x <= getWidth()  && 0 <= y <= getHeight() ){
    buffer[3 * y*getWidth() + 3 * x].r = value.r;
    buffer[3 * y*getWidth() + 3 * x].g = value.g;
    buffer[3 * y*getWidth() + 3 * x].b = value.b;
  }
}

// or use memcpy() instead ??
void Image::setData(const Color * & data_ptr){
  if (getWidth() != 0 && getHeight() != 0 && buffer != nullptr){
    unsigned int bufferSize = getHeight() * getWidth();
    for (int i = 0; i < bufferSize; i++){
      buffer[i] = data_ptr[i];
    }
  }
}


//constructors & destructors

Image::Image() : width(0), height(0){
  buffer = nullptr;
}


Image::Image(unsigned int width, unsigned int height){
  this->width = width;
  this->height = height;
}


Image::Image(unsigned int width, unsigned int height, const Color * data_ptr){
  this->width = width;
  this->height = height;
  this->buffer = new Color[width*height*3]; // γιατί έχω βάλει '3' ; // Image αντι για Color
  for (unsigned int i = 0 ; i < width*height; i++){ // μήπως setData(0) αντί του for ?? // setData(data_ptr)
    this->buffer[i] = data_ptr[i];
  }
  //  setData(data_ptr);
}


Image::Image(const Image &src){
  this->height = src.getHeight();
  this->width = src.getWidth();

  buffer = new Color[width*height*3];

	memcpy(buffer, src.buffer, width * height * sizeof(Color));
}

Image::~Image(){
  delete[] buffer;
}

// ΝΟΤ DONE !!
Image & Image::operator = (const Image & right){
  if (buffer){
     delete[] buffer;
  }
  width = right.width;
  height = right.height;
 // buffer =;
}


// NOT DONE !!
bool Image::load (const std::string & filename, const std::string & format){

  const char * input = filename.c_str(); // converts filename to a typical c string. ( char [] )

  //check if format is PPM
  if ( format != "ppm") {
    cerr << "Only PPM format is supported" << endl;
    return false;
  }

  int width;
  int height;

  float * floatBuffer = ReadPPM(input, &width, &height);
  if (floatBuffer == nullptr){
    cerr << "file read failed !" << "\n";
    return false;
  }
  Color * colorBuffer = new Color[w*h];
  for (int i = 0; i < width; i++){ // Αυτό είναι λάθος σταντέ / ίσως θέλει getPixel()
    colorBuffer->r = * floatBuffer;
    colorBuffer->g = * floatBuffer;
    colorBuffer->g = * floatBuffer;
  }

  width = w;
  height = h;
  buffer = data_ptr;

  delete[] floatBuffer;

  return true;
}


bool Image::save (const std:: string & filename, const std::string & format){

  //check if format is PPM .. & if Image is initialized
  int w = width, h = height;
const char * output = filename.c_str();

const Color * data_ptr = buffer;
Color * colorBuffer = buffer;

float * floatbuffer = new float[3 * w*h];
float * p = floatbuffer;



for (int i = 0; i < w*h; i++) {
  *p = colorBuffer->r;
  p++;
  *p = colorBuffer->g;
  p++;
  *p = colorBuffer->b;
  p++;
  colorBuffer++;
}

bool writedone = WritePPM(floatbuffer, w, h, output);

delete[] floatbuffer;

return writedone;

}

}
