#include <stdio.h>
#include <stdlib.h>


typedef struct BT{
    char data;
    struct BTNODE *lchild, *rchild;
}BTNODE, *BTREE;


//创建二叉树

void creatbtree(BTREE *T){
    char c;
    scanf("%c", &c);
    if(c ==' ')  *T = NULL;
    else{
         *T = (BTREE *)malloc(sizeof(BTNODE));//创建根节点
         (*T)->data = c;//输入数据
         creatbtree(&(*T)->lchild);//递归创建左子树
         creatbtree(&(*T)->rchild));
    }
}


int getleavescount(BTREE T){
    int Lleavescount ;
    int Rleavescount ;
    if(T == NULL){
        return 0;
    }
    else if(T->lchild ==NULL && T->rchild == NULL){
        return 1;
    }
    else{
        Lleavescount = getleavescount(T->lchild);
        Rleavescount = getleavescount(T->rchild);
        return Lleavescount + Rleavescount ;
    }
}


int main(){
    BTREE T = NULL;
    int count = 0;
    printf("input some characters to create a binary tree");
    creatbtree(&T);
    count = getleavescount(T);
    printf("The number of leaves of BTREE are %d \n", count );
    getchar();
    getchar();

}
