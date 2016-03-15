#include <stdio.h>
#include <math.h>
int main(){
	double n;//用double 防止溢出
	scanf("%lf",&n);
	int count = 0;
	while(1){
		if(n == 1){
			break;
		}
		double tmp = n/2;
		if(floor(tmp+0.5) == tmp){
			n = tmp;
		}else{
			n = 3*n+1;
		}
		count++;
	}
	printf("%d\n", count);
	return 0;
}