#include "BigInt.h"
#include<iostream>
using namespace std;
int main()
{
	BigInt x,y;
	cout<<"持续输入两个整数X,Y中间用空格隔开，输出结果如下"<<endl; 
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
