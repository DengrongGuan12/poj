#include <stdio.h>
int main(){
	int a = 1000000;
	int max = 0;
	while(a>0){
		max = a;
		a++;
	}
	a = -1000000;
	int min = 0;
	while(a<0){
		min = a;
		a--;
	}
	printf("max: %d\n", max);
	printf("min: %d\n", min);
	return 0;
}