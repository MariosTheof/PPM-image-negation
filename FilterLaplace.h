#pragma once
#ifndef _FILTERLAPLACE
#define _FILTERLAPLACE

#include "Array.h"
#include "FilterBlur.h"

typedef Vec3<float> Color;

namespace imaging {
	class FilterLaplace : public FilterBlur {

	protected:
		Vec3<float> * linearPixel;
		int N;
	public:
		Image operator << (const Image & image);

		FilterLaplace();

		FilterLaplace(const FilterLaplace &src);
	};

}
#endif