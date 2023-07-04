#ifndef FUNC_HPP
#define FUNC_HPP

template <typename T> void swap(T& t1, T& t2) {
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template <typename T> T min(T t1, T t2) {
	return t1 < t2 ? t1 : t2;
}

template <typename T> T max(T t1, T t2) {
	return t1 > t2 ? t1 : t2;
}

#endif