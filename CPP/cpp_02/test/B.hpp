#ifndef __B_GUARD__
#define __B_GUARD__

#include "A.hpp"

class B {
	private:
		const A x;
		const A y;
	public:
		B();
		B(const B& b);
};

#endif