#include<iostream>
using namespace std;
int main()
{
	char date[80];
	cin>>date;
	for(int i=0;date[i]!='\0';i++)
	{
		if(date[i]>='a'&&date[i]<='z')
			date[i]-=32;
		else
			date[i]+=32;
	}
	cout<<date<<endl;
	return 0;
}