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
//    if(place==1)//���뵽ͷ��� ���⴦��
//    {
//        s=(clinkNode *)malloc(sizeof (clinkNode));
//        if(!s) exit(0);
//        s->data=num;
//        for(rear=*p;rear->next!=*p;rear=rear->next);//�ҵ�β�ڵ�
//
//        s->next=*p;
//        rear->next=s;
//        *p=s;//ע��Ҫ��ֵ����
//    }
//}

void Delete(clinkNode **p,int num)
{
    clinkNode *s,*r;
    s=*p;
    for(s;s->next->data!=num&&s->next!=*p;s=s->next);//�ҵ�ɾ��ָ���ǰһ��ָ��
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
    for(i=k%j-1,j;j>0;)//��������0ʱֹͣѭ��
    {
        for(i;i>0;--i)
        {
            s=s->next;
            k=s->data;
            o=s->next->next;//�ҵ���Ӧ��ָ�뼰������
        }
    printf("%d\t", s->num);//��ӡ����
    i=k%(--j);//���¸�ֵi
    Delete(s,k);//ɾ���ýڵ�
    s=o;//��s������һ��ָ��
    }
}

int main()
{
    clinkNode *head=NULL;
    CreatClLinkList(&head);//����һ��ձ�
    printf("����ԭʼ����");//ԭʼ���� n=7����������Ϊ3,1,7,2,4,8,4
    show(head);//�������ԭʼ����
    Joseph(&head,20,7);//Լɪ��
}
