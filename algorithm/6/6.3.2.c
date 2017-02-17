// 构造并层次遍历二叉树
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TNode{
    int value;
    int hasValue;
    struct TNode *left;
    struct TNode *right;
} Node;
const int MAXN = 256;//最多结点数
char s[MAXN+10];
Node* root;
int failed = 0;
Node* new_node(){
    Node* n = (Node*)malloc(sizeof(Node));
    if(n != NULL){
        //分配成功
        n->hasValue = 0;
        n->left = n->right = NULL;
    }
    return n;
}
void remove_tree(Node* r){
    if(r == NULL){
        return;
    }
    remove_tree(r->left);
    remove_tree(r->right);
    free(r);
}
void add_node(int v,char* s){
    int l = strlen(s);
    Node* tmp = root;
    for(int i=0;i<l;i++){
        if(s[i] == 'L'){
            if(tmp->left == NULL){
                tmp->left = new_node();
            }
            tmp = tmp->left;
        }else if(s[i] == 'R'){
            if(tmp->right == NULL){
                tmp->right = new_node();
            }
            tmp = tmp->right;
        }
    }
    if(tmp->hasValue)failed = 1;//输入有问题
    tmp->hasValue = 1;
    tmp->value = v;
}
int read_input(){
    //大循环，读取每行的输入，每行构造一棵树
    failed = 0;
    remove_tree(root);
    root = new_node();
    for(;;){
        if(scanf("%s",s) != 1){
            return 0; //整个输入结束
        }
        if(!strcmp(s,"()")){
            break;//单棵树输入结束
        }
        int v;
        sscanf(&s[1],"%d",&v);//读取节点值
        add_node(v,strchr(s,',')+1);//添加节点
    }
    return 1;
}
int n,ans[MAXN];
int BFS(){
    n = 0;
    memset(ans,0,sizeof(ans));
    Node* q[MAXN];
    int front=0,rear = 1;
    q[0] = root;
    while(front < rear){
        Node* p = q[front++];
        if(!p->hasValue){
            return 0;
        }
        ans[n++] = p->value;
        if(p->left != NULL){
            q[rear++] = p->left;
        }
        if(p->right != NULL){
            q[rear++] = p->right;
        }
    }
    return 1;
}
int main(){
    while(read_input()){
        if(failed || !BFS()){
            printf("%d\n",-1);
        }else{
            for(int i = 0;i<n;i++){
                printf("%d ",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

