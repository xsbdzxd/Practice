#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*ʵ������ľ͵�����*/

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
        p=(Linklist *)malloc(sizeof(Linklist));//����ռ�
        if(p==NULL)//����ʧ��
        {
            printf("error\n");
            return ;
        }
        else
        {
            scanf("%d", &p->data);
            getchar();
        }
        if(head==NULL)//�ж��Ƿ�Ϊ�ձ�
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
    printf("��������ĳ��ȣ�\n");
    scanf("%d", &n);
    printf("��������\n");
    head = creatlist(n);
    printf("ԭʼ����Ϊ:\n");
    print_List(head);
    printf("���ú������Ϊ��\n");
    Ihead = Inversion_List(head);
    print_List(Ihead);
}
