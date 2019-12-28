// vector header file

#ifndef SL_VECTOR_H
#define SL_VECTOR_H

#include <stddef.h>

namespace SL {

template<class T> 
class vector {
private:
	const size_t DEFAULT_SIZE = 10;
	size_t capacity_;
	size_t size_;
	T *data_;

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
	// push_back
	// pop_back
	// insert
	// erase
	// swap
	// clear

	// Destructor
	~vector();

};


}
#endif