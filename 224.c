#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define N 10
/*链表二合一*/
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
        if(k->data>j->data){exit(0) ;}//输入非递增链表 错误 退出
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

	while ( p && q )//当两个链表都不为空
	{
		//将两个链表的开头节点值较小的从原链表拆除，并添加到目标链表上
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
	//当有一个链表还有剩余元素时，将剩余元素逆序添加到目标单链表上
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
	//返回合并后的目标链表
	return dest;
}
int main()
{
    linkNode *m, *n ,*o;
    printf("创立原始链表1：\n");
    m = creatlist(5);
    printf("创立原始链表2：\n");
    n = creatlist(4);
    printf("原始链表1为：\n");
    print_List(m);
    printf("\n");
    printf("原始链表2为：\n");
    print_List(n);
    printf("\n");
    printf("按值从大到小排序的新链表为：\n");
    o = MergeList(m,n);
    print_List(o);
}
