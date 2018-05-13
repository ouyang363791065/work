#include<iostream>
using namespace std;
int main()
{
	int date;
	int test[10000];
	int a[]={1,3,7,8};
	int flag=0;
	int cnt=0;
	int n=0;

	cin>>date;
	getchar();
	for(int i=0;i<date;i++)
	{
		cin>>test[i];
		getchar();
	}
	cout<<endl;
	for(int j=0;j<date;j++)
	{
		while(test[j]>8)
		{
			test[j]-=8;
			cnt++;
		}
		for(int m=0;m<4;m++)
		{
			if(test[j]==a[m])
				flag=1;
		}
		if(flag==1)
		{
			if(cnt%2==0)
				cout<<"0"<<endl;
			else
				cout<<"1"<<endl;
			flag=0;
			continue;
		}
		while(1)
		{
			test[j]-=1;
			cnt++;
			if(a[0]==test[j])
			{
				flag=1;
			}
			if(flag)
				break;
		}
		if(cnt%2==0)
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
		flag=0;
	}
	return 0;
}