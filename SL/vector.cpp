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
T& vector<T>::operator[](size_t index) {
	return vector<T>::at(index);
}

template<class T>
T& vector<T>::at(size_t index) {
	if (index >= size_) {
		// TODO: Should swap out with exception class
		throw "Out of range exception!";
	}
	return data_[index];
}

template<class T>
T& vector<T>::front() {
	return vector<T>::at(0);
}

template<class T>
T& vector<T>::back() {
	return vector<T>::at(size_ - 1);
}


// Modifying
template<class T>
void vector<T>::push_back(T val) {
	if (size_ == capacity_) {
		// need to update capacity
		vector<T>::increase_capacity();
	}
	data_[size_] = val;
	size_++;
}

template<class T>
void vector<T>::pop_back(T val) {
	size_--;
}



// Destructor

template<class T> 
vector<T>::~vector() {
	delete[] data_;
}



template<class T>
void vector<T>::increase_capacity() {
	capacity_ *= UPDATE_FACTOR;
	T* tempData = new T[capacity_];

	for (int i = 0; i < size_; i++) {
		tempData[i] = data_[i];
	}

	delete[] data_;
	data_ = tempData;
}
