#include<iostream>
using namespace std;
int main()
{
	char date[80];
	int cnt_a=0,cnt_A=0;
	cin>>date;
	for(int i=0;date[i]!='\0';i++)
	{
		if(date[i]>='a'&&date[i]<='z')
			cnt_a++;
		if(date[i]>='A'&&date[i]<='Z')
			cnt_A++;
	}
	cout<<"´óĞ´×ÖÄ¸£º"<<cnt_a<<endl<<"Ğ¡Ğ´×ÖÄ¸£º"<<cnt_A<<endl;
	return 0;
}