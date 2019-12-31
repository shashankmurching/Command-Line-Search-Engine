// vector header file

#ifndef SL_VECTOR_H
#define SL_VECTOR_H

#include <stdio.h>

namespace SL {

template<class T> 
class vector {
public:
	// Constructors
	vector() {
		capacity_ = 0;
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

	vector(unsigned long length, T val) {
		capacity_ = length;
		size_ = length;
		data_ = new T[capacity_];

		for (int i = 0; i < size_; i++) {
			data_[i] = val;
		}
	}

	// Capacity
	unsigned long size() {
		return size_;
	}
	
	unsigned long capacity() {
		return capacity_;
	}
	
	bool empty() {
		return size_ == 0;
	}

	void resize(unsigned long n) {
		T def_val = T{};
		resize(n, def_val);
	}

	void resize(unsigned long n, const T& val) {
		if (n < size_) {
			capacity_ = n;
			size_ = n;
			T* temp_data = new T[capacity_];

			for (int i = 0; i < n; i++) {
				temp_data[i] = data_[i];
			}

			delete[] data_;
			data_ = temp_data;
		
		} else if (n > size_) {
			if (n > capacity_) {
				capacity_ = n;
				T* temp_data = new T[capacity_];

				for (int i = 0; i < size_; i++) {
					temp_data[i] = data_[i];
				}

				delete[] data_;
				data_ = temp_data;
			}
			
			for (int i = size_; i < n; i++) {
				data_[i] = val;
			}

			size_ = n;
		}
	}

	void reserve(unsigned long n) {
		if (n > capacity_) {
			capacity_ = n;
			T* temp_data = new T[capacity_];

			for (int i = 0; i < size_; i++) {
				temp_data[i] = data_[i];
			}

			delete[] data_;
			data_ = temp_data;
		}
	}


	// Accessors
	T& operator[](unsigned long index) {
		return vector<T>::at(index);
	}

	T& at(unsigned long index) {
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
		if (empty()) {
			throw "Cannot pop_back on empty vector!";
		}
		size_--;
		prune_capacity();
	}

	// Destructor
	~vector() {
		delete[] data_;
		data_ = nullptr;
	}

	class Iterator {
	public:
		Iterator() : data_(nullptr), capacity_(0), index_(0) {}

		// Pre increment op
		//increment before doing op

		Iterator& operator++() {
			index_ += 1;
			return *this;
		}

		// Post increment
		// increment after doing op

		Iterator operator++(int) {
			Iterator temp(data_, capacity_, index_);
			index_ += 1;
			return temp;
		}

		bool operator==(const Iterator &other) {
			printf("index: %lu adn other index: %lu\n", index_, other.index_);

			return data_ == other.data_ 
					&& capacity_ == other.capacity_ 
					&& index_ == other.index_;
		}

		bool operator!=(const Iterator &other) {
			return !(*this == other);
		}

		T operator*() {
			if (data_ == nullptr || index_ >= capacity_) {
				throw "Dereferencing vector iterator out of bounds";
			}
			return data_[index_];
		}

	private:
		unsigned long capacity_;
		unsigned long index_;
		T* data_;

		Iterator(T* data, unsigned long capacity, unsigned long index) : 
				capacity_(capacity), index_(index), data_(data) {}

		friend class vector;
	};


	Iterator begin() {
		return Iterator(data_, capacity_, 0);
	}

	Iterator end() {
		return Iterator(data_, capacity_, capacity_);
	}


private:
	const unsigned long LOWEST_SIZE = 1;
	const unsigned long UPDATE_FACTOR = 2;

	unsigned long capacity_;
	unsigned long size_;
	T *data_;


	void increase_capacity() {
		int lower_bound = LOWEST_SIZE;

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
		if (capacity_ > LOWEST_SIZE && size_ <= capacity_/ (UPDATE_FACTOR*UPDATE_FACTOR)) {

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