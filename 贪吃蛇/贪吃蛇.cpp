#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include <graphics.h>
// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

//全局变量
int food_x,food_y;			  //记录食物的位置
int canvas[50][50]={0};       //二维数组存储游戏画面中的元素，0为空格，-1为边框#，1为蛇头@，大于一为蛇身* ，-2位食物o
int moveDirection;            //小蛇的移动方向 值1234分别表示上下左右移动
int grade;					  //得分
IMAGE img_bk;				  //背景图片 


void startup()
{
	initgraph(490,490);
	loadimage(&img_bk, "./image/background.jpg");
	mciSendString("open ./image/game_music.mp3 alias bkmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  // 循环播放
	//生成边框 -1代表边框
	int i,j;
	for(i=0;i<50;i++)
	{
		canvas[i][0]=-1;
		canvas[i][49]=-1;
	}
	for(j=0;j<50;j++)
	{
		canvas[0][j]=-1;
		canvas[49][j]=-1;
	}
	//初始化蛇头蛇身
	canvas[25][25]=1; 
	for(i=0;i<4;i++)
	{
		canvas[25+i][25]=i+1;
	}
	//初始化蛇的移动方向
	moveDirection=1;
	
	//初始化食物的位置
	food_x=rand()%(45)+2;
	food_y=rand()%(45)+2;
	canvas[food_x][food_y]=-2;
	
	grade=0;
}
void moveSnakeByDirection()
{
	int i,j;
	int max=0;
	int oldTail_i,oldTail_j;     //记录旧的蛇尾巴
	int oldHead_i,oldHead_j;     //记录旧的蛇头
	
	for(i=1;i<50-1;i++)
	{
		for(j=1;j<50-1;j++)
		{
			if(canvas[i][j]>0)
			{
				//对所有大于零的元素加一
				canvas[i][j]++;
				
				//求出最大值max
				if(max<canvas[i][j])
				{
					max=canvas[i][j];
					oldTail_i=i;
					oldTail_j=j;
				}
				//记录旧蛇头的位置
				if(canvas[i][j]==2)
				{
					oldHead_i=i;
					oldHead_j=j;
				}
			}
		}
	}
	int newHead_i,newHead_j;    //记录新蛇头
	
	if(moveDirection==1)      //向上
	{
		newHead_i=oldHead_i-1;
		newHead_j=oldHead_j;
	}
	if(moveDirection==2)      //向下
	{
		newHead_i=oldHead_i+1;
		newHead_j=oldHead_j;
	}
	if(moveDirection==3)      //向左
	{	
		newHead_i=oldHead_i;
		newHead_j=oldHead_j-1;
	}
	if(moveDirection==4)      //向右
	{	
		newHead_i=oldHead_i;
		newHead_j=oldHead_j+1;
	}
	
	//判断小蛇蛇头是否碰到食物
	if(canvas[newHead_i][newHead_j]==-2)
	{
		//食物原始位置归零
		clearrectangle(10*food_y-5,10*food_x-5,10*food_y+5,10*food_x+5);      //让食物消失
		//产生新的食物
		mciSendString("close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
		mciSendString("open ./image/gotEnemy.mp3 alias gemusic", NULL, 0, NULL); // 打开音乐
		mciSendString("play gemusic", NULL, 0, NULL); // 仅播放一次
		if (grade>0 && grade%5==0 && grade%2!=0)
		{
			mciSendString("close 5music", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString("open ./image/5.mp3 alias 5music", NULL, 0, NULL); // 打开音乐
			mciSendString("play 5music", NULL, 0, NULL); // 仅播放一次
		}
		if (grade%10==0)
		{
			mciSendString("close 10music", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString("open ./image/10.mp3 alias 10music", NULL, 0, NULL); // 打开音乐
			mciSendString("play 10music", NULL, 0, NULL); // 仅播放一次
			}
		food_x=rand()%(50-5)+2;
		food_y=rand()%(50-5)+2;
		canvas[food_x][food_y]=-2;
		
		grade++; 
		//吃到食物，不用把最大值设为零，长度加一
	}
	else
	{
		//没有吃到食物的时候长度不变
		canvas[oldTail_i][oldTail_j]=0;    //最大值所在元素变为0
	}
	//判断小蛇撞到边框或者本身，游戏失败
	if(canvas[newHead_i][newHead_j]==-1)
	{
		printf("游戏失败!\n");
		exit(0);
	}
	else
	{
		canvas[newHead_i][newHead_j]=1;
	}
}
void show()        //显示画面
{
	int x,y;
	putimage(0, 0, &img_bk);	// 显示背景
	for (x=0;x<50;x++)
	{
		for (y=0;y<50;y++)
		{
			if(canvas[y][x]==-1)
			{
				//画边框
				setcolor(WHITE);
				setfillcolor(BLACK);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5); 
			}
			else if (canvas[y][x]==1)
			{
				//画蛇头
				setcolor(RED);
				setfillcolor(RED);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5);
			}
			else if (canvas[y][x]>1)
			{
				//画蛇身
				setcolor(RED);
				setfillcolor(YELLOW);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5);
			}
			else if (canvas[y][x]==-2)
			{
				//画食物
				setcolor(RED);
				setfillcolor(BLUE);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5);
			}
		}
	}
	setcolor(WHITE);
	setfillcolor(WHITE);
	outtextxy(210,430,"得分：");
	// 输出数值，先将数字格式化输出为字符串 (VC6)
	char s[5];
	sprintf(s, "%d", grade);
	outtextxy(250, 430, s);
	Sleep(120);
}
void updateWithoutinput()     //与用户输入无关的更新
{
	moveSnakeByDirection();
}
void updteWithinput()         //与用户输入有关的更新
{
	char input;
	if(kbhit())
	{
		input = getch();
		if (input == 'a')
		{
			moveDirection=3;
		}
		if (input == 'd')
		{
			moveDirection=4;
		}
		if (input == 'w')
		{
			moveDirection=1;
		}
		if (input == 's')
		{
			moveDirection=2;
		}
	}
}	
int main()
{
	startup();         //数据初始化
	while (1)          //游戏循环执行
	{
		show();        //显示画面
		updateWithoutinput();     //与用户输入无关的更新
		updteWithinput();         //与用户输入有关的更新
	}
	return 0;
}