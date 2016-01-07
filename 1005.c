#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
double calSquare(double x, double y){
	double r2 = x*x+y*y;
	return M_PI*r2/2;

}
int main(){
	int n;
	double x;
	double y;
	scanf("%d",&n);
	int i = 0;
	while( i < n){
		scanf("%lf",&x);
		scanf("%lf",&y);
		int year = 1;
		while(1){
			if(calSquare(x,y) < (50*year)){
				printf("Property %d: This property will begin eroding in year %d.\n",i+1,year);
				break;
			}
			year++;
		}
		i++;
	}
	printf("END OF OUTPUT.\n");

}