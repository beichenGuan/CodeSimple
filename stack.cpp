#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20

typedef struct 
{
	int data[MaxSize];
	int top;//栈顶指针
}SqStack;//顺序栈类型

typedef struct linknode
{
	int data;
	struct linknode *next;
}LinkStack;

//初始化栈
void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));//s为栈指针
	s->top = -1;//s->top为栈顶指针
}

//销毁栈
void DestroyStack(SqStack *&s)
{
	free(s);
}

//判断栈是否为空
bool StackEmpty(SqStack *s)
{
	return (s->top == -1);
}

//进栈
bool Push(SqStack *&s,int e)
{
	if(s->top == MaxSize)
	{
		return false;//栈满的情况，即栈上溢出
	}
	s->top++;//栈顶指针增1
	s->data[s->top] = e;//元素e放在栈顶指针处
	return true;
}

//出栈
bool Pop(SqStack *&s,int &e)
{
	if(s->top == -1)
	{
		return false;//栈为空的情况，即栈下溢出
	}
	e = s->data[top];//取栈顶指针元素的元素
	s->top--;
	return true;
}

//取栈顶元素
bool GetTop(SqStack *s,int &e)
{
	if(s->top == -1)
	{
		return false;//空栈
	}
	e = s->data[s->top];//取栈顶指针元素的元素
	return true;
}

//用顺序栈判断字符串是否是对称串
bool symmetry(char str[])
{
	int i;
	char e;
	SqStack *st;
	InitStack(st);//初始化栈

	for(i=0;str[i]!='\0';i++)//将串所有元素进栈
	{
		Push(st,str[i]);//元素进栈
	}

	for(i=0;str[i]!='\0';i++)
	{
		Pop(st,e);//退栈元素e
		if(str[i]!=e)//若e与当前串元素不同则不是对称串
		{
			DestroyStack(st);
			return false;
		}
	}

	DestroyStack(st);//销毁栈
	return true;
}

//初始化链栈
void InitStackL(LinkStack *&S)
{
	S = (LinkStack *)malloc(sizeof(LinkStack));
	S->next = NULL;
}

//销毁栈
void DestroyStackL(LinkStack *&S)
{
	LinkStack *pre = S;
	LinkStack *p = pre->next;
	while(p!=NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);//释放尾节点
}

//判断栈是否为空栈
bool StackEmptyL(LinkStack *S)
{
	return(S->next == NULL);
}

//进栈,采用头插法进栈
void PushL(LinkStack *&S,int e)
{
	LinkStack *p;
	p = (LinkStack *)malloc(sizeof(LinkStack));
	p->data = e;//新建元素e对应的节点p
	p->next = S->next;//插入p节点作为开始节点
	S->next = p;
}

//出栈
bool PopL(LinkStack *&S,int &e)
{
	LinkStack *q;
	if(S->next == NULL)
	{
		return false;//栈空情况
	}
	p = S->next;//p指向开始节点
	e = p->data;
	S->next = p->next;//删除p节点
	free(p);//释放p节点

}

//取栈顶元素
bool GetTopL(LinkStack *S,int &e)
{
	if(S->next == NULL)
	{
		return false;//栈空情况
	}
	e = S->next->data;//取首节点的值
	return true;
}

//判断表达式左右括号是否配对
bool Match(char exp[],int n)
{
	int i = 0;
	char e;
	bool match = true;
	LinkStack *st;
	InitStackL(st);//初始化栈
	while(i<n&&match)//扫描exp中所有字符
	{
		if(exp[i]=='(')
		{
			PushL(st,exp[i]);
		}
		else if(exp[i]==')')//当前字符为右括号
		{
			if(GetTopL(st,e) == true)
			{
				if(e!='(')
				{
					match=false;//栈顶元素不为'('时表示不匹配
				}
				else
				{
					Pop(st,e);//将栈顶元素出栈
				}
			}
			else
			{
				match = false;//无法取栈顶元素时表示不匹配
			}

		}
		i++;//继续处理其他元素
	}
	if(!StackEmptyL(st))
	{
		match = false;
	}
	DestroyStackL(st);//销毁栈
	return match;
}


int main()
{

	return 0;
}