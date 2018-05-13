#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	int sum;
	for(int i=100;i<999;i++)
	{
		int temp=i*i;
		a=temp%10;
		b=(temp/10)%10;
		c=(temp/100)%10;
		sum=c*100+b*10+a;
		if(i==sum)
			cout<<i<<endl;
	}
	return 0;
}