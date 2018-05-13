#include<stdio.h>
#define High 65
#define Width High*2
int pixel[High][Width] = {0};	
int pow(int m,int n)
{	//求整数的幂函数
	int f;
	if( n==0 )
		f = 1;
	else if( n==1 )
		f = m;
	else
	{
		f = m * pow(m,n-1);
	}
	return f;
}
int dispose(int rank,int x,int y)
{	
	if( rank==1 )		//递归出口
		pixel[x][y] = 1;
	else
	{
		dispose(rank-1,x,y+pow(2,rank-2));				//处理上部分
		dispose(rank-1,x+pow(2,rank-2),y);				//处理左下
		dispose(rank-1,x+pow(2,rank-2),y+pow(2,rank-1));	//处理右下
	}
	return 0;
}
int show()
{	//输出函数
	int i,j;
	for( i=0;i<High;i++ )
	{
		for( j=0;j<Width;j++ )
		{
			if( pixel[i][j]==0 )
				printf(" ");	
			else				
				printf("*");	
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	int rank;
	printf("设置rank的值(1<=rank<=7):");
	scanf("%d",&rank);
	dispose(rank,0,0);	
	show();				
	return 0;
}