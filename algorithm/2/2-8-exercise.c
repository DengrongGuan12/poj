#include <stdio.h>
int main(){
  double n,m,k,result=0;
  scanf("%lf%lf",&n,&m);
  for (k = n; k <= m; k=k+1) {
    result+=1/(k*k);
  }
  printf("%.5lf\n",result );
  return 0;
}
