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
	cout<<"��д��ĸ��"<<cnt_a<<endl<<"Сд��ĸ��"<<cnt_A<<endl;
	return 0;
}