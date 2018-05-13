#include<stdio.h>
#define High 65
#define Width High*2
int pixel[High][Width] = {0};	
int pow(int m,int n)
{	//���������ݺ���
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
	if( rank==1 )		//�ݹ����
		pixel[x][y] = 1;
	else
	{
		dispose(rank-1,x,y+pow(2,rank-2));				//�����ϲ���
		dispose(rank-1,x+pow(2,rank-2),y);				//��������
		dispose(rank-1,x+pow(2,rank-2),y+pow(2,rank-1));	//��������
	}
	return 0;
}
int show()
{	//�������
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
	printf("����rank��ֵ(1<=rank<=7):");
	scanf("%d",&rank);
	dispose(rank,0,0);	
	show();				
	return 0;
}