// vector header file

#ifndef SL_VECTOR_H
#define SL_VECTOR_H

#include <stddef.h>

namespace SL {

template<class T> 
class vector {
public:
	// Constructors
	vector() {
		capacity_ = DEFAULT_SIZE;
		size_ = 0;
		data_ = new T[capacity_];
	}

	vector(const vector &v) {
		capacity_ = v.capacity_;
		size_ = v.size_;
		data_ = new T[capacity_];

		for (int i = 0; i < size_; i++) {
			data_[i] = v.data_[i];
		}		
	}

	vector(size_t length, T val) {
		capacity_ = length;
		size_ = length;
		data_ = new T[capacity_];

		for (int i = 0; i < size_; i++) {
			data_[i] = val;
		}
	}

	// Capacity
	size_t size() {
		return size_;
	}
	
	size_t capacity() {
		return capacity_;
	}
	
	bool empty() {
		return size_ == 0;
	}

	// Accessors
	T& operator[](size_t index) {
		return vector<T>::at(index);
	}

	T& at(size_t index) {
		if (index >= size_) {
			// TODO: Should swap out with exception class
			throw "Out of range exception!";
		}
		return data_[index];		
	}

	T& front() {
		return vector<T>::at(0);
	}

	T& back() {
		return vector<T>::at(size_ - 1);
	}

	// Modifying
	void push_back(T val) {
		if (size_ == capacity_) {
			// need to update capacity
			vector<T>::increase_capacity();
		}
		data_[size_] = val;
		size_++;
	}

	void pop_back() {
		size_--;
		prune_capacity();
	}

	// Destructor
	~vector() {
		delete[] data_;
	}

private:
	const size_t DEFAULT_SIZE = 10;
	const size_t UPDATE_FACTOR = 2;

	size_t capacity_;
	size_t size_;
	T *data_;


	void increase_capacity() {
		int lower_bound = DEFAULT_SIZE;

		while (lower_bound <= capacity_) {
			lower_bound *= UPDATE_FACTOR;
		}

		capacity_ = lower_bound;
		T* temp_data = new T[capacity_];

		for (int i = 0; i < size_; i++) {
			temp_data[i] = data_[i];
		}

		delete[] data_;
		data_ = temp_data;
	}

	void prune_capacity() {
		if (capacity_ > DEFAULT_SIZE && size_ <= capacity_/ (UPDATE_FACTOR*UPDATE_FACTOR)) {

			capacity_ /= UPDATE_FACTOR;
			T* temp_data = new T[capacity_];

			for (int i = 0; i < size_; i++) {
				temp_data[i] = data_[i];
			}

			delete[] data_;
			data_ = temp_data;
		}
	}
};


}
#endif