#include "FilterBlur.h"



namespace imaging {
	Image imaging::FilterBlur::operator<<(const Image & image)
	{
		Image tempImg;
		Image tempImg2;
		tempImg = image;
		tempImg2 = image;
		Vec3<float> p_Pixel;
		Vec3<float> finalPixel;
		//Vec3<float> f_Pixel;
		for (int i = 0 ; i < image.getHeight(); i++){
			for (int j = 0 ; j < image.getWidth(); j++){
				
				float red = 0;
				float green = 0;
				float blue = 0;
				int count = 0;
				
				
				for (int m = -(N / 2); m <= (N / 2); m++)
				{
					for (int n = -(N / 2); n <= (N / 2); n++)
					{
						if ((i + m < image.getHeight()) && ((int)i + m >= 0)
							&& (j + n < image.getWidth()) && ((int)j + n >= 0))
						{

							count++;
							p_Pixel = tempImg.getPixel((int)i + m, (int)j + n);
							//f_Pixel = tempImg.getPixel((int)m + (N/2), (int)n + (N/2));

							
							red = red + p_Pixel.r;
							green = green + p_Pixel.g;
							blue = blue + p_Pixel.b;
						}
					}
				}
				
				red = red / count;
				green = green / count;
				blue = blue / count;
				
				

				finalPixel.r = red;
				finalPixel.g = green;
				finalPixel.b = blue;

				finalPixel = finalPixel.clampToLowerBound(0.0);
				finalPixel = finalPixel.clampToUpperBound(1.0);

				tempImg2.setPixel(i, j, finalPixel);
				

		}
	
	}


		return tempImg2;
	}



	imaging::FilterBlur::FilterBlur() {}

	imaging::FilterBlur::FilterBlur(int N)
	{
		this->N = N;
	}

	imaging::FilterBlur::FilterBlur(const FilterBlur & src)
	{
		this->N = src.N;
	}
}
