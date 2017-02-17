//根据先序和中序，求后序(先构造二叉树，再后序遍历)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int MAXN = 100;
char f[MAXN];//先
char m[MAXN];//中
typedef struct TNode{
    char v;
    struct TNode *left;
    struct TNode *right;
} Node;
Node* generate(char *f, char *m){
    //构造二叉树
    // printf("%s %s",f,m);
    Node *n = (Node *)malloc(sizeof(Node));
    if(n != NULL){
        n->v = f[0];
        n->left = NULL;
        n->right = NULL;
    }
    int len = strlen(m);
    int p = strchr(m,f[0]) - m;
    if (p > 0 ){
        //有左子树
        // char newm[p];
        char *newm = (char *)malloc(sizeof(char)*p);
        strncpy(newm,m,p);
        n->left = generate(&f[1],newm);
    }
    if (p < len-1){
        //有右子树
        n->right = generate(&f[1+p],&m[p+1]);
    }
    return n;

}
void lastThrough(Node* root){
    if(root->left != NULL){
        lastThrough(root->left);
    }
    if(root->right != NULL){
        lastThrough(root->right);
    }
    printf("%c",root->v);
}
void removeTree(Node* root){
    if(root == NULL){
        return;
    }
    removeTree(root->left);
    removeTree(root->right);
    free(root);
}
Node* root;
int main(){
    for(;;){
        if(scanf("%s",f) != 1){
            break;
        }
        scanf("%s",m);
        root = generate(f,m);
        lastThrough(root);
        removeTree(root);
    }
    return 0;
}
