#ifndef _ARRAY
#define _ARRAY

#include <vector>
#include <iostream>
#include "Vec3.h"


namespace math
{
	
	//---------------------------------------------------------------------------------------------
	// Do NOT modify this section. For the implementation, see comment below the class declaration

	template <typename T>
	class Array
	{
	protected:
		std::vector<T> buffer;
		unsigned int width, height;

	public:

		unsigned int getWidth() const { return width; }   
		unsigned int getHeight() const { return height; }    

		T * getRawDataPtr();                             		

		T getItemByCoordinates(unsigned int x, unsigned int y) const;

		void setItemByCoordinates(unsigned int x, unsigned int y, T & value);

		void setData(const T * & data_ptr);

		T & operator () (int x, int y);                      
		
		const T & operator() (int x, int y) const;     

		
		Array(unsigned int w, unsigned int h);

		Array(unsigned int width, unsigned int height, const T * data_ptr);

		Array(const Array<T> & src); 
		
		Array & operator = (const Array<T> & right);

		virtual ~Array();									 

	};

	// This is a templated class so include its implementation in the header file below this line:
	//--------------------------------------------------------------------------------------------

	template <typename T>
	T * Array<T>::getRawDataPtr() {
		return buffer;
	}

	template<typename T>
	inline T math::Array<T>::getItemByCoordinates(unsigned int x, unsigned int y) const
	{
		T  t;

		if (x < 0 || y < 0 || x > getHeight() || y > getWidth()) {

			std::cerr << "Out of bounds" << std::endl;
			return t;
		}
		unsigned int position = x + getHeight() * y;
		t = buffer[position]; //place buffer[i] in color
		return t;
	}

	template<typename T>
	inline void math::Array<T>::setItemByCoordinates(unsigned int x, unsigned int y, T & value)
	{
		if (x < 0 || y < 0 || x > getHeight() || y > getWidth()) {

			return;
		}
		unsigned int position = x + getHeight() * y;
		//buffer[position].r = value.r;
		//buffer[position].g = value.g;
		//buffer[position].b = value.b;
		buffer[position] = value;
		return;
	}

	template<typename T>
	inline void Array<T>::setData(const T *& data_ptr)
	{
		if ((getRawDataPtr() == nullptr) || (getWidth() == 0) || (getHeight() == 0)) {

			std::cout << "Exiting..." << std::endl;

			return;
		}
		if (buffer == NULL) {
			std::cerr << "buffer is null" << std::endl;
			return;
		}
		for (unsigned int i = 0; i < width*height; i++) {
			buffer[i] = data_ptr[i];
		}
	}

	template <typename T>
	T & Array<T>::operator () (int x, int y) {
		return buffer[x * y];
	}

	template <typename T>
	const T & Array<T>::operator () (int x, int y) const {
		return buffer[x * y];
	}

	template <typename T>
	Array<T>::Array(unsigned int w, unsigned int h) : width(w), height(h), buffer(NULL) {}

	template<typename T>
	inline Array<T>::Array(unsigned int width, unsigned int height, const T * data_ptr)
	{
		this->width = width;
		this->height = height;
		this->buffer = new T[width*height * 3]; 
		for (unsigned int i = 0; i < width*height; i++) { // μήπως setData(0) αντί του for ?? // setData(data_ptr)
			this->buffer[i] = data_ptr[i];
		}
	}

	template <typename T>
	Array<T>::Array(const Array<T> & source) : width(source.width), height(source.height), buffer(source.buffer) {	}

	template <typename T>
	Array<T> & Array<T>::operator = (const Array<T> & src) {
		Array<T> left = Array<T>(src);
		return left;
	}


	template <typename T>
	Array<T>::~Array() {}

} // namespace math
#endif