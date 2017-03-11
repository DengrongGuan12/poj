#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 输出字典序（由0和1组成）中的第k个元素
int K = 1;
void gen(int n,int m,char* s, int kth){
    if(n == 0){
        char* newStr = (char*)malloc(strlen(s)+m+1);
        strcpy(newStr,s);
        int i;
        for(i=strlen(s);i<strlen(s)+m;i++){
            newStr[i] = '1';
        }
        newStr[i] = '\0';
        if(K == kth){
            printf("%s\n",newStr);
        }
        K++;
        // free(s);
        // free(newStr);
    }else if(m == 0){
        char* newStr = (char*)malloc(strlen(s)+n+1);
        strcpy(newStr,s);
        int i;
        for(i=strlen(s);i<strlen(s)+n;i++){
            newStr[i] = '0';
        }
        newStr[i] = '\0';
        if(K == kth){
            printf("%s\n",newStr);
        }
        K++;
        // free(s);
        // free(newStr);
    }else{
        char * newStr1 = (char*)malloc(strlen(s)+2);
        strcpy(newStr1,s);
        newStr1[strlen(s)] = '0';
        newStr1[strlen(s)+1] = '\0';
        char * newStr2 = (char*)malloc(strlen(s)+2);
        strcpy(newStr2,s);
        newStr2[strlen(s)] = '1';
        newStr2[strlen(s)+1] = '\0';
        // free(s);
        gen(n-1,m,newStr1,kth);
        gen(n,m-1,newStr2,kth);
    }
    
}

int main(){
    int c,n,m,k;
    scanf("%d",&c);
    int i = 0;
    
    for(i = 0;i<c;i++){
        scanf("%d%d%d",&n,&m,&k);
        char s[]= {'\0'};
        gen(n,m,s,k);
    }
    return 0;
}