#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct
{
	int data[MaxSize];
	int length;
}SqList;//顺序表类型

typedef struct LNode
{
	int data;
	LNode *next;
}LinkList;//单链表类型

 
 //创建顺序表
 void CreateSqList(SqList *&L,int a[],int n)
 {
 	L = (SqList *)malloc(sizeof(SqList));
 	int i;
 	for(i=0;i<n;i++)
 	{
 		L->data[i] = a[i];
 	}
 	L->length = n;
 }

 //输出顺序表
 void DispSqList(SqList *L)
 {
 	int i;
 	for(i=0;i<L->length;i++)
 	{
 		printf("%d ", L->data[i]);
 	}
 	printf("\n");
 }

 //荷兰旗排序,顺序表
 void move1(SqList *&L)
 {
 	int i=-1;
 	int j=0;
 	int k=L->length;
 	int tmp;
 	while(j<k)
 	{
 		if(L->data[j] == 0)
 		{
 			i++;
 			tmp = L->data[i];
 			L->data[i] = L->data[j];
 			L->data[j] = tmp;
 			j++;
 		}
 		else if(L->data[j] == 2)
 		{
 			k--;
 			tmp = L->data[k];
 			L->data[k] = L->data[j];
 			L->data[j] = tmp;
 		}
 		else
 		{
 			j++;
 		}
 	}
 }


 //尾插法创建单链表
 void CreateLinkListR(LinkList *&L,int a[],int n)
 {
 	
 	LinkList *r,*s;
 	int i;
 	L = (LinkList *)malloc(sizeof(LinkList));
 	r = L;
 	
 	for(i=0;i<n;i++)
 	{
 		s=(LinkList *)malloc(sizeof(LinkList));
 		s->data=a[i];
 		r->next=s;
 		r=s;
 	}
 	r->next = NULL;
 	
 }

 //输出单链表
 void DispLinkList(LinkList *L)
 {
 	LinkList *p=L->next;
 	while(p!=NULL)
 	{
 		printf("%d ",p->data);
 		p = p->next;
 	}
 	printf("\n");
 }

 //荷兰旗排序，单链表
 void move2(LinkList *&L)
 {
 	LinkList *L1,*L2,*r,*r1,*r2,*p;
 	L1=NULL;
 	L2=NULL;
 	p=L->next;
 	r=L;
 	while(p!=NULL)
 	{
 		if(p->data == 0)
 		{
 			r->next = p;
 			r=p;
 		}
 		else if(p->data == 1)
 		{
 			if(L1==NULL)
 			{
 				L1=p;
 				r1=L1;
 			}
 			else
 			{
 				r1->next=p;
 				r1=p;
 			}
 		}
 		else if(p->data == 2)
 		{
 			if(L2 == NULL)
 			{
 				L2=p;
 				r2=L2;
 			}
 			else
 			{
 				r2->next=p;
 				r2=p;
 			}
 		}
 		p=p->next;
 	}
 	r2->next=NULL;
 	r->next=L1;
 	r1->next=L2;
 }


 int main()
 {
 	SqList *L1,*L2;
 	int sqa1[5] = {2,5,3,7,8};
 	int n = 5;

 	CreateSqList(L1,sqa1,n);
 	printf("L1: ");
 	DispSqList(L1);


 	SqList *H1;
 	int h[12] = {1,0,2,1,0,0,1,2,2,1,0,2};
 	int m = 12;
 	CreateSqList(H1,h,m);
 	printf("H1: ");
 	DispSqList(H1);
 	move1(H1);
 	printf("H1: ");
 	DispSqList(H1);	

 	LinkList *LH;
 	int lh[12] = {1,0,2,1,0,0,1,2,2,1,0,2};
 	int lm = 12;
 	CreateLinkListR(LH,lh,lm);
 	printf("LH: ");
 	DispLinkList(LH);
 	move2(LH);
 	printf("LH: ");
 	DispLinkList(LH);

 	return 0;
 }

