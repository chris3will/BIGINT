#include "BigInt.h"
#include<iostream>
using namespace std;
int main()
{
	BigInt x,y;
	cout<<"����������������X,Y�м��ÿո����������������"<<endl; 
	while(cin>>x>>y)
	{
		cout<<x+y<<endl;
		cout<<x-y<<endl;
		cout<<x*y<<endl;
		cout<<x/y<<endl;
		cout<<x%y<<endl;
	}
	return 0;
}
