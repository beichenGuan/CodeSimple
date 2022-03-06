#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20

typedef struct 
{
	int data[MaxSize];
	int front,rear;//队首和队头指针
}SqQueue;//顺序队节点类型


//该环形队列4要素
//队空条件：count = 0;
//队满条件：count = MaxSize
//进队e操作：rear = (rear+1)%MaxSize
//出队操作：front = (front+1)%MaxSize
typedef struct
{
	int data[MaxSize];
	int front;//队头指针
	int count;//队列中元素个数
}QuType;//环形队列节点类型

typedef struct qnode
{
	int data;//数据元素
	struct qnode *next;
}QNode;//链队中数据节点类型

typedef struct
{
	QNode *front;//队头节点
	QNode *rear;//队尾节点
}LiQueue;//链队中头节点类型

typedef struct LNode
{
	int data;
	struct LNode *next;
}LinkList;



//初始化队列
void InitQueueS(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front=-1;
	q->rear = -1;
}

//环形队列初始化队列
void InitQueueS1(SqQueue *&q)
{
	q = (QuType *)malloc(sizeof(QuType));
	qu->front = 0;
	qu->count = 0;
}

//环形队列进队操作
bool enQueueS1(QuType *&q,int x)
{
	int rear;
	if(q->count == MaxSize)//队满上溢出
	{
		return false;
	}
	else
	{
		rear = (q->front+q->count)%MaxSize;//求队尾位置
		rear = (rear+1)%MaxSize;//队尾循环增1
		q->data[rear] = x;
		q->count++;//元素个数增1
		return true;
	}
}

//环形队列出队操作
bool deQueueS1(QuType *&q,int &x)
{
	if(q->count == 0)
	{
		return false;//队空下溢出
	}
	else
	{
		q->front=(q->front+1)%MaxSize;//队头循环增1
		x = q->data[q->front];
		q->count--;//元素个数减1
		return true;
	}
}

//环形队列判断队空
bool QueueEmptyS1(QuType *q)
{
	return (q->count == 0);
}



//销毁队列
void DestroyQueueS(SqQueue *&q)
{
	free(q);
}

//判断队列是否为空
bool QueueEmptyS(SqQueue *q)
{
	return (q->front == q->rear);
}

//进队列
bool enQueueS(SqQueue *&q,int e)
{
	if(q->rear == MaxSize)
	{
		return false;//队满上溢出
	}
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

//出队列
bool deQueueS(SqQueue *&q,int &e)
{
	if(q->front == q->rear)
	{
		return false;//队空下溢出
	}
	q->front++;
	e = q->data[q->front];
	return true;
}


//链队初始化队列
void InitQueueQ(LiQueue *&q)
{
	q = (LiQueue *)malloc(sizeof(LiQueue));
	q->front=NULL;
	q->rear=NULL;
}

//链队销毁队列
void DestroyQueueQ(LiQueue *&q)
{
	QNode *p = q->front;//p指向队头数据节点
	QNode *r;
	if(p!=NULL)//释放数据节点占用空间
	{
		r = p->next;
		while(r!=NULL)
		{
			free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);//释放链队节点占用空间

}

//链队判断队列是否为空
bool QueueEmptyQ(LiQueue *q)
{
	return (q->rear == NULL);
}

//进队
//原队列为空，原队列非空需要考虑
void enQueueQ(LiQueue *&q,int e)
{
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	if(q->rear == NULL)//若队链为空，新节点是队首节点又是队尾节点
	{
		q->front = p;
		q->rear = p;
	}
	else//非空，p节点链到队尾，并将rear指向它
	{
		q->rear->next = p;
		q->rear = p;
	}

}

//链队出队
//原队列为空，或只有一个节点，或其他情况
bool deQueueQ(LiQueue *&q,int &e)
{
	QNode *t;
	if(q->rear == NULL)//队列为空
	{
		return false;
	}
	t = q->front;//t指向第一个数据节点
	if(q->front == q->rear)//队列中只有一个节点时
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else//队列有多个节点时
	{
		q->front = q->front->next;
	}
	e = t->data;
	free(t);
	return true;

}

//只带尾节点链队
void InitQueueQ1(LinkList *&rear)
{
	rear = NULL;
}

bool queueEmptyQ1(LiQueue *rear)
{
	return (rear == NULL);
}

void enQueueQ1(LinkList *&rear,int x)
{
	LinkList *p;
	p = (LinkList *)malloc(sizeof(LinkList));
	p->data = x;
	if(rear == NULL)
	{
		p->next = p;
		rear = p;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;
		rear = p;
	}
}

bool deQueueQ1(LinkList *&rear,int &x)
{
	LinkList *q;
	if(rear == NULL)
	{
		return false;
	}
	else if(rear->next == rear)
	{
		x = rear->data;
		free(rear);
		rear = NULL;
	}
	else
	{
		q = rear->next;
		x = q->data;
		rear->next = q->next;
		free(q);
	}
	return true;
}




int main()
{

	return 0;
}