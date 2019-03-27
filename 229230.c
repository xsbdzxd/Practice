#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 10
typedef int ElemType;
typedef struct  ClinkNode{
    ElemType data;
    ElemType num;
    struct ClinkNode *next;
}clinkNode, *ClLinkList;

void CreatClLinkList(clinkNode **p)
{
    clinkNode *rear,*s;
    rear=p;
    int flag=1;
    int x;
    static int i=0;
    printf("Please input data and enter 0 end :\n");
    while(flag)
    {
        scanf("%d",&x);
        if(x==0) return ;
        if(*p==NULL)
        {
            *p=(clinkNode *)malloc(sizeof(clinkNode));
            if(!*p)exit(0);
            (*p)->data=x;
            (*p)->next=*p;
            (*p)->num=++i;

        }
        else
        {
            for(rear=*p;rear->next!=*p;rear=rear->next);
            s=(clinkNode *)malloc(sizeof(clinkNode));
        }
        if(!s)exit(0);
        s->data=x;
        s->num=i++;
        s->next=*p;
        rear->next=s;
    }
}

void show(clinkNode *p)
{
    clinkNode *s;
    s=p;
    do
    {
        printf("%d(%d)", s->data,s->num);
        s=s->next;
    }
    while(s!=p);

    printf("\n");
}

//void insert(clinkNode **p,int place ,int num)
//{
//    clinkNode *rear,*s;
//    if(place==1)//插入到头结点 特殊处理
//    {
//        s=(clinkNode *)malloc(sizeof (clinkNode));
//        if(!s) exit(0);
//        s->data=num;
//        for(rear=*p;rear->next!=*p;rear=rear->next);//找到尾节点
//
//        s->next=*p;
//        rear->next=s;
//        *p=s;//注意要赋值！！
//    }
//}

void Delete(clinkNode **p,int num)
{
    clinkNode *s,*r;
    s=*p;
    for(s;s->next->data!=num&&s->next!=*p;s=s->next);//找到删除指针的前一个指针
        if(s->next->data!=num) printf("error\n");
        r=s->next;
        s->next=r->next;
        free(r);
}

void Joseph(clinkNode **p,int m,int n)
{
    int j=n,k=m;
    int i=k%j-1;
    clinkNode *s,*o;
    s= *p;
    for(i=k%j-1,j;j>0;)//人数等于0时停止循环
    {
        for(i;i>0;--i)
        {
            s=s->next;
            k=s->data;
            o=s->next->next;//找到相应的指针及其密码
        }
    printf("%d\t", s->num);//打印密码
    i=k%(--j);//重新赋值i
    Delete(s,k);//删除该节点
    s=o;//将s移向下一个指针
    }
}

int main()
{
    clinkNode *head=NULL;
    CreatClLinkList(&head);//创建一歌空表
    printf("输入原始链表");//原始链表 n=7，密码依次为3,1,7,2,4,8,4
    show(head);//遍历输出原始链表
    Joseph(&head,20,7);//约瑟夫环
}
