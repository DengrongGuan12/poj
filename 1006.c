#include <stdio.h>
int main(){
	int p;
	int e;
	int i;
	int d;
	int count = 1;
	int k;
	while(1){
		scanf("%d %d %d %d",&p,&e,&i,&d);
		if(p == -1 && e==-1&&i==-1&&d == -1){
			break;
		}
		for (k = d + 1; k <= 21252 + d; k++) {
            if ((k - p) % 23 == 0
                    && (k - e) % 28 == 0
                    && (k - i) % 33 == 0)
                break;
        }
		
		printf("Case %d: the next triple peak occurs in %d days.\n",count,k-d);
		count++;

	}
	return 0;
}