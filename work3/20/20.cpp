#include<stdio.h>
int count = 0;		//��������
char group[3][4] = {{'A','B','C',' '},{'D','E','F',' '},{'G','H','I',' '}};

int exchange(char *a,char *b)
{	//����
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
	count++;	//�����ǰ����,������
	line_exchange(1,2);	
	printf("%s %4d\n",group,count+1);
	line_exchange(1,2);
	count++;
	int i,j;
	for( i=2;i>=0;i-- )
	{
		for( j=0;j<3;j++ )
		{
		    //���������(��ǰѭ������ǰ���ύ������)
			exchange(&group[m][i],&group[n][j]);
			printf("%s %4d\n",group,count+1);
			count++;
			line_exchange(1,2);	//���齻�������������
			printf("%s %4d\n",group,count+1);
			line_exchange(1,2);
			count++;
			//������֮ǰ��״
			exchange(&group[m][i],&group[n][j]);
		}
	}
	return 0;
}
int before(int m,int n)	
{	//��һ�ӳ�Ա�ĸı�(��������У�ֻ�ı��������Ա)
	int i,j;
	behind(1,2);	//�ı�֮ǰ������ǰ�ĺ������������
	printf("\n");
	for( i=1;i<3;i++ )
	{
		for( j=0;j<3;j++ )
		{	
			//�����ڵڶ���Ա������Ϊ������Ա
			if( (i!=m || j!=n) && group[i][j]>group[0][1] )
			{
				//�����ϵĶ�Ա����Ϊ��һ�ӳ�Ա���ٽ��к���������
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


