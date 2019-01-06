#include "FilterBlur.h"
#include "FilterLaplace.h"


namespace imaging {
	Image imaging::FilterLaplace::operator<<(const Image & image)
	{
		float redSum;
		float greenSum ;
		float blueSum ;
		Image tempImg;
		tempImg = image;

		float kernel[3][3] = { {0, 1, 0},{1,-4, 1},{0, 1, 0} };

		for (unsigned int i = 0; i < image.getHeight(); i++) {
			for (unsigned int j = 0; j < image.getWidth(); j++) {

				redSum = 0;
				greenSum = 0;
				blueSum = 0;
				int count = 0;
				Vec3<float> pixel;
				Vec3<float> finalPixel;
				for (int y = -1; y <= 1; y++)
				{
					for (int x = -1; x <= 1; x++) 
					{
						
							pixel = tempImg.getPixel(i, j);

							redSum += pixel[0] * kernel[y + 1][x + 1];
							greenSum += pixel[1] * kernel[y + 1][x + 1];
							blueSum += pixel[2] * kernel[y + 1][x + 1];

							
						

					}
				}

				redSum = pixel[0] - (0.2 * redSum );
				greenSum = pixel[1] - (0.2 * greenSum );
				blueSum = pixel[2] - (0.2 * blueSum);
				
				finalPixel[0] = redSum;
				finalPixel[1] = greenSum;
				finalPixel[2] = blueSum;

				finalPixel = finalPixel.clampToLowerBound(0.0);
				finalPixel = finalPixel.clampToUpperBound(1.0);

				tempImg.setPixel(i, j, finalPixel);

			}
		}

		return tempImg;

	}

	FilterLaplace::FilterLaplace(){}

	FilterLaplace::FilterLaplace(const FilterLaplace & src) {}


}