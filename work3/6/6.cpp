#include<iostream>
using namespace std;
int main()
{
	int n;
	int yushu;
	int cnt=0;
	char p[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char date[40];
	cin>>n;
	while(n!=0)
	{
		yushu=n%16;
		date[cnt++]=p[yushu];
		n/=16;
	}
	date[cnt]='\0';
	for(int j=cnt-1;j>=0;j--)
		cout<<date[j];
	return 0;
}