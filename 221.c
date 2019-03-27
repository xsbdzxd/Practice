#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*实现链表的就地逆置*/

typedef int ElemType;

typedef struct Linklist{
    ElemType data;
    struct LNode *next;
}Linklist,*LNode;

Linklist *creatlist(int n)
{
    Linklist *s,*head,*p;
    head=NULL;
    for(int i=0;i<n;i++)
    {
        p=(Linklist *)malloc(sizeof(Linklist));//分配空间
        if(p==NULL)//分配失败
        {
            printf("error\n");
            return ;
        }
        else
        {
            scanf("%d", &p->data);
            getchar();
        }
        if(head==NULL)//判断是否为空表
        {
            head = p;
            s = head;
        }
        else
        {
            s->next = p;
            s = p;
        }
    }
    s->next = NULL;
    return head;
}
void print_List(Linklist *p)
{
    Linklist *s;
    s = p;
    while(s!=NULL)
    {
        printf("%d\t", s->data);
        s = s->next;
    }
}

Linklist *Inversion_List(Linklist *p)
{
    Linklist *q,*s;
    s=p;
    q=NULL;
    p=NULL;
    while(s)
    {
        q = s->next;
        s->next = p;
        p = s;
        s = q;
    }
    return p;
}



int main()
{
    Linklist *head, * Ihead;
    int n;
    printf("输入链表的长度：\n");
    scanf("%d", &n);
    printf("输入链表：\n");
    head = creatlist(n);
    printf("原始链表为:\n");
    print_List(head);
    printf("逆置后的链表为：\n");
    Ihead = Inversion_List(head);
    print_List(Ihead);
}
