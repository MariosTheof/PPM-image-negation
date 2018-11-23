#include "ppm.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace imaging {

  // παίζει τα << να είναι αρκετά αντί να κάνω read()
  float * ReadPPM(const char * filename, int * w, int * h){

    ifstream file(filename, ios_base::binary);

    if (file.fail()) {
      cerr << "File cannot be opened" << endl;
      // Αναγκαίο ;; file.close();
      return nullptr;
    }

    // Διάβασε την πρώτη γραμμή. αν εχει 'P6'
    string line;
    file >> line;
    if ( line.compare("P6") != 0) {
      cerr << "Not a P6 image" << endl;
      file.close();
      return nullptr;
    }

    //read file into memory
    file.seekg(0, file.end);
    int fileLength = file.tellg();
    file.seekg ( 0 , file.beg);

    //allocate memory
    float * buffer = new float[fileLength];

    //read data as a block
    file.read(buffer, fileLength);

    file.close();

    /*

    //// μήπως φτάνει το fileLength αντί για size ;;;
    int size = 3 * *w * *h;
    float * float_buffer = new float[size];
    for (int i = 0; i < size; i++){
      float_buffer = (buffer[i] / 255.0f );
    }

    */

    //delete[] buffer;
    return buffer;
    //return float_buffer;
  }

  // not done yet
  bool WritePPM(const float * data, int w, int h, const char * filename){
    if (data == nullptr){
      return false;
    }

    ofstream file(filename, ios_base::binary );

    if (file.fail()) {
      cerr << "File cannot be opened" << endl;
      // Αναγκαίο ;; file.close();
      return nullptr;
    }

    int size = 3 * w * h;
    char * temp = new char[size];

    for (int i = 0; i < size; i++){
      temp[i] = (data[i] * 255);
    }

  }



}
