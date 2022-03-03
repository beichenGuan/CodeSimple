#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct 
{
	char data[MaxSize];
	int length;
}SqList;//顺序表类型

void CreateList(SqList *&L,char a[],int n)//整体创建顺序表
{
	int i;
	L=(SqList*)malloc(sizeof(SqList));
	for(i=0;i<n;i++)
	{
		L->data[i]=a[i];
	}
	L->length=n;
}

void InitList(SqList *&L)//初始化线性表
{
	L=(SqList *)malloc(sizeof(SqList));//分配存放线性表的线性表空间
	L->length=0;
}

void DestroyList(SqList *&L)//销毁线性表
{
	free(L);
}

bool ListEmpty(SqList *L)//判断是否为空表
{
	return (L->length==0);
}

int ListLength(SqList *L)//求线性表长度
{
	return (L->length);
}

void DispList(SqList *L)//输出线性表
{
	int i;
	if(ListEmpty(L))
	{
		return;
	}
	for(i=0;i<L->length;i++)
	{
		printf("%c ",L->data[i]);
	}
	printf("\n");
}

bool GetElem(SqList *L,int i,char &e)//求某个数据元素值,第i个元素
{
	if(i<1||i>L->length)
	{
		return false;
	}
	e = L->data[i-1];
	return true;
}

int LocateElem(SqList *L,char e)//按元素查找
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
	{
		i++;
	}
	if(i>=L->length)
	{
		return 0;
	}
	else
	{
		return i+1;
	}
}

bool ListInsert(SqList *&L,int i,char e)//第i个位置插入元素
{
	int j;
	if(i<1||i>L->length+1)
	{
		return false;//参数错误返回false
	}
	i--;//将顺序表逻辑序号转化为物理序号
	for(j=L->length;j>i;j--)//将data[i...n-1]元素后移一个位置
	{
		L->data[j]=L->data[j-1];
	}
	L->data[i]=e;//插入元素
	L->length++;//长度增加
	return true;//成功插入返回true

}

bool ListDelete(SqList *&L,int i,char &e)//删除第i个元素
{
	int j;
	if(i<1||i>L->length)
	{
		return false;//参数错误返回false
	}
	i--;//逻辑序号转化为物理序号
	e = L->data[i];//获取删除元素
	for(j=i;j<L->length;j++)
	{
		L->data[j] = L->data[j+1];//元素前移
	}
	L->length--;//长度减一
	return true;

}

int main()
{
	SqList *L1,*L2,*L3,*L4,*L5;
	int i,j,k;
	char a1[3] = {'a','b','c'};
	char a2[5] = {'w','e','5','h','y'};
	char c1 = 'b';
	int n=3;
	int m=5;
	CreateList(L1,a1,n);
	printf("L1: ");
	DispList(L1);
	printf("L1 length: %d\n",ListLength(L1));
	printf("b的位置： %d\n",LocateElem(L1,c1));
	InitList(L2);
	if(ListEmpty(L2))
	{
		printf("L2为空的顺序表\n");
	}
	j=4;
	k=2;
	char c2='t';
	char c3='h';
	ListInsert(L1,j,c2);
	printf("L1: ");
	DispList(L1);
	ListInsert(L1,k,c3);
	printf("L1: ");
	DispList(L1);
	char c4;
	j=3;
	ListDelete(L1,j,c4);
	printf("L1: ");
	DispList(L1);
	printf("删除的元素为：%c\n",c4);

	return 0;
}


