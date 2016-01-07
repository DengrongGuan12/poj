#include <stdio.h>
int main(){
	double sum;
	double tmp;
	int i = 0;
	while(i < 12){
		scanf("%lf",&tmp);
		sum += tmp;
		i++;
	}
	sum = sum/12;
	printf("$%.2f\n", sum);

}