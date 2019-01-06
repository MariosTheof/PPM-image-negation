#include "Filter.h"
#include "FilterGamma.h"
#include <iostream>
#include <cmath>

namespace imaging {
	Image FilterGamma::operator<<(const Image & image)
	{
		{				
			if (powerExponent >= 0.5 && powerExponent <= 2.0) {

				unsigned int index = 0;
				Image tempImg;
				tempImg = image;
				
					for (unsigned int i = 0; i < image.getHeight(); i++) {
						for (unsigned int y = 0; y < image.getWidth(); y++) {
						
							Vec3<float> pixel = tempImg.getPixel(i, y);

							pixel[0] = pow(pixel[0], powerExponent);
							pixel[1] = pow(pixel[1], powerExponent);
							pixel[2] = pow(pixel[2], powerExponent);

							tempImg.setPixel(i, y, pixel);
							
						}
					}
				
				return tempImg;
			}
			else {
				cerr << "Out of bounds FilterGamma exponent value!" << endl;
				cerr << "Gamma filter won't be applied!" << endl;
				return image;
			}
		}
		return Image();
	}

	FilterGamma::FilterGamma() {}
	
	FilterGamma::FilterGamma(float powerExponent)
	{ //μάλλον περιττό
		this->powerExponent = powerExponent;
	}

	FilterGamma::FilterGamma(const FilterGamma & src)
	{
		this->powerExponent = src.powerExponent;
	}


}