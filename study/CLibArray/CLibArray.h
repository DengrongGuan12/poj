#include<stdlib.h>
#include<stdio.h>

struct CArray {
	int *buff;
	int size;
	int capacity;
};

void array_initial(CArray& array);
void array_recap(CArray& array, int new_cap);
int array_capacity(CArray& array);
int array_size(CArray& array);
int& array_at(CArray& array, int index);
void array_append(CArray& array, int key);
void array_copy(CArray& array, CArray& array2);
bool array_compare(CArray& array, CArray& array2);
void array_insert(CArray& array, int index, int key);
void array_destroy(CArray& array);
void array_printer(CArray& array);