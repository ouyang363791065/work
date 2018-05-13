#include<iostream>
using namespace std;
int main()
{
	int n;
	int date[1000]={0};
	int js=0,os=0;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
		cin>>date[i];
	for(int j=0;j<n;j++)
	{
		if(date[j]%2==0)  //Å¼Êý
			os++;
		else
			js++;
	}
	cout<<js<<" "<<os<<endl;
	return 0;
}