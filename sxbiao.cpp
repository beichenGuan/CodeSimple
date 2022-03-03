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

//删除顺序表中所有值为x的元素，方法1
void delnode1(SqList *&A, char x)
{
	int k=0,i;//k记录值不等于x的元素个数
	for(i=0;i<A->length;i++)
	{
		if(A->data[i]!=x)//当前元素不为x,插入A中
		{
			A->data[k] = A->data[i];
			k++;//不等于x的元素增1
		}
	}
	A->length=k;//顺序表长度等于k
}

//删除顺序表中所有值为x的元素，方法2
void delnode2(SqList *&A,char x)
{
	int k=0,i=0;//k记录值不等于x的元素个数
	while(i<A->length)
	{
		if(A->data[i]==x)//当前元素值为x时k增1
		{
			k++;
		}
		else//不为x时将其前移k个位置
		{
			A->data[i-k]=A->data[i];
		}
		i++;
	}
	A->length=A->length-k;//顺序表A的长度递减k
}

//移动元素,解法1
//交换元素位置
void move1(SqList *&L)
{
	int i=0,j=L->length-1;
	char tmp;
	char pivot=L->data[0];//以data[0]为基准
	while(i<j)
	{
		while(i<j&&L->data[j]>pivot)//从后往前扫描，找出一个≤pivot的元素
		{
			j--;
		}
		while(i<j&&L->data[i]<=pivot)//从前往后扫描，找出一个＞pivot的元素
		{
			i++;
		}
		if(i<j)
		{
			tmp=L->data[i];
			L->data[i]=L->data[j];
			L->data[j]=tmp;
		}
	}
	tmp=L->data[0];
	L->data[0] = L->data[j];
	L->data[j] = tmp;
}

//移动元素,解法2
//找出符合条件的直接前移或者后移
void move2(SqList *&L)
{
	int i=0,j=L->length-1;
	char pivot = L->data[0];//以data[0]为基准
	while(i<j)
	{
		while(j>i&&L->data[j]>pivot)
		{
			j--;//从右向左扫描，找出一个≤pivot的元素
		}
		L->data[i] = L->data[j];//放入data[i]处
		while(j>i&&L->data[i]<=pivot)
		{
			i++;//从左向右扫描，找出一个大于pivot的元素
		}
		L->data[j]=L->data[i];//放入data[j]处
	}
	L->data[i] = pivot;//放置基准值
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


