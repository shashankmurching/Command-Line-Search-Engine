// vector header file

#ifndef SL_VECTOR_H
#define SL_VECTOR_H

#include <stddef.h>

namespace SL {

template<class T> 
class vector {
public:
	// Constructors
	vector();
	vector(const vector &v);
	vector(size_t length, T val);

	// Capacity
	size_t size();
	size_t capacity();
	bool empty();

	// Accessors
	T& operator[](size_t index);
	T& at(size_t index);
	T& front();
	T& back();

	// Modifying
	void push_back(T val);
	void pop_back(T val);

	// Destructor
	~vector();

private:
	const size_t DEFAULT_SIZE = 10;
	const size_t UPDATE_FACTOR = 2;
	size_t capacity_;
	size_t size_;
	T *data_;


	void increase_capacity();
};


}
#endif