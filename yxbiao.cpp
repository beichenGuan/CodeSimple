#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef  struct 
{
	int data[MaxSize];
	int length;
}SqList;//顺序表节点类型

typedef struct LNode
{
	int data;
	struct LNode *next;
}LinkList;//单链表节点类型


//求顺序表长度
int ListLength(SqList *L)
{
	return L->length;
}

//顺序表存储有序表时，插入算法
void ListInsertS(SqList *&L,int e)
{
	int i=0,j;
	while(i<L->length&&L->data[i]<e)//查找元素值为e的元素
	{
		i++;
	}
	for(j=ListLength(L);j>i;j--)//将data[i...n]后移一个位置
	{
		L->data[j]=L->data[j-1];
	}
	L->data[i] = e;
	L->length++;//有序表长度增1

}

//顺序表存放有序表时，二路归并算法
void UnionListS(SqList *LA,SqList *LB,SqList *&LC)
{
	int i = 0,j=0,k=0;//i、j分别为LA、LB的下标，k为LC中元素个数；
	LC=(SqList *)malloc(sizeof(LinkList));//建立有序表LC
	while(i<LA->length&&j<LB->length)
	{
		if(LA->data[i]<LB->data[j])
		{
			LC->data[k] = LA->data[i];
			i++;k++;
		}
		else
		{
			LC->data[k] = LB->data[j];
			j++;k++;
		}
		//没有遍历完
	}

	while(i<LA->length)//LA没有扫描完，将其余元素插入LC中
	{
		LC->data[k] = LA->data[i];
		i++;k++;
	}
	while(j<LB->length)
	{
		LC->data[k] = LB->data[j];
		j++;k++;
	}

	LC->length=k;
}

//单链表存放有序表时，二路归并算法
void UnionListL(LinkList *LA,LinkList *LB,LinkList *&LC)
{
	LinkList *pa = LA->next;
	LinkList *pb = LB->next;
	LinkList *r,*s;
	LC = (LinkList *)malloc(sizeof(LinkList));//创建LC的头节点
	r = LC;


	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data<pb->data)
		{
			s=(LinkList *)malloc(sizeof(LinkList));
			s->data = pa->data;//复制节点
			r->next = s;
			r = s;//尾插法插入节点s
			pa=pa->next;
		}
		else
		{
			s = (LinkList *)malloc(sizeof(LinkList));
			s->data = pb->data;
			r->next = s;//复制节点
			r = s;//尾插法插入
			pb = pb->next;
		} 
	}

	while(pa!=NULL)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data = pa->data;
		r->next = s;
		r = s;
		pa = pa->next;
	} 
	while(pb!=NULL)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = pb->data;
		r->next = s;
		r = s;
		pb = pb->next;
	}

	r->next = NULL;//尾节点的next域置空

}


//单链表存储有序表,插入算法
void ListInsertL(LinkList *&L,int e)
{
	LinkList *pre=L,*p;
	while(pre->next!=NULL&&pre->next->data<e)
	{
		pre = pre->next;//查找插入节点的前趋节点
	}
	p=(LinkList *)malloc(sizeof(LinkList));
	p->data=e;//创建存放e的数据节点*p
	p->next = pre->next;
	pre->next = p;//pre节点之后插入p节点
}

//二路归并算法求中位数
//算法时间复杂度O(n)，空间复杂度O(1)
int M_Search(int A[],int B[],int n)
{
	int i,j,k;
	i=0;j=0;k=0;
	while(i<n&&j<n)
	{
		k++;
		if(A[i]<B[j])
		{
			if(k==n)
			{
				return A[i];
			}
			i++;
		}
		else//A[i]>=B[j]
		{
			if(k==n)
			{
				return B[j];
			}
			j++;
		}
	}

}

//二路归并思想求公共元素
void InsertSect(LinkList *ha,LinkList *hb,LinkList *&hc)
{
	LinkList *pa = ha->next;
	LinkList *pb = hb->next;
	LinkList *r,*s;
	hc = (LinkList *)malloc(sizeof(LinkList));
	r = hc;//r指向尾节点
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data<pb->data)
		{
			pa = pa->next;
		}
		if(pa->data>pb->data)
		{
			pb = pb->next;
		}
		if(pa->data == pb->data)//相同元素
		{
			s=(LinkList *)malloc(sizeof(LinkList));
			s->data = pa->data;//复制节点
			r->next = s;
			r=s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	r->next = NULL;
}


int main()
{
	return 0;
}