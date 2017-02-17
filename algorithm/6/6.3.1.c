#include<stdio.h>

const int MAXD = 20;
int s[1<<MAXD];
int main(){
    // I个小球依次滚落D层的树,根据节点状态来确定往左还是往右
    int D,I;
    memset(s,0,sizeof(s));
    while(scanf("%d%d",&D,&I) == 2){
        int last = 1<<(D-1);
        // printf("%d",last);
        int start = 1;
        for(int i=1;i<=I;i++){
            start = 1;
            while(start<last){
                if(s[start] == 0){
                    s[start] = 1;
                    start = start*2;
                }else{
                    s[start] = 0;
                    start = start*2+1;
                }
            }
        }
        printf("%d\n",start);
        memset(s,0,sizeof(s));
    }
    return 0;
}