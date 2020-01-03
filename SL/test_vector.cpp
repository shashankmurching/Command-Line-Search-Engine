// Vector Test File

#include "vector.h"
#include <stdio.h>
#include <cassert>

using namespace SL;

void test_basic_constr();
void test_fill_constr();
void test_copy_constr();

void test_size();
void test_capacity();
void test_empty();
void test_resize();
void test_resize_val();
void test_reserve();
void test_shrink_to_fit();

void test_index_operator();
void test_at();
void test_front();
void test_back();
void test_data();
void test_data_const();

void test_push_back();
void test_pop_back();

template<class T>
void test_destructor_helper(T* data, unsigned long length, T val);
void test_destructor();

void test_begin();
void test_end();
void test_iterator_incr();
void test_iterator_equal();
void test_iterator_neq();
void test_iterator_deref();

enum Func { op, at, front, back };

template<class T>
void index_error_checker(Func type, vector<T> vec, unsigned long index = 0);


const unsigned long default_cap = 0;
const unsigned long ten_iter = 10;
const unsigned long update_factor = 2;


int main() {
	printf("Running vector test cases\n");

	// Test constructors
	test_basic_constr();
	test_fill_constr();
	test_copy_constr();

	// Test Capactiy
	test_size();
	test_capacity();
	test_empty();
	test_resize();
	test_resize_val();
	test_reserve();
	test_shrink_to_fit();

	// Test Accessors
	test_index_operator();
	test_at();
	test_front();
	test_back();
	test_data();
	test_data_const();

	// Test Modifiers
	test_push_back();
	test_pop_back();

	// Test Destructor
	test_destructor();

	// Test Iterators
	test_begin();
	test_end();
	test_iterator_incr();
	test_iterator_equal();
	test_iterator_neq();
	test_iterator_deref();

	printf("All vector test cases passed!\n");
	return 0;
}

// Testing Constructors

void test_basic_constr() {
	printf("Testing basic constructor\n");

	vector<int> vec1;
	assert(vec1.size() == 0);
	assert(vec1.capacity() == default_cap);
	assert(vec1.empty());

	printf("Passed!\n");
}

void test_fill_constr() {
	printf("Testing fill constructor\n");

	int vec_size = 4;
	int vec_value = 5;

	vector<int> vec2(vec_size, vec_value);
	assert(vec2.size() == vec_size);
	assert(vec2.capacity() == vec_size);
	assert(!vec2.empty());

	for (int i = 0; i < vec_size; i++) {
		assert(vec2[i] == vec_value);
	}

	printf("Passed!\n");
}

void test_copy_constr() {
	printf("Testing copy constructor\n");
	
	int vec_size = 4;
	int vec_value = 5;	
	vector<int> original(vec_size, vec_value);

	vector<int> copy(original);

	assert(copy.size() == vec_size && copy.size() == original.size());
	assert(copy.capacity() == vec_size && copy.capacity() == original.capacity());
	assert(!copy.empty());

	for (int i = 0; i < vec_size; i++) {
		assert(copy[i] == original[i] && copy[i] == vec_value);
	}
	
	printf("Passed!\n");
}

// Testing Destructor

template<class T>
void test_destructor_helper(T* ptr, unsigned long length, T val) {
	vector<int> vec(length, val);
	ptr = vec.data();
	assert(ptr != nullptr);
}

void test_destructor() {
	printf("Testing ~vector()\n");

	{
		int vec_size = 10;
		int vec_val = 5;

		int* ptr = nullptr;
		test_destructor_helper(ptr, vec_size, vec_val);
		assert(ptr == nullptr);
	}

	printf("Passed!\n");
}


// Testing Iterators

void test_begin() {
	printf("Testing begin()\n");

	{
		vector<int> vec;
		for (int i = 0; i < ten_iter; i++) {
			vec.push_back(i);
			auto itr = vec.begin();
			assert(*itr == 0);
		}

		auto itr = vec.begin();
		for (int i = 0; i < ten_iter; i++) {
			vec[0] = i;
			assert(*itr == i);
		}
	}

	printf("Passed!\n");
}

void test_end() {
	printf("Testing end()\n");

	{
		vector<int> vec;
		auto begin = vec.begin();
		auto end = vec.end();
		assert(begin == end);

		for (int i = 0; i < 16; i++) {
			vec.push_back(i);
		}

		begin = vec.begin();
		end = vec.end();
		assert(begin != end);

		for (int i = 0; i < 16; i++) {
			begin++;
		}
		assert(begin == end);
	}

	printf("Passed!\n");
}

