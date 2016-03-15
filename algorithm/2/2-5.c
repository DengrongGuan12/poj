#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int result = 0;
	int i = 1,j=1;
	for(i = 1;i<=n;i++){
		int tmp = 1;
		for(j = 1;j<=i;j++){
			tmp = tmp*j;
		}
		result += tmp;
	}
	printf("%d\n", result % 1000000);

}