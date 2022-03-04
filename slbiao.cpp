#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode//双链表节点类型
{
	int data;
	struct DLNode *prior;//指向前趋节点
	struct DLNode *next;//指向后继节点
}DoubleLinkList;

//头插法建双链表
void CreateListF(DoubleLinkList *&L,int a[],int n)
{
	DoubleLinkList *s;
	int i;
	L = (DoubleLinkList *)malloc(sizeof(DoubleLinkList));//创建头节点
	L->prior = NULL;					//前后指针域置为NULL
	L->next = NULL; 
	for(i=0;i<n;i++)//循环建立数据节点
	{
		s=(DoubleLinkList *)malloc(sizeof(DoubleLinkList));
		s->data = a[i];//创建数据节点*s
		s->next=L->next;//将*s插入到头节点之后
		if(L->next!=NULL)//若L存在数据节点修改前趋指针
		{
			L->next->prior=s;
		}
		L->next=s;
		s->prior=L;
	}
}

//尾插法建双链表
void CreateListR(DoubleLinkList *&L,int a[],int n)
{
	DoubleLinkList *r,*s;
	int i;
	L = (DoubleLinkList *)malloc(sizeof(DoubleLinkList));//创建头节点
	L->next = NULL;
	L->prior = NULL;
	r = L;//r始终指向尾节点，开始时指向头节点
	for(i = 0;i<n;i++)//循环建立数据节点
	{
		s = (DoubleLinkList *)malloc(sizeof(DoubleLinkList));
		s->data = a[i];//创建数据节点*s
		r->next = s;
		s->prior = r;//将*s插入*r之后
		r = s;//r指向尾节点
	}
	r->next = NULL;//尾节点next域置为NULL

}

//输出链表元素data域值
void DispList(DoubleLinkList *L)
{
	DoubleLinkList *p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
 
//双链表插入节点
bool ListInsert(DoubleLinkList *&L,int i,int e)
{
	int j=0;
	DoubleLinkList *p = L;//p指向头节点，j设置为0
	DoubleLinkList *s;
	while(j<i-1&&p!=NULL)//查找第i-1个节点
	{
		j++;
		p = p->next;
	}
	if(p==NULL)//未找到第i-1个节点，返回false
	{
		return false;
	}
	else//找到第i-1个节点*p,在其后插入新节点*s
	{
		s = (DoubleLinkList *)malloc(sizeof(DoubleLinkList));
		s->data = e;//创建新节点*s
		s->next = p->next;//在*p之后插入*s节点
		if(p->next != NULL)//若存在后继节点，修改其前趋指针
		{
			p->next->prior = s;
		}
		p->next = s;
		s->prior = p;
		return true;
	}

}

//双链表删除节点
bool ListDelete(DoubleLinkList *&L,int i,int &e)
{
	DoubleLinkList *p = L;
	DoubleLinkList *q;
	int j = 0;
	while(j<i-1&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
	{
		return false;
	}
	else
	{
		q = p->next;
		if(q==NULL)
		{
			return false;
		}
		e=q->data;
		p->next = q->next;
		if(p->next!=NULL)
		{
			p->next->prior = p;
		}
		free(q);
		return true;
	}

}

//双链表节点逆置,采用头插法进行逆置
void Reverse(DoubleLinkList *&L)
{
	DoubleLinkList *p = L->next;//p指向开头节点
	DoubleLinkList *q;
	L->next = NULL;//只有头节点的双链表
	while(p!=NULL)
	{
		q = p->next;//q保存后继节点
		p->next = L->next;//头插法将p插入
		if(L->next != NULL)//修改前趋指针
		{
			L->next->prior = p;
		}
		L->next = p;
		p->prior = L;
		p = q;//p重新指向后继节点
	}
}



//求链表长度
int ListLength(DoubleLinkList *L)
{
	DoubleLinkList *p=L;
	int i=0;
	while(p->next!=NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int main()
{
	DoubleLinkList *L1,*L2;
	int a[5] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	CreateListR(L1,a,n);
	printf("L1: ");
	DispList(L1);
	int i = 4;
	int e = 88;
	bool b1 = ListInsert(L1,i,e);
	printf("L1 Insert: ");
	DispList(L1);
	printf("Length: %d\n",ListLength(L1));

	int j = 2;
	int e1;
	bool b2 = ListDelete(L1,j,e1);
	printf("L1 Delete: ");
	DispList(L1);

	Reverse(L1);
	printf("L1 Reverse: ");
	DispList(L1);

	return 0;
}