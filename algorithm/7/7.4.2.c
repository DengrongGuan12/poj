//素数环问题，使用回溯法（只需要位置参数）
#include<stdio.h>
#include<math.h>
#define MAXN 100
int A[MAXN];
int vis[MAXN] = {0};
int isp(int a){
    int k = sqrt(a);
    for(int i = 2;i<=k;i++){
        if(a%i == 0){
            return 0;
        }
    }
    return 1;
}
void dfs(int cur,int n){
    if(cur == n && isp(A[0]+A[n-1])){
        for(int i = 0;i<n;i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }else{
        for(int i = 2;i<=n;i++){
            if(!vis[i]&&isp(A[cur-1]+i)){
                vis[i] = 1;
                A[cur] = i;
                dfs(cur+1,n);
                vis[i] = 0;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    A[0] = 1;
    dfs(1,n);
    return 0;
}