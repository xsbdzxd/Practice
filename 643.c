#include <stdio.h>
#include <stdlib.h>


typedef struct BT{
    char data;
    struct BTNODE *lchild, *rchild;
}BTNODE, *BTREE;

void createbtree(BTREE *T){
    char c;
    scanf("%c", &c);
    if(c == ' '){
        *T = NULL ;
    }
    else{
        *T = (BTREE *)malloc (sizeof(BTNODE));
        (*T)->data = c;
        createbtree(&(*T)->lchild);
        createbtree(&(*T)->rchild);
    }
}


void printtree(BTREE *t){
    if(t != NULL){
        printf("%d", t->lchild);
        printtree(t->lchild);
        printtree(t->rchild);
    }
    else{
        printf("error.");
    }
}


BTNODE * Fexchange(BTREE *T){
    if(T != NULL)
        if(T->lchild != NULL||T->rchild != NULL){
            BTREE *p,*q;
            p = Fexchange(T->lchild);
            q = Fexchange(T->rchild);
            T->lchild = q;
            T->rchild = p;
        }
    return T;
}



void Lexchange(BTREE *T){
`   if(T != NULL)
        if(T->lchild != NULL||T->rchild != NULL){
            BTREE *p, *q;
            q = T->rchild;
            p = T->lchild;
            T->lchild = q;
            T->rchild = p;
            Lexchange(T->lchild);
            Lexchange(T->rchild);
        }
}


BTNODE *Mexchange(BTREE *T){
    if(T != NULL)
        if(T->lchild != NULL||T->rchild != NULL){
        BTREE *p,*q;
        p = Mexchange(T->lchild);
        T->rchild = p;
        T->lchild = q;
        q = Mexchange(T->rchild);
    }

    return T;

}



int main(){
    BTREE *T;
    createbtree(&T);
    printtree(T);
    printf("\n");
    Fexchange(T);
    printtree(T);
    printf("\n");
    Lexchange(T);
    printtree(T);
    printf("\n");
    Mexchange(T);
    printtree(T);
    printf("\n");

}
、
