#include <stdio.h>
#include <math.h>
int main(){
  double a,b;
  int c,k,i=0;
  scanf("%lf%lf%d",&a,&b,&c);
  double tmp,m=1.0;
  tmp = a/b;
  for(i=0;i<c;i++){
    m = m*10;
  }
  k = round(tmp*m);
  printf("%g\n",k/m);
  return 0;
}
