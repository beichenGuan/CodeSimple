#include <stdio.h>
#include <stdlib.h>

typedef struct  LNode
{
	int data;
	struct LNode *next;
}LinkList;

typedef struct DLNode
{
	int data;
	struct DLNode *prior;
	struct DLNode *next;
}DoubleLinkList;

 
 //创建循环单链表
void CreateListR1(LinkList *&L,int a[],int n)
{
	LinkList *r,*s;
	int i;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next=NULL;
	r = L;
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=L;

}


//创建循环双链表
void CreateListR2(DoubleLinkList *&L,int a[],int n)
{
	L=(DoubleLinkList *)malloc(sizeof(DoubleLinkList));
	DoubleLinkList *r,*s;
	L->prior = NULL;
	L->next = NULL;
	r=L;
	int i;
	for(i=0;i<n;i++)
	{
		s=(DoubleLinkList *)malloc(sizeof(DoubleLinkList));
		s->data=a[i];
		r->next=s;
		s->prior=r;
		r=s;
	}
	r->next=L;
	L->prior=r;

}

//输出循环单链表
void DispListR1(LinkList *L)
{
	LinkList *p=L->next;
	while(p!=NULL&&p!=L)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//输出循环双链表
void DispListR2(DoubleLinkList *L)
{
	DoubleLinkList *p=L->next;
	while(p!=NULL&&p!=L)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");

}

//判断带头节点的循环双链表L(含两个以上的节点)是否对称
//返回1为对称，0为不对称
int Equal(DoubleLinkList *L)
{
	int same = 1;//返回标志
	DoubleLinkList *p = L->next;//p指向第一个数据节点
	DoubleLinkList *q = L->prior;//q指向最后数据节点
	while(same==1)
	{
		if(p->data!=q->data)
		{
			same = 0;
		}
		else
		{
			if(p==q||p==q->prior)
			{
				break;
			}
			q=q->prior;//前移
			p=p->next;//后移
		}
	}
	return same;

}


int main()
{
	LinkList *L1;
	int a[3]={1,2,3};
	int n = 3;
	CreateListR1(L1,a,n);
	printf("L1: ");
	DispListR1(L1);

	DoubleLinkList *L2;
	int b[5]={1,2,3,4,1};
	int m = 5;
	CreateListR2(L2,b,m);
	printf("L2: ");
	DispListR2(L2);
	printf("%d \n",Equal(L2));

	return 0;
}