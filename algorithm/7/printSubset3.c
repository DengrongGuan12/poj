#include<stdio.h>
// 使用二进制法打印集合的子集
void print_subset(int n,int s){
    //只是用于打印，而打印什么内容s已经指出了，s的对应位为1则表示要打印，0表示不用打印
    for(int i = 0;i<n;i++){
        if(s&(1<<i)) printf("%d ",i);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<(1<<n);i++){
        print_subset(n,i);
    }
    return 0;
}