#ifndef _FILTERBLUR
#define _FILTERBLUR

#include "Filter.h"
#include "Array.h"


typedef Vec3<float> Color;

namespace imaging {
	class FilterBlur : public Array<Color>, public Filter {
		
	protected:	
		Vec3<float> * linearPixel;
		int N;
	public:
		Image operator << (const Image & image);

		FilterBlur();

		FilterBlur(int N);

		FilterBlur(const FilterBlur &src);
	};
	
}
#endif