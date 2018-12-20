#include "Filter.h"
#include "Image.h"
#include "FilterLinear.h"


namespace imaging {


	Image FilterLinear::operator<<(const Image & image)
	{
		unsigned int index = 0;
		Image tempImg(image.getWidth(), image.getHeight());
		for (unsigned int i = 0; i < image.getWidth(); i++) {
			for (unsigned int y = 0; y < image.getHeight(); y++) {

				linearPixel[index].r = a * image.getItemByCoordinates(i, y).r + c;
				linearPixel[index].g = a * image.getItemByCoordinates(i, y).g + c;
				linearPixel[index].b = a * image.getItemByCoordinates(i, y).b + c;

				linearPixel[index] = linearPixel[index].clampToUpperBound(1.0);
				linearPixel[index] = linearPixel[index].clampToUpperBound(0.0);
				index++;
			}
		}
		


		return tempImg;

	}

	FilterLinear::FilterLinear() {}

	FilterLinear::FilterLinear(float a, float c)
	{
		this->a = a;
		this->c = c;
	}

	FilterLinear::FilterLinear(const FilterLinear & src)
	{
		this->a = src.a;
		this->c = src.c;
	}

	/*FilterLinear& operator = (const FilterLinear& src) {

		a = src.a;
		c = src.c;
		return *this;
	}*/

}