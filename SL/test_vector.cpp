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


int main() {
	// Test constructors
	test_basic_constr();
	test_fill_constr();
	test_copy_constr();

	// Test Capactiy
	test_size();
	test_capacity();
	test_empty();

	

	return 0;
}

// Test Constructors

void test_basic_constr() {
	printf("Testing basic constructor\n");

	vector<int> vec1;
	assert(vec1.size() == 0);
	assert(vec1.capacity() == 10);
	assert(vec1.empty());

	printf("Passed!\n");
}

void test_fill_constr() {
	printf("Testing fill constructor\n");

	int vecSize = 4;
	int vecValue = 5;

	vector<int> vec2(vecSize, vecValue);
	assert(vec2.size() == vecSize);
	assert(vec2.capacity() == vecSize);
	assert(!vec2.empty());

	for (int i = 0; i < vecSize; i++) {
		assert(vec2[i] == vecValue);
	}

	printf("Passed!\n");
}

void test_copy_constr() {
	printf("Testing copy constructor\n");
	
	int vecSize = 4;
	int vecValue = 5;	
	vector<int> original(vecSize, vecValue);

	vector<int> copy(original);

	assert(copy.size() == vecSize && copy.size() == original.size());
	assert(copy.capacity() == vecSize && copy.capacity() == original.capacity());
	assert(!copy.empty());

	for (int i = 0; i < vecSize; i++) {
		assert(copy[i] == original[i] && copy[i] == vecValue);
	}
	
	printf("Passed!\n");
}

// Test Capacity

void test_size() {
	printf("Testing size\n");

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
	printf("Testing capacity\n");

	printf("Passed!\n");
}

void test_empty() {
	printf("Testing Empty\n");

	printf("Passed!\n");
}

// Test Accessors