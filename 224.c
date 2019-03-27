#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define N 10
/*�������һ*/
typedef int ElemType;
typedef struct  linkNode{
    ElemType data;
    struct LinkNode *next;
}linkNode, *LinkList;

linkNode *creatlist(int n)
{
    linkNode *s,*head, *p;
    head = NULL;
    for(int i=0;i<n;i++)
    {
        p=(linkNode *)malloc(sizeof(linkNode));
        if(p==0)
        {
            printf("error.\n");
            exit(1);
        }
        scanf("%d", &p->data);
        getchar();
        if(head==NULL){
            head = p;
            s = head;
        }
        else{
            s->next = p;
            s = p;
        }
    }
    s->next = NULL;
    return head;
}
void print_List(linkNode *p)
{
    linkNode *s;
    linkNode *k,*j;
    s = p;
    while(s)
    {
        k=s;
        j=s->next;
        printf("%d\t", s->data);
        s = s->next;
        if(k->data>j->data){exit(0) ;}//����ǵ������� ���� �˳�
    }
}

//linkNode Init(linkNode *p)
//{
//    p=(linkNode *)malloc(sizeof(linkNode));
//    p = p->next;
//}


linkNode* MergeList(linkNode* p,linkNode* q)
{
	linkNode* dest = NULL;
	linkNode* tmp  = NULL;

	while ( p && q )//������������Ϊ��
	{
		//����������Ŀ�ͷ�ڵ�ֵ��С�Ĵ�ԭ������������ӵ�Ŀ��������
		if (p->data <= q->data)
		{
			tmp = p->next;
			p->next = dest;
			dest = p;
			p = tmp;
		}
		else
		{
			tmp = q->next;
			q->next = dest;
			dest = q;
			q = tmp;
		}
	}
	//����һ��������ʣ��Ԫ��ʱ����ʣ��Ԫ��������ӵ�Ŀ�굥������
	while (p != NULL)
	{
		tmp = p->next;
		p->next = dest;
		dest = p;
		p = tmp;
	}
	while (q != NULL)
	{
		tmp = q->next;
		q->next = dest;
		dest = q;
		q = tmp;
	}
	//���غϲ����Ŀ������
	return dest;
}
int main()
{
    linkNode *m, *n ,*o;
    printf("����ԭʼ����1��\n");
    m = creatlist(5);
    printf("����ԭʼ����2��\n");
    n = creatlist(4);
    printf("ԭʼ����1Ϊ��\n");
    print_List(m);
    printf("\n");
    printf("ԭʼ����2Ϊ��\n");
    print_List(n);
    printf("\n");
    printf("��ֵ�Ӵ�С�����������Ϊ��\n");
    o = MergeList(m,n);
    print_List(o);
}