void test_iterator_incr() {
	printf("Testing iterator++()\n");

	int vector_size = 10;
	
	{
		vector<int> vec;
		vec.reserve(vector_size);

		for (int i = 0; i < vector_size; i++) {
			vec.push_back(i);
		}

		auto itr = vec.begin();
		for (int i = 0; i < vector_size; i++) {
			assert(*itr++ == i);
		}
		assert(itr == vec.end());
	}

	{
		vector<int> vec;
		vec.reserve(vector_size);

		for (int i = 0; i < vector_size; i++) {
			vec.push_back(i);
		}

		auto itr = vec.begin();
		for (int i = 0; i < vector_size; i++) {
			if (i == vector_size - 1) {
				itr++;
			} else {
				assert(*++itr == i + 1);
			}
		}
		assert(itr == vec.end());
	}

	printf("Passed!\n");
}

void test_iterator_equal() {
	printf("Testing Iterator==()\n");
	
	{
		vector<int> vec;
		assert(vec.begin() == vec.end());
	}

	{
		int vector_size = 10;
		vector<int> vec;
		vec.resize(vector_size);

		auto itr = vec.begin();

		for (int i = 0; i < vector_size; i++, itr++) {
			assert(!(itr == vec.end()));
		}
		assert(itr == vec.end());
	}


	printf("Passed!\n");
}

void test_iterator_neq() {
	printf("Testing Iterator!=()\n");
	
	{
		vector<int> vec;
		assert(!(vec.begin() != vec.end()));
	}

	{
		int vector_size = 10;
		vector<int> vec;
		vec.resize(vector_size);

		auto itr = vec.begin();

		for (int i = 0; i < vector_size; i++, itr++) {
			assert(itr != vec.end());
		}
		assert(!(itr != vec.end()));
	}

	printf("Passed!\n");
}

void test_iterator_deref() {
	printf("Testing Iterator*()\n");
	
	{
		vector<int> vec;
		auto itr = vec.begin();
		try {
			*itr;
			assert(false);
		} catch (...) {
			assert(true);
		}
		itr = vec.end();
		try {
			*itr;
			assert(false);
		} catch (...) {
			assert(true);
		}
	}

	{
		int vector_size = 10;
		vector<int> vec;
		vec.reserve(vector_size);

		for (int i = 0; i < vector_size; i++) {
			vec.push_back(i);
		}

		int val = 0;
		for (auto itr = vec.begin(); itr != vec.end(); itr++, val++) {
			assert(*itr == val);
		}
	}

	{
		vector<int> vec;
		vec.resize(1);
		auto itr = vec.begin();
		assert(*itr == 0);
		assert(vec.capacity() == 1);
		
		itr++;
		assert(itr == vec.end());		
		
		try {
			*itr;
			assert(false);
		} catch (...) {
			assert(true);
		}
	}

	printf("Passed!\n");
}

// Testing Capacity

void test_size() {
	printf("Testing size()\n");

	vector<int> vec;
	assert(vec.size() == 0);

	int size = 30;

	for (int i = 1; i <= size; i++) {
		vec.push_back(i);
		assert(vec.size() == i);
	}

	for (int i = size - 1; i >= 0; i--) {
		vec.pop_back();
		assert(vec.size() == i);
	}

	printf("Passed!\n");
}

void test_capacity() {
	printf("Testing capacity()\n");
	{
		vector<int> vec;
		assert(vec.capacity() == default_cap);

		for (int i = 0; i < 10; i++) {
			int increase_factor = 1 << i;
			int current_size = vec.size();

			for (int j = current_size; j < increase_factor; j++) {
				vec.push_back(1);
				assert(vec.capacity() == increase_factor);
			}
		}

		for (int i = 0; i < 10; i++) {
			int lower_bound = vec.capacity() / (update_factor * update_factor);
			int current_size = vec.size();
			int current_capacity = vec.capacity();

			for (int j = current_size; j > lower_bound; j--) {
				vec.pop_back();
				int calc_capacity = (vec.size() <= lower_bound) 
										? current_capacity / update_factor
										: current_capacity;

				assert(vec.capacity() == calc_capacity);
			}
		}
	}

	{
		for (int i = 1; i < 50; i++) {
			vector<int> vec(i, i);
			assert(vec.capacity() == i);

			int calc_capacity = 1;
			while (calc_capacity <= i) {
				calc_capacity *= update_factor;
			}

			vec.push_back(1);
			assert(vec.capacity() == calc_capacity);

			vector<int> copy(vec);
			assert(copy.capacity() == calc_capacity);
		}
	}

	printf("Passed!\n");
}

void test_empty() {
	printf("Testing empty()\n");
	
	{
		vector<int> vec;
		assert(vec.empty());

		for (int i = 0; i < 10; i++) {
			vec.push_back(i);
			assert(!vec.empty());
		}

		for (int i = 1; i < 10; i++) {
			vec.pop_back();
			assert(!vec.empty());
		}

		vec.pop_back();
		assert(vec.empty());
	}

	{
		for (int i = 0; i < 10; i++) {
			vector<int> vec(1, i);
			assert(!vec.empty());

			vector<int> copy(vec);
			assert(!copy.empty());
		}
	}

	printf("Passed!\n");
}

