#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 5000+10
char buf[MAXN],s[MAXN];
int p[MAXN];
int main(){
  int n,m =0, max=0, x,y;
  int i,j;
  fgets(buf,sizeof(buf),stdin);
  n = strlen(buf);
  for(i=0;i<n;i++){
    if(isalpha(buf[i])){
      p[m] = i;
      s[m++] = toupper(buf[i]);
    }
  }
  for(i=0;i<m;i++){
    
  }
  return 0;
}
