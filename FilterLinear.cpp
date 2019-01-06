#include "Filter.h"
#include "FilterLinear.h"
#include "Vec3.h"
	

namespace imaging {


	Image FilterLinear::operator<<(const Image & image)
	{
		unsigned int index = 0;
		Image tempImg;
		tempImg = image; // προσοχη εδώ

		for (unsigned int i = 0; i < image.getHeight(); i++) {
			for (unsigned int y = 0; y < image.getWidth(); y++) {

				Vec3<float> pixel = tempImg.getPixel(i, y);
				
				pixel[0] = a.r * pixel[0] + c.r;
				pixel[1] = a.g * pixel[1] + c.g;
				pixel[2] = a.b * pixel[2] + c.b;

				pixel = pixel.clampToLowerBound(0.0);
				pixel = pixel.clampToUpperBound(1.0);
				
				tempImg.setPixel(i, y, pixel);
		
			}
		}
	

		return tempImg;

	}

	FilterLinear::FilterLinear() {}

	FilterLinear::FilterLinear(Vec3<float> a, Vec3<float> c)
	{
		this->a = a;
		this->c = c;
	}

	FilterLinear::FilterLinear(const FilterLinear & src)
	{
		this->a = src.a;
		this->c = src.c;
	}


}