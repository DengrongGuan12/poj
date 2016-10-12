#include "CLibArray.h"

void array_initial(CArray& array) {
	array.buff = NULL;
	array.capacity = 0;
	array.size = 0;
}

void array_recap(CArray & array, int new_cap) {
	int *buff = new int[new_cap * sizeof(int)];
	if (NULL == buff) {
		printf("memory allocation failed.\n");
		exit(1);
	}
	array.capacity = new_cap;
	for (int i = 0; i < array.size; i++) {
		buff[i] = array.buff[i];
	}
	delete []array.buff;
	array.buff = buff;
	buff = NULL;
}

int array_capacity(CArray & array) {
	return array.capacity;
}

int array_size(CArray & array) {
	return array.size;
}

int& array_at(CArray & array, int index) {
	return array.buff[index];
}

void array_append(CArray & array, int key) {
	if (array.size >= array.capacity) {
		array_recap(array, 2 * array.capacity);
	}
	array.buff[array.size] = key;
	array.size++;
}

void array_copy(CArray & array, CArray & array2) {
	array2.size = array.size;
	array2.capacity = array.capacity;
	if (NULL != array2.buff) {
		delete []array2.buff;
	}

	array2.buff = new int[array.capacity];
	if (NULL == array2.buff) {
		printf("memory allocation failed.\n");
		exit(1);
	}
	for (int i = 0; i < array2.size; i++) {
		array2.buff[i] = array.buff[i];
	}
}

bool array_compare(CArray & array, CArray & array2) {
	if ((array.capacity != array2.capacity) || (array.size != array2.size)) {
		return false;
	}
	for (int i = 0; i < array.size; i++) {
		if (array.buff[i] != array2.buff[i]) return false;
	}
	return true;
}

void array_insert(CArray & array, int index, int key) {
	if (array.size >= array.capacity) {
		array_recap(array, 2 * array.capacity);
	}
	for (int i = array.size - 1; i >= index; i--) {
		array.buff[i + 1] = array.buff[i];
	}
	array.buff[index] = key;
	array.size++;
}

void array_destroy(CArray& array) {
	delete []array.buff;
	array.buff = NULL;
	array.capacity = 0;
	array.size = 0;
}

void array_printer(CArray & array) {
	printf("size: %d\n", array.size);
	printf("capacity: %d\n", array.capacity);
	for (int i = 0; i < array.size; i++)
		printf("%d ", array.buff[i]);
	printf("\n\n");
}
