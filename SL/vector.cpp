// Vector CPP File

#include "vector.h"

using namespace SL;

// Constructors

template<class T>
vector<T>::vector() {
	capacity_ = DEFAULT_SIZE;
	size_ = 0;
	data_ = new T[capacity_];
}

template<class T>
vector<T>::vector(const vector &v) {
	capacity_ = v.capacity_;
	size_ = v.size_;
	data_ = new T[capacity_];

	for (int i = 0; i < size_; i++) {
		data_[i] = v.data_[i];
	}
}

template<class T>
vector<T>::vector(size_t length, T val) {
	capacity_ = length;
	size_ = length;
	data_ = new T[capacity_];

	for (int i = 0; i < size_; i++) {
		data_[i] = val;
	}
}

// Capacity

template<class T>
size_t vector<T>::size() {
	return size_;
}

template<class T>
size_t vector<T>::capacity() {
	return capacity_;
}

template<class T>
bool vector<T>::empty() {
	return size_ == 0;
}


// Accessors

template<class T>
T &vector<T>::operator[](size_t index) {
	if (index >= size_) {
		// TODO: Should swap out with exception class
		throw "Out of range exception!";
	}
	return data_[index];
}


// Modifying



// Destructor

template<class T> 
vector<T>::~vector() {
	delete[] data_;
}