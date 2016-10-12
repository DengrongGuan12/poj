#include <assert.h>
#include "CLibArray.h"

int main() {
	CArray array;
	array_initial(array);

	array_recap(array, 10); //重新定义数组容量
	assert(array_capacity(array) == 10);

	for (int i = 0; i < 20; ++i) {
		array_append(array, i); //增加元素
	}
	assert(array_size(array) == 20);
	array_printer(array);

	for (int i = 0; i < array_size(array); ++i) {
		assert(array_at(array, i) == i);//array_at:返回在位置i的元素 
	}
	array_printer(array);

	CArray array2, array3;
	array_initial(array2);
	array_initial(array3);

	array_copy(array, array2); //将array拷贝到array2
	assert(array_compare(array, array2) == true);
	array_copy(array, array3);
	assert(array_compare(array, array3) == true);

	array_printer(array);

	array_insert(array2, 2, 3); //在array2 index=2的位置插入元素3
	assert(array_compare(array, array2) == false);

	array_at(array3, 2) = 5;
	assert(array_compare(array, array3) == false);

	array_destroy(array);
	array_destroy(array2);
	array_destroy(array3);

	printf("Successfully.\n");
	return 0;
}
