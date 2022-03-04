#include <stdio.h>
#include <stdlib.h>

typedef struct LNode //定义单链表节点类型
{
	int data;
	struct LNode *next;//指向后继节点
}LinkList;

//头插法建表
void CreateListF(LinkList *&L,int a[],int n)
{
	LinkList *s;
	int i;
	L=(LinkList *)malloc(sizeof(LinkList));
	L->next=NULL; //创建头节点，其next域置为NULL
	for(i=0;i<n;i++)//循环建立数据节点
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];//创建数据节点*s
		s->next=L->next;//将*s插在原开始节点之前，头节点之后
		L->next=s;
	}
}

//尾插法建表
void CreateListR(LinkList *&L,int a[],int n)
{
	LinkList *s,*r;
	int i;
	L=(LinkList *)malloc(sizeof(LinkList));//创建头节点
	r=L;//r始终指向尾节点，开始时指向头节点
	for(i=0;i<n;i++)//循环建立数据节点
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];//创建数据节点*s
		r->next=s;//将*s插入*r之后
		r=s;
	}
	r->next=NULL;//尾节点next域置为NULL
}

//初始化线性表
void InitList(LinkList *&L)
{
	L=(LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
}

//销毁线性表
void DestroyList(LinkList *&L)
{
	LinkList *pre = L;
	LinkList *p = L->next;//*pre指向*p的前驱节点
	while(p!=NULL)//扫描单链表L
	{
		free(pre);//释放*pre节点
		pre = p;//pre,p同步后移一个节点
		p = pre->next;
	}
	free(pre);//循环结束时，p为NULL,pre指向尾节点，释放它

}

//判断线性表是否为空表
bool ListEmpty(LinkList *L)
{
	return (L->next == NULL);//单链表L没有数据节点则为空表，返回真，否则返回假
}

//求线性表的长度
int ListLength(LinkList *L)
{
	int n=0;
	LinkList *p=L;//p指向头节点，n置为0(即头节点的序号为0)
	while(p->next!=NULL)
	{
		n++;
		p=p->next;
	}
	return (n);//循环结束，p指向尾节点，其序号n为节点个数
}

//输出线性表
void DispList(LinkList *L)
{
	LinkList *p = L->next;//p指向开始节点
	while(p!=NULL)
	{
		printf("%d ",p->data);//p不为NULL，输出*p节点的data域
		p=p->next;//p移向下一个节点
	}
	printf("\n");

}

//求线性表L中位置i的数据元素
bool GetElem(LinkList *L,int i,int &e)
{
	int j=0;
	LinkList *p=L;//p指向头节点，j置为0（即头节点的序号为0）
	while(j<i&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)//不存在第i个数据节点，返回false
	{
		return false;
	}
	else//存在第i个数据节点，返回true
	{
		e = p->data;
		return true;
	}

}

//按元素值查找
int LocateElem(LinkList *L,int e)
{
	int i=1;
	LinkList *p = L->next;//p指向开始节点，i置为1
	while(p!=NULL&&p->data!=e)//查找data值为e的节点，序号为i
	{
		p=p->next;
		i++;
	}
	if(p==NULL)//不存在元素值为e的节点，返回0
	{
		return 0;
	}
	else//存在元素值为e的节点，返回其逻辑序号i
	{
		return i;
	}
}

//插入数据元素
bool ListInsert(LinkList *&L,int i,int e)
{
	int j=0;
	LinkList *p=L,*s;//p指向头节点，j置为0
	while(j<i-1&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
	{
		return false;//未找到第i-1个节点，返回false
	}
	else//找到第i-1个节点*p,插入新节点并返回true
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=e;//创建新节点*s,其data域置为e
		s->next=p->next;//将*s插入到*p之后
		p->next=s;
		return true;
	}

}

//删除数据元素
bool ListDelete(LinkList *&L,int i,int &e)
{
	int j=0;
	LinkList *p=L,*q;//p指向头节点，j置为0
	while(j<i-1&&p!=NULL)//查找第i-1个节点
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
	{
		return false;//未找到第i-1个节点，返回false
	}
	else//找到第i-1个节点*p
	{
		q=p->next;//q指向第i个节点*p
		if(q==NULL)//若不存在第i个节点，返回false
		{
			return false;
		}
		else
		{
		e=q->data;
		p->next=q->next;//从单链表中删除*q节点	
		free(q);//释放*q节点
		return true;	//返回true表示成功删除第i个节点	
		}
	}
}

//删除单链表L中元素值最大的节点
//算法时间复杂度O(n)
void delmaxnode(LinkList *&L)
{
	LinkList *p = L->next;
	LinkList *pre = L;
	LinkList *maxp = p;
	LinkList *maxpre = pre;

	while(p!=NULL)
	{
		if(maxp->data<p->data)//若找到一个更大的节点
		{
			maxp = p;//更改maxp
			maxpre = pre;//更改maxpre
		}
		pre = p;//p、pre同步后移一个节点
		p = p->next;
	}

	maxpre->next = maxp->next;//删除*maxp节点
	free(maxp);//释放*maxp节点

}

//使单链表元素递增有序排列
//算法时间复杂度O(n²)
void sort(LinkList *&L)
{
	LinkList *p,*pre,*q;
	p = L->next->next;//p指向L的第2个数据节点
	L->next->next = NULL;//构造只含一个数据节点的有序表

	while(p!=NULL)
	{
		q = p->next;//q保存*p节点后继节点的指针
		pre = L;//从有序表开头进行比较，pre指向插入*p的前趋节点
		while(pre->next!=NULL&&pre->next->data<p->data)
		{
			pre = pre->next;//在有序表中找插入*p的前趋节点*pre
		}
		p->next = pre->next;
		pre->next = p;
		p = q;//扫描原单链表余下的节点
	}

}

//逆置单链表L
void Reverse(LinkList *&L)
{
	LinkList *p = L->next;
	LinkList *q;
	L->next = NULL;

	while(p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

//将单链表L{a1,b1,a2,b2,...,an,bn}拆分成L1(顺序),L2(逆序)
voie split(LinkList *&L,LinkList *&L1,LinkList *&L2)
{
	LinkList *p = L->next,*q,*r1;//p指向第一个数据节点
	L1 = L;						 //L1利用原来L的头节点
	r1 = L1;					 //r1始终指向L1的尾节点
	L2 = (LinkList *)malloc(sizeof(LinkList));//创建L2的头节点
	L2->next = NULL;			 //置L2的指针域为NULL

	while(p!=NULL)
	{
		r1->next = p;//采用尾插法将*p(data值为ai)插入L1中
		r1 = p;
		p = p->next;//p移向下一个节点(data值为bi)
		q = p->next;//用q保存p的后继节点
		p->next = L2->next;//头插法插入L2
		L2->next = p;
		p = q;//p重新指向ai+1节点
	}
	r1->next=NULL;  //尾节点next置空
}

int main()
{
	LinkList *L1,*L2,*L3,*L4,*L5;
	int a[5]={1,2,3,4,5};
	int b[6]={5,3,7,2,7,9};
	int m=5,n=6;
	int i,j,k;
	int e1,e2,e3;

	CreateListR(L1,a,m);
	printf("L1: ");
	DispList(L1);
	i=3;e1=22;
	ListInsert(L1,i,e1);
	printf("L1: ");
	DispList(L1);
	ListDelete(L1,i,e2);
	printf("L1: ");
	DispList(L1);
	printf("e2: %d\n",e2);
	
	return 0;
}
