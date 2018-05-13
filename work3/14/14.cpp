#include<iostream>
using namespace std;
int main()
{
	int date[3];
	cin>>date[0]>>date[1]>>date[2];
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<3-i;j++)
		{
			if(date[i]>date[i+j])
			{
				int temp=date[i];
				date[i]=date[i+j];
				date[i+j]=temp;
			}
		}
	}
	cout<<date[0]<<" "<<date[1]<<" "<<date[2];
	return 0;
}