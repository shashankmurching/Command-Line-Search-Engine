// Vector Test File

#include "vector.h"
#include <stdio.h>
#include <cassert>

using namespace SL;

void test_basic_const();
void test_fill_const();
void test_copy_const();


int main() {
	test_basic_const();
	test_fill_const();
	test_copy_const();
	

	return 0;
}


void test_basic_const() {
	printf("Testing basic constructor\n");

	vector<int> vec1;
	assert(vec1.size() == 0);
	assert(vec1.capacity() == 10);
	assert(vec1.empty());

	printf("Passed!\n");
}

void test_fill_const() {
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

void test_copy_const() {
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
