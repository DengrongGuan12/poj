// 根据先序和中序直接输出后序
#include<stdio.h>
#include<string.h>
const int MAXN = 256;
char f[MAXN];
char m[MAXN];
char l[MAXN];
void build(int n,char * s1,char *s2,char *s3){
    //n 树的长度 s1先序 s2中序 s3后序
    if(n <=0 ){
        return;
    }
    int p = strchr(s2,s1[0])-s2;
    build(p,s1+1,s2,s3);
    build(n-p-1,s1+1+p,s2+p+1,s3+p);
    s3[n-1] = s1[0];
}
int main(){
    while(scanf("%s %s",f,m) == 2){
        int len = strlen(f);
        build(len,f,m,l);
        l[len] = '\0';
        printf("%s\n",l);
    }
    return 0;
}