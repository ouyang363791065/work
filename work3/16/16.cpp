#include<iostream>
using namespace std;
int main()
{
	char test[30];
	char date[30];
	char ch;
	int cnt=0;
	cin>>test>>ch;
	for(int i=0;test[i]!='\0';i++)
	{
		if(test[i]!=ch)
			date[cnt++]=test[i];
	}
	date[cnt]='\0';
	cout<<date<<endl;
	return 0;
}
