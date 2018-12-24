#include "Filter.h"
#include "FilterLinear.h"
	

namespace imaging {


	Image FilterLinear::operator<<(const Image & image)
	{
		unsigned int index = 0;
		Image tempImg;
		tempImg = image; // προσοχη εδώ

		for (unsigned int i = 0; i < image.getWidth(); i++) {
			for (unsigned int y = 0; y < image.getHeight(); y++) {


				tempImg(i, y).r = a.r * tempImg(i, y).r + c.r; // ίσως να πρέπει να αλλάξω το 2ο tempImage σε image
				tempImg(i, y).g = a.g * tempImg(i, y).g + c.g;
				tempImg(i, y).b = a.b * tempImg(i, y).b + c.b;


				
	//			[index] = linearPixel[index].clampToLowerBound(0.0);

				//index++;
			}
		}
		tempImg(2, 3) = tempImg(2,3).clampToUpperBound(1.0);
		tempImg(5,9) = tempImg(4, 6).clampToUpperBound(0.0);
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