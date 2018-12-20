
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
				Image tempImg(image.getWidth(), image.getHeight());
				for (unsigned int i = 0; i < image.getWidth(); i++) {
					for (unsigned int y = 0; y < image.getHeight(); y++) {
						/*
						p`(x,y) = p(x,y)^exp
						*/
					
						gammaPixel[index].r = pow(image.getItemByCoordinates(i, y).r, powerExponent);
						gammaPixel[index].g = pow(image.getItemByCoordinates(i, y).g, powerExponent);
						gammaPixel[index].b = pow(image.getItemByCoordinates(i, y).b, powerExponent);
						
						//Ready from Vec3.h functions
						gammaPixel[index] = gammaPixel[index].clampToUpperBound(1.0);
						gammaPixel[index] = gammaPixel[index].clampToLowerBound(0.0);

						tempImg.setItemByCoordinates(i, y,* gammaPixel); // προσοχή εδώ έβαλα pointer
						index++;
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
	
	/*FilterGamma::FilterGamma(float powerExponent)
	{ //μάλλον περιττό
		this->powerExponent = powerExponent;
	}*/

	FilterGamma::FilterGamma(const FilterGamma & src)
	{
		this->powerExponent = src.powerExponent;
	}


}