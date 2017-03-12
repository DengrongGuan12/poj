#include<stdio.h>
#define MAXN 100
int vis[3][MAXN]={0};
int C[MAXN];
int tot = 0;
void search(int cur,int n){
    if(cur == n){
        tot++;
    }else{
        for(int i = 0;i<n;i++){
            if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]){
                //主对角线行列和相同，副对角线行列差相同
                C[cur] = i;
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
                search(cur+1,n);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    search(0,n);
    printf("%d\n",tot);
    return 0;
}