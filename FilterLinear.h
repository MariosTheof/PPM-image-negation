#ifndef _FILTERLINEAR
#define _FILTERLINEAR

#include "Filter.h"
#include "Vec3.h"

namespace imaging {
	class FilterLinear : public Filter {

	protected:
		//float a,c;
		Vec3<float> * linearPixel, a, c;
	public:

		Image operator << (const Image & image);

		FilterLinear();

		FilterLinear(Vec3<float> a, Vec3<float> c);

		//FilterLinear(float param);

		FilterLinear(const FilterLinear & src);


	};
}
#endif // !_FilterLinear_