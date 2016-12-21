#include<stdio.h>
#include<string.h>
// 找周期串
int main(){
  char word[100];
  scanf("%s",word);
  int length = strlen(word);
  int i;
  for(i = 1;i<=length;i++){
    if(length % i == 0){
      int j;
      int ok = 1;
      for(j = i;j<length;j++){
        if(word[j] != word[j%i]){
          ok = 0;
          break;
        }
      }
      if(ok){
        printf("%d\n",i);
        break;
      }
    }
  }
  return 0;
}
