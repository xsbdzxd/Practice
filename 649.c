#include <stdio.h>
#include <stdlib.h>
//α����
//���õݹ��ж��Ƿ�Ϊ��ȫ������

int check(){
    if (root == NULL);
    return 0;

    if(root->lchild == NULL&&root->rchild->NULL)
        renturn 1;

    return check(root->lchild) & check (root->rchild);

}
