#include<iostream>
using namespace std;
int main()
{
	int n;   //n=10
	cin>>n;
	int sum=1;
	while(n!=0)
	{
		sum*=2;
		n--;
	}
	cout<<sum+1;   //1025
	return 0;
}