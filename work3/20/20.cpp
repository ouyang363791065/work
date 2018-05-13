#include<stdio.h>
int count = 0;		//计数变量
char group[3][4] = {{'A','B','C',' '},{'D','E','F',' '},{'G','H','I',' '}};

int exchange(char *a,char *b)
{	//交换
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}
int line_exchange(int m,int n)
{
	int i;
	for( i=0;i<3;i++ )
		exchange(&group[m][i],&group[n][i]);
	return 0;
}
int behind(int m,int n)
{	
	printf("%s %4d\n",group,count+1);
	count++;	//输出当前队列,并计数
	line_exchange(1,2);	
	printf("%s %4d\n",group,count+1);
	line_exchange(1,2);
	count++;
	int i,j;
	for( i=2;i>=0;i-- )
	{
		for( j=0;j<3;j++ )
		{
		    //输出并计数(当前循环结束前，会交换回来)
			exchange(&group[m][i],&group[n][j]);
			printf("%s %4d\n",group,count+1);
			count++;
			line_exchange(1,2);	//队伍交换，输出并计数
			printf("%s %4d\n",group,count+1);
			line_exchange(1,2);
			count++;
			//交换回之前的状
			exchange(&group[m][i],&group[n][j]);
		}
	}
	return 0;
}
int before(int m,int n)	
{	//第一队成员的改变(这个函数中，只改变第三个成员)
	int i,j;
	behind(1,2);	//改变之前，将当前的后两队排列输出
	printf("\n");
	for( i=1;i<3;i++ )
	{
		for( j=0;j<3;j++ )
		{	
			//若大于第二成员，则作为第三成员
			if( (i!=m || j!=n) && group[i][j]>group[0][1] )
			{
				//将符合的队员，作为第一队成员，再进行后两队排列
				exchange(&group[0][2],&group[i][j]);
				behind(1,2);
				printf("\n");
				exchange(&group[0][2],&group[i][j]);
			}
		}
	}
	return 0;
}
int rank()
{	
	before(-1,-1);	
	int i,j = 0;
	for( i=1;i<3;i++ )
	{
		for( j=0;j<3;j++ )
		{
			exchange(&group[0][1],&group[i][j]);
			before(i,j);
			exchange(&group[0][1],&group[i][j]);
		}
	}
	return 0;
}
int main()
{	
	rank();	
	printf("%d \n",count);
	return 0;
}


