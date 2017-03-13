#include<stdio.h>
#define MAXN 1000
int kth = 0;
char A[MAXN] = {'A'};
void dfs(int cur,int l,int n){
    if(cur > 0){
        //已经是一个困难串了
        kth++;
        if(kth == n){
            for(int i = 0;i<cur;i++){
                printf("%c",A[i]);
            }
            printf("\n");
            return;
        }
    }
    for(int i = 0;i<l;i++){
        A[cur] = 'A'+i;
        //判断是否还是困难串
        int ok = 1;//是困难串
        for(int j=1;j*2<=cur+1;j++){
            //j表示可能对的重复串长度
            int equal = 1;
            for(int k = cur-j*2+1;k<=cur-j;k++){
                if(A[k] != A[k+j]){
                    equal = 0;
                    break;
                }
            }
            if(equal == 1){
                ok = 0;
                break;
            }
            // int tail = cur;
            // int head = cur - j*2+1;
            // while(head < tail){
            //     if(A[head] == A[tail]){
            //         head++;
            //         tail--;
            //     }else{
            //         break;
            //     }
            // }
            // if(head > tail){
            //     ok = 0;//包含重复串
            //     break;
            // }
        }
        if(ok){
            dfs(cur+1,l,n);
        }
    }
}
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    dfs(0,l,n);
    return 0;
}