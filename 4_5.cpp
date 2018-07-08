#include "BigInt.h"
#include<iostream>
#include<iomanip>  
using namespace std;
int main()
{
	BigInt x,y;
	cout<<"持续输入两个整数X,Y中间用空格隔开，输出结果如下"<<endl; 
	while(cin>>x>>y)
	{	cout<<"一下判断结果为1是真，为0是假!"<<endl; 
		cout<<"X>y? "<<setw(6)<<(x>y)<<endl;
		cout<<"x<y? "<<setw(6)<<(x<y)<<endl;
		cout<<"x==y? "<<setw(5)<<(x==y)<<endl;
	}
	return 0;
}
