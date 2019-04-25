#include <stdio.h>
#include <stdlib.h>
//伪代码
//运用递归判断是否为完全二叉树

int check(){
    if (root == NULL);
    return 0;

    if(root->lchild == NULL&&root->rchild->NULL)
        renturn 1;

    return check(root->lchild) & check (root->rchild);

}
