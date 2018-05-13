#include<iostream>
using namespace std;
int fzs(int n);
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<fzs(a)+fzs(b)<<endl;
	return 0;
}
int fzs(int n)
{
	int cnt=0;
	int temp;
	while(n!=0)
	{
		temp=n%10;
		cnt=cnt*10+temp;
		n/=10;
	}
	return cnt;
}