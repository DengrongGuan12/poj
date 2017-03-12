//八皇后问题
#include<stdio.h>
#define MAXN 100
int tot = 0;
int C[MAXN];
void search(int cur,int n){
    if(cur == n){
        tot++;
    }else{
        for(int i = 0;i<n;i++){
            int ok = 1;
            C[cur] = i;
            for(int j= 0;j<cur;j++){
                if(C[cur] == C[j] || C[cur]-C[j] == cur-j || cur-j == C[j]-C[cur]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                search(cur+1,n);
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