void test_resize() {
	printf("Testing resize()\n");

	{
		vector<int> vec;
		assert(vec.capacity() == default_cap);
		assert(vec.empty());

		vec.resize(0);
		assert(vec.capacity() == default_cap);
		assert(vec.empty());

		int resize_max = 30;

		for (int i = 1; i <= resize_max; i++) {
			vec.resize(i);

			int calc_capacity = i;
			assert(vec.capacity() == calc_capacity);
			assert(vec.size() == i);

			for (int j = 0; j < i; j++) {
				assert(vec[j] == 0);
			}
		}

		for (int i = resize_max; i >= 0; i--) {
			vec.resize(i);
			assert(vec.capacity() == i);
			assert(vec.size() == i);

			for (int j = 0; j < i; j++) {
				assert(vec[j] == 0);
			}
		}
	} 

	{
		vector<int> vec;

		int resize_length = 5;
		vec.resize(resize_length);

		assert(vec.size() == 5);
		assert(vec.capacity() == 5);
	}

	printf("Passed!\n");
}

void test_resize_val() {
	printf("Testing resize(T)\n");

	{
		vector<int> vec;
		assert(vec.capacity() == default_cap);
		assert(vec.empty());

		vec.resize(0, 1);
		assert(vec.capacity() == default_cap);
		assert(vec.empty());

		int resize_max = 30;

		for (int i = 1; i <= resize_max; i++) {
			vec.resize(i, i);

			int calc_capacity = i;
			assert(vec.capacity() == calc_capacity);
			assert(vec.size() == i);

			for (int j = 0; j < i; j++) {
				assert(vec[j] == j + 1);
			}
		}

		for (int i = resize_max; i >= 0; i--) {
			vec.resize(i, i);
			assert(vec.capacity() == i);
			assert(vec.size() == i);

			for (int j = 0; j < i; j++) {
				assert(vec[j] == j + 1);
			}
		}
	} 

	{
		vector<int> vec;

		int resize_length = 5;
		vec.resize(resize_length, 1);

		assert(vec.size() == 5);
		assert(vec.capacity() == 5);

		for (int i = 0; i < resize_length; i++) {
			assert(vec[i] == 1);
		}
	}

	printf("Passed!\n");
}

void test_reserve() {
	printf("Testing reserve()\n");

	{
		vector<int> vec;

		for (int i = 0; i < 20; i++) {
			vec.reserve(i);
			assert(vec.capacity() == i);
		}		
	}

	{
		vector<int> vec;

		int val_count = 35;
		int upper_bound = 64;
		int reserve_bound = 70;

		for (int i = 0; i < val_count; i++) {
			vec.push_back(i);
		}
		
		assert(vec.capacity() == upper_bound);
		assert(vec.size() == val_count);


		for (int i = 1; i < reserve_bound; i++) {
			int calc_capacity = (i < upper_bound) ? upper_bound : i;
			vec.reserve(i);

			assert(vec.capacity() == calc_capacity);
			assert(vec.size() == val_count);

			for (int j = 0; j < val_count; j++) {
				assert(vec[j] == j);
			}
		}
	}

	printf("Passed!\n");
}

void test_shrink_to_fit() {
	printf("Testing shrink_to_fit()\n");

	{
		vector<int> vec;
		assert(vec.capacity() == default_cap);
		vec.shrink_to_fit();
		assert(vec.capacity() == default_cap);
	}

	{
		int vec_capacity = 100;
		int vec_size = 90;

		for (int i = vec_size; i < vec_capacity; i++) {
			vector<int> vec;
			vec.reserve(vec_capacity);
			assert(vec.capacity() == vec_capacity);

			for (int j = 0; j < vec_size; j++) {
				vec.push_back(j);
			}
			assert(vec.capacity() == vec_capacity);
			assert(vec.size() == vec_size);

			vec.shrink_to_fit();
			assert(vec.capacity() == vec_capacity);
		}
	}

	{
		int vec_capacity = 1024;

		for (int i = 0; i < vec_capacity; i++) {
			vector<int> vec;
			assert(vec.capacity() == default_cap);
			assert(vec.empty());

			vec.reserve(vec_capacity);
			assert(vec.capacity() == vec_capacity);
			assert(vec.empty());

			vec.resize(i);
			assert(vec.capacity() == vec_capacity);
			assert(vec.size() == i);

			vec.shrink_to_fit();

			unsigned long lower_bound = 1;
			while (lower_bound <= i) {
				lower_bound *= update_factor;
			}

			if (lower_bound < vec_capacity) {
				assert(vec.capacity() == lower_bound);
				assert(vec.size() == i);
			} else {
				assert(vec.capacity() == vec_capacity);
				assert(vec.size() == i);				
			}
		}
	}

	printf("Passed!\n");
}

