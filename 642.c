#include <stdio.h>
#include <stdlib.h>


typedef struct BT{
    char data;
    struct BTNODE *lchild, *rchild;
}BTNODE, *BTREE;


//����������

void creatbtree(BTREE *T){
    char c;
    scanf("%c", &c);
    if(c ==' ')  *T = NULL;
    else{
         *T = (BTREE *)malloc(sizeof(BTNODE));//�������ڵ�
         (*T)->data = c;//��������
         creatbtree(&(*T)->lchild);//�ݹ鴴��������
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
