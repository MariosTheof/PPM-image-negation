#ifndef _FILTERGAMMA
#define _FILTERGAMMA

#include "Filter.h"
#include "Vec3.h"

namespace imaging {
	class FilterGamma : public Filter {

	protected:
		float powerExponent;
		Vec3<float> * gammaPixel;

	public:

		Image operator << (const Image & image);

		FilterGamma();

		//FilterGamma(float param);

		FilterGamma(const FilterGamma & src);


	};
}
#endif // !_FilterGamma_