#include <stdio.h>
int main(){
  int start,end=999;
  for(start=100;start<=999;start++){
    int a = start%10;
    int tmp = start/10;
    int b = tmp%10;
    tmp = tmp/10;
    int c = tmp%10;
    if(start == (a*a*a+b*b*b+c*c*c)){
      printf("%d\n",start );
    }
  }
  return 0;
}
