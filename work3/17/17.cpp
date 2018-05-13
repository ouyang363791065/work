#include<iostream>
using namespace std;
#define M 4
#define N 3
int main()
{
	int date[M][N];
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>date[i][j];
		}
	}
	for(int m=0;m<N;m++)
	{
		for(int n=0;n<M;n++)
		{
			cout<<date[n][m]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
