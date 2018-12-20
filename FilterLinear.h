#ifndef _FILTERLINEAR
#define _FILTERLINEAR

#include "Filter.h"
#include "Vec3.h"

namespace imaging {
	class FilterLinear : public Filter {

	protected:
		float a,c;
		Vec3<float> * linearPixel;
	public:

		Image operator << (const Image & image);

		FilterLinear();

		FilterLinear(float a, float c);

		//FilterLinear(float param);

		FilterLinear(const FilterLinear & src);


	};
}
#endif // !_FilterLinear_