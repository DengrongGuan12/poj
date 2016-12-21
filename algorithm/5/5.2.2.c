#include<stdio.h>
#include<string.h>
//计算一个数的阶乘
const int maxn = 3000;
int f[maxn];
int main(){
  int d,i,j,m,c=0;//c记录进位信息
  scanf("%d", &d);
  memset(f,0,sizeof(f));
  f[0] = 1;
  for(i = 2;i<=d;i++){
    c = 0;
    for(j = 0;j<maxn;j++){
      int m = f[j]*i + c;
      c = m/10;
      f[j] = m%10;
    }
  }
  for(i=maxn-1;i>=0;i--){
    if(f[i]){
      break;
    }
  }
  for(j=i;j>=0;j--){
    printf("%d",f[j]);
  }
  return 0;

}
