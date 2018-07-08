#include "BigInt.h"
#include<iostream>
using namespace std;
int main()
{
	BigInt x,y;
	cout<<"持续输入两个整数X,Y中间用空格隔开，输出结果如下"<<endl; 
	while(cin>>x>>y)
	{
		cout<<"和 "<<x+y<<endl;
		cout<<"差 "<<x-y<<endl;
		cout<<"积 "<<x*y<<endl;
		cout<<"除 "<<x/y<<endl;
		cout<<"余 "<<x%y<<endl;
	}
	return 0;
}
