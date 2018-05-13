#include<iostream>
using namespace std;
int main()
{
	char * p="I Love GPLT";
	for(int i=0;*(p+i)!='\0';i++)
		cout<<*(p+i)<<endl;
	return 0;
}