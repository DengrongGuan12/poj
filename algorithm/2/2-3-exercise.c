#include <stdio.h>
int main(){
  int a,b,c,k;
  scanf("%d%d%d",&a,&b,&c);
  for(k=10;k<=100;k++){
    if( (k-a)%3 == 0 && (k-b)%5 == 0 && (k-c)%7 == 0){
      printf("%d\n",k);
      break;
    }
  }
  if(k>100){
    printf("No answer\n");
  }
  return 0;
}
