#include<stdio.h>
const int maxn = 50;
int f[maxn];
int main(){
    int n,i = 0;
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    for(i=1;i<=n;i++){
        f[i-1] = i;
    }
    int front = 0;
    int rear = n;
    while(front < rear){
        printf("%d ",f[front++]);
        f[rear++] = f[front++];
    }
    return 0;
}