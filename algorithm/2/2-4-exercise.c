#include <stdio.h>
int main(){
  int n,i,k;
  scanf("%d", &n);
  for(i=2*n-1;i>=1;i=i-2){
    int tmp = (2*n-1-i)/2;
    for(k=0;k<tmp;k++){
      printf(" ");
    }
    for (k = 0; k < i; k++) {
      printf("*");
    }
    for(k=0;k<tmp;k++){
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
