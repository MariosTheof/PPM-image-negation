#include "ppm.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace imaging {

  float * ReadPPM(const char * filename, int * w, int * h){

    ifstream file(filename, ios_base::binary);

    cout << "File in ReadPPM method :" << filename << endl;

    if (!file.is_open()) {
      cerr << "File cannot be opened" << endl;
      // Αναγκαίο ;; file.close();
      return nullptr;
    }

    string line;
    int maxBitValue = 0;

    file >> line ;

    // Διάβασε την πρώτη γραμμή. αν εχει 'P6'
    if ( line.compare("P6") != 0) {
      cerr << "Not a P6 image" << endl;
      file.close();
      return nullptr;
    }
    file >> *w >> *h >> maxBitValue;
    //Διάβασε εάν η μέγιστη αξια των bit δεν υπερβαίνει τις ορισμένες μας τιμές
    if ((maxBitValue == 0) || (maxBitValue > 255)){
      cerr << "Bit value is larger than allowed maximum or less than 0. " << endl;

      return nullptr;
    }


    int size = 3 * *w * *h;

    float * floatBuffer = new float[size];

    unsigned char * tempBuffer = new unsigned char[size];

    file.read((char*)tempBuffer, size);

    for (int i = 0; i < size; i++) {
      floatBuffer[i] = (tempBuffer[i] / 255.0f);
    }

    file.close();
    delete[] tempBuffer;

    return floatBuffer;
  }


  bool WritePPM(const float * data, int w, int h, const char * filename){
    if (data == nullptr){
      return false;
    }

    ofstream file(filename, ios_base::binary );

    if (file.fail()) {
      cerr << "File cannot be opened" << endl;
      return false; // ή nullptr
    }

    int size = 3 * w * h;
    char * tempBuffer = new char[size];

    for (int i = 0; i < size; i++){
      tempBuffer[i] = (data[i] * 255.0f);;
    }

    file << "P6" << endl << w << endl << h << endl << "255" << endl;

    file.write(tempBuffer, size);
    file.close();

    return true;
  }

}
