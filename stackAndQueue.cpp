#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct 
{
	int i;//当前方块的行号
	int j;//当前方块的列号
	int di;//di是下一可走相邻方位的方位号
} Box;//定义方块类型

typedef struct
{
	Box data[MaxSize];
	int top;//栈顶指针
}StType;//定义顺序栈类型


bool mgpath(int xi,int yi,int xe,int ye)
{
	int i,j,k,di,find;
	StType st;
	st.top = -1;//定义栈st并初始化
	st.top++;初始化方块进栈
	st.data[st.top].i=xi;
	st.data[st.top].j=yi;
	st.data[st.top].di = -1;
	//mg[xi][yi]=-1;//为避免重复，当一个方块进栈时，将迷宫值改为-1；
	while(st.top>-1)//栈不空时循环
	{
		i = st.data[st.top].i;
		j = st.data[st.top].j;
		di = st.data[st.top].di;//取栈顶方块
		if(i == xe && j == ye)
		{
			printf("迷宫路径如下：\n");
			for(k=0;k<st.top;k++)
			{
				printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
				if((k+1)%5==0)//每输出5个方块后换一行
				{
					printf("\n");
				}
			}
			printf("\n");
			return true;//找到一条路径后返回true
		}
	find = 0;
	while(di<4&&find==0)//找下一个可走方块
	{
		di++;
		switch(di)
		{
			case 0:
			i = st.data[st.top].i-1;
			j = st.data[st.top].j;
			break;
			case 1:
			i = st.data[st.top].i;
			j = st.data[st.top].j+1;
			break;
			case 2:
			i = st.data[st.top].i+1;
			j = st.data[st.top].j;
			break;
			case 3:
			i = st.data[st.top].i;
			j = st.data[st.top].j-1;
			break;
		}
		if(mg[i][j] == 0)
		{
			find = 1;
		}
	}

	if(find == 1)//找到下一个可走方块
		{
			st.data[st.top].di = di;//修改原栈顶元素的di 值
			st.top++;//下一个可走方块进栈
			st.data[st.top].i = i;
			st.data[st.top].j = j;
			st.data[st.top].di = -1;
			mg[i][j] = -1;//避免重复走到该方块
		}
		else//没有路径可走，则退栈
		{
			mg[st.data[st.top].i][st.data[st.top].j]=0;
			//让该位置变为其他路径可走方块
			//将该方块退栈
			st.top--;
		}
	}

	return false;

}


//用队列求解迷宫问题
typedef struct
{
	int i,j;//方块位置
	int pre;//本路径中上一方块在队列中的下标
}Box1;//方块类型

typedef struct
{
	Box1 data[MaxSize];
	int front,rear;//队头指针和队尾指针
}QuType;//顺序队类型

bool mgpath1(int xi,int yi,int xe,int ye)
{
	//搜索路径为:(xi,yi)->(xe,ye)
	int i,j,find=0,di;
	QuType qu;
	qu.front = qu.rear = -1;
	qu.rear++;
	qu.data[qu.rear].i = xi;
	qu.data[qu.rear].j = yi;//(xi,yi进队)
	qu.data[qu.rear].pre = -1;
	mg[xi][yi] = -1;//将其赋值-1,以避免会过来重复搜索

  	while(qu.front!=qu.rear && !find)//队列不空循环
  	{
  		qu.front++;//出队
  		i = qu.data[qu.front].i;
  		j = qu.data[qu.front].j;
  		if(i == xe && j == ye)//找到了出口，输出路径
  		{
  			find = 1;
  			printf(qu,qu.front);
  			return true;
  		}

  		for(di=0;di<4;di++)
  		{
  			switch(di)
  			{
  				case 0:
  				i = qu.data[qu.front].i-1;
  				j = qu.data[qu.front].j;
  				break;
  				case 1:
  				i = qu.data[qu.front].i;
  				j = qu.data[qu.front].j+1;  				
  				break;
  				case 2:
  				i = qu.data[qu.front].i+1;
  				j = qu.data[qu.front].j;  				
  				break;
  				case 3:
  				i = qu.data[qu.front].i;
  				j = qu.data[qu.front].j-1;  				
  				break;
  			}
  			if(mg[i][j]==0)
  			{
  				qu.rear++;//将该相邻方块插入到队列中
  				qu.data[qu.rear].i = i;
  				qu.data[qu.rear].j = j;
  				qu.data[qu.rear].pre = qu.front;
  				mg[i][j]=-1;
  			}
  		}


  	}

  	return false;//未找到一条路径时返回false

}


int main()
{
	if(!mgpath(1,1,M,N))
	{
		printf("该迷宫问题没有解！");
	}

	if(!mgpath1(1,1,M,N))
	{
		printf("该迷宫问题没有解！");
	}

}



