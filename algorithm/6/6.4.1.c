//dfs
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN = 100;
int mat[MAXN][MAXN],vis[MAXN][MAXN];
void dfs(int x,int y){
    if(mat[x][y]&&!vis[x][y]){
        vis[x][y] = 1;
        dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
        dfs(x,y-1);             dfs(x,y+1);
        dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    memset(mat,0,sizeof(mat));
    memset(vis,0,sizeof(vis));
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            int tmp;
            scanf("%d",&tmp);
            mat[i+1][j+1] = tmp;
        }
    }
    int count = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(mat[i][j] && !vis[i][j]){
                count++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",count);
    return 0;
}