// Testing Accessors

void test_index_operator() {
	printf("Testing operator[]\n");

	vector<int> vec;

	index_error_checker(op, vec, -1);
	index_error_checker(op, vec, 0);
	index_error_checker(op, vec, -1);

	for (int i = 0; i < 50; i++) {
		vec.push_back(i);
		assert(vec[i] == i);
		index_error_checker(op, vec, i + 1);
	}

	printf("Passed!\n");
}

void test_at() {
	printf("Testing at()\n");

	vector<int> vec;

	index_error_checker(at, vec, -1);
	index_error_checker(at, vec, 0);
	index_error_checker(at, vec, -1);

	for (int i = 0; i < 50; i++) {
		vec.push_back(i);
		assert(vec.at(i) == i);
		index_error_checker(at, vec, i + 1);
	}

	printf("Passed!\n");
}

void test_front() {
	printf("Testing front()\n");

	vector<int> vec;

	index_error_checker(front, vec);

	for (int i = 0; i < 50; i++) {
		vec.push_back(i);
		assert(vec.front() == 0);
	}

	for (int i = 1; i < 50; i++) {
		vec.pop_back();
		assert(vec.front() == 0);
	}

	vec.pop_back();
	index_error_checker(front, vec);

	printf("Passed!\n");
}

void test_back() {
	printf("Testing back()\n");

	vector<int> vec;

	index_error_checker(back, vec);

	for (int i = 0; i < 50; i++) {
		vec.push_back(i);
		assert(vec.back() == i);
	}

	for (int i = 49; i > 0; i--) {
		assert(vec.back() == i);
		vec.pop_back();
		assert(vec.back() == i - 1);
	}

	vec.pop_back();
	index_error_checker(back, vec);

	printf("Passed!\n");
}

void test_data() {
	printf("Testing data()\n");

	{
		int vec_capacity = 100;

		vector<int> vec;
		vec.reserve(vec_capacity);

		for (int i = 0; i < vec_capacity; i++) {
			vec.push_back(i);
		}

		int* data = vec.data();
		for (int i = 0; i < vec_capacity; i++) {
			assert(data[i] == i);
		}

		for (int i = 0; i < vec_capacity; i++) {
			data[i] = i + vec_capacity;
		}

		for (int i = 0; i < vec_capacity; i++) {
			assert(data[i] == i + vec_capacity);
			assert(vec[i] == i + vec_capacity);
		}
	}

	printf("Passed!\n");
}

void test_data_const() {
	printf("Testing data() const\n");

	{
		int vec_capacity = 100;

		vector<int> vec;
		vec.reserve(vec_capacity);

		for (int i = 0; i < vec_capacity; i++) {
			vec.push_back(i);
		}

		const int* data = vec.data();
		for (int i = 0; i < vec_capacity; i++) {
			assert(data[i] == i);
		}

		for (int i = 0; i < vec_capacity; i++) {
			vec[i] = i + vec_capacity;
		}

		for (int i = 0; i < vec_capacity; i++) {
			assert(data[i] == i + vec_capacity);
		}
	}

	printf("Passed!\n");
}


// Testing Modifiers

void test_push_back() {
	printf("Testing push_back()\n");

	{
		vector<int> vec;
		int size = 0;

		for (int i = 0; i < 10; i++) {
			vec.push_back(i);
			assert(vec[i] == i);
			assert(vec.size() == size + 1);
			size += 1;
		}
	}

	{
		int vec_size = 10;
		vector<int> vec(vec_size, 0);
		vec.push_back(1);
		assert(vec[vec_size] == 1);
	}

	printf("Passed!\n");
}

void test_pop_back() {
	printf("Testing pop_back()\n");

	// Functionality is also tested through test_size() and test_capacity()
	vector<int> vec(10, 1);

	for (int i = 10; i > 0; i--) {
		assert(vec.size() == i);
		vec.pop_back();
		assert(vec.size() == i - 1);
	}

	assert(vec.empty());

	try {
		vec.pop_back();
		assert(false);
	} catch (...) { // Change to specific error class
		assert(true);
	}

	printf("Passed!\n");
}




template<class T>
void index_error_checker(Func type, vector<T> vec, unsigned long index) {
	try {
		int val = 0;
		switch(type) {
			case op:
				val = vec[index];
				break;
			case at:
				val = vec.at(index);
				break;
			case front:
				val = vec.front();
				break;
			case back:
				val = vec.back();
		}
		assert(false);
	} catch (...) {
		assert(true);
	}
}
