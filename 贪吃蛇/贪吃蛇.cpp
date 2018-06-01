#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include <graphics.h>
// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

//ȫ�ֱ���
int food_x,food_y;			  //��¼ʳ���λ��
int canvas[50][50]={0};       //��ά����洢��Ϸ�����е�Ԫ�أ�0Ϊ�ո�-1Ϊ�߿�#��1Ϊ��ͷ@������һΪ����* ��-2λʳ��o
int moveDirection;            //С�ߵ��ƶ����� ֵ1234�ֱ��ʾ���������ƶ�
int grade;					  //�÷�
IMAGE img_bk;				  //����ͼƬ 


void startup()
{
	initgraph(490,490);
	loadimage(&img_bk, "./image/background.jpg");
	mciSendString("open ./image/game_music.mp3 alias bkmusic", NULL, 0, NULL);//�򿪱�������
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  // ѭ������
	//���ɱ߿� -1����߿�
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
	//��ʼ����ͷ����
	canvas[25][25]=1; 
	for(i=0;i<4;i++)
	{
		canvas[25+i][25]=i+1;
	}
	//��ʼ���ߵ��ƶ�����
	moveDirection=1;
	
	//��ʼ��ʳ���λ��
	food_x=rand()%(45)+2;
	food_y=rand()%(45)+2;
	canvas[food_x][food_y]=-2;
	
	grade=0;
}
void moveSnakeByDirection()
{
	int i,j;
	int max=0;
	int oldTail_i,oldTail_j;     //��¼�ɵ���β��
	int oldHead_i,oldHead_j;     //��¼�ɵ���ͷ
	
	for(i=1;i<50-1;i++)
	{
		for(j=1;j<50-1;j++)
		{
			if(canvas[i][j]>0)
			{
				//�����д������Ԫ�ؼ�һ
				canvas[i][j]++;
				
				//������ֵmax
				if(max<canvas[i][j])
				{
					max=canvas[i][j];
					oldTail_i=i;
					oldTail_j=j;
				}
				//��¼����ͷ��λ��
				if(canvas[i][j]==2)
				{
					oldHead_i=i;
					oldHead_j=j;
				}
			}
		}
	}
	int newHead_i,newHead_j;    //��¼����ͷ
	
	if(moveDirection==1)      //����
	{
		newHead_i=oldHead_i-1;
		newHead_j=oldHead_j;
	}
	if(moveDirection==2)      //����
	{
		newHead_i=oldHead_i+1;
		newHead_j=oldHead_j;
	}
	if(moveDirection==3)      //����
	{	
		newHead_i=oldHead_i;
		newHead_j=oldHead_j-1;
	}
	if(moveDirection==4)      //����
	{	
		newHead_i=oldHead_i;
		newHead_j=oldHead_j+1;
	}
	
	//�ж�С����ͷ�Ƿ�����ʳ��
	if(canvas[newHead_i][newHead_j]==-2)
	{
		//ʳ��ԭʼλ�ù���
		clearrectangle(10*food_y-5,10*food_x-5,10*food_y+5,10*food_x+5);      //��ʳ����ʧ
		//�����µ�ʳ��
		mciSendString("close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
		mciSendString("open ./image/gotEnemy.mp3 alias gemusic", NULL, 0, NULL); // ������
		mciSendString("play gemusic", NULL, 0, NULL); // ������һ��
		if (grade>0 && grade%5==0 && grade%2!=0)
		{
			mciSendString("close 5music", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString("open ./image/5.mp3 alias 5music", NULL, 0, NULL); // ������
			mciSendString("play 5music", NULL, 0, NULL); // ������һ��
		}
		if (grade%10==0)
		{
			mciSendString("close 10music", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString("open ./image/10.mp3 alias 10music", NULL, 0, NULL); // ������
			mciSendString("play 10music", NULL, 0, NULL); // ������һ��
			}
		food_x=rand()%(50-5)+2;
		food_y=rand()%(50-5)+2;
		canvas[food_x][food_y]=-2;
		
		grade++; 
		//�Ե�ʳ����ð����ֵ��Ϊ�㣬���ȼ�һ
	}
	else
	{
		//û�гԵ�ʳ���ʱ�򳤶Ȳ���
		canvas[oldTail_i][oldTail_j]=0;    //���ֵ����Ԫ�ر�Ϊ0
	}
	//�ж�С��ײ���߿���߱�����Ϸʧ��
	if(canvas[newHead_i][newHead_j]==-1)
	{
		printf("��Ϸʧ��!\n");
		exit(0);
	}
	else
	{
		canvas[newHead_i][newHead_j]=1;
	}
}
void show()        //��ʾ����
{
	int x,y;
	putimage(0, 0, &img_bk);	// ��ʾ����
	for (x=0;x<50;x++)
	{
		for (y=0;y<50;y++)
		{
			if(canvas[y][x]==-1)
			{
				//���߿�
				setcolor(WHITE);
				setfillcolor(BLACK);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5); 
			}
			else if (canvas[y][x]==1)
			{
				//����ͷ
				setcolor(RED);
				setfillcolor(RED);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5);
			}
			else if (canvas[y][x]>1)
			{
				//������
				setcolor(RED);
				setfillcolor(YELLOW);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5);
			}
			else if (canvas[y][x]==-2)
			{
				//��ʳ��
				setcolor(RED);
				setfillcolor(BLUE);
				fillrectangle(10*x-5,10*y-5,10*x+5,10*y+5);
			}
		}
	}
	setcolor(WHITE);
	setfillcolor(WHITE);
	outtextxy(210,430,"�÷֣�");
	// �����ֵ���Ƚ����ָ�ʽ�����Ϊ�ַ��� (VC6)
	char s[5];
	sprintf(s, "%d", grade);
	outtextxy(250, 430, s);
	Sleep(120);
}
void updateWithoutinput()     //���û������޹صĸ���
{
	moveSnakeByDirection();
}
void updteWithinput()         //���û������йصĸ���
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
	startup();         //���ݳ�ʼ��
	while (1)          //��Ϸѭ��ִ��
	{
		show();        //��ʾ����
		updateWithoutinput();     //���û������޹صĸ���
		updteWithinput();         //���û������йصĸ���
	}
	return 0;
}