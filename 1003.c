#include <stdio.h>
int main(){
	double length;
	double sum;
	for(;;){
		scanf("%lf",&length);
		if((length - 0.00)<0.01 && (0.00-length) < 0.01) return 0;
		sum= 0;
		for(int i=2;;i++){
			sum += 1/(double)i;
			if(sum > length){
				printf("%d card(s)\n", i-1 );
				break;
			}
		}
	}
}