#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T> void iter(T* t1, size_t siz, void (*func)(T&)) {
	for(size_t i = 0; i < siz; i++) {
		func(t1[i]);
	}
}

template <typename T> void increment(T& a) {
	a++;
}

#endif