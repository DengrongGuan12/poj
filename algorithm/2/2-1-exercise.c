#include <stdio.h>
int main(){
  int a;
  scanf("%d", &a);
  int s = 0;
  while(a>=1){
    a = a/10;
    s++;
  }
  printf("%d\n",s);
  return 0;
}
