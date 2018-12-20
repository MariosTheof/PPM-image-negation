#ifndef _FILTER
#define _FILTER

#include "Image.h"
#include "Array.h"
#include "Vec3.h"

namespace imaging {
	class Filter {

	public:

		virtual Image operator << (const Image & image) = 0;

		Filter() {};

		Filter(Filter & src) {};


	};
}
#endif
