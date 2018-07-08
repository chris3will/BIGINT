#include "BigInt.h"
#include<iostream>
using namespace std;
BigInt digui(BigInt t);
BigInt digui(BigInt t)
{
	BigInt tt(t.getstring());
	BigInt one("1");
	BigInt zero("0");
	if((tt==one)||(tt==zero))
	{
		return one;
	}
	else
	{
		string temp=(tt-one).getstring();
		BigInt tsub1(temp);
		BigInt diguide(digui(tsub1).getstring());
		return tt*diguide;
	}
}
int main()
{
	BigInt n;
	cout<<"请持续输入整数t，输出结果为t的阶乘；"<<endl; 
	int sign=0;
	int shijishu=0;//0为真; 
	BigInt zero("0");
	BigInt one("1");
	BigInt two("2");
	while(cin>>n)
	{
		if(n<zero)
	{
		sign=1;
	}
	else
	{
		sign=0;
	}
	string a(n.getstring(),sign,-1);
	BigInt nn(a);
	if((nn%two).getstring()=="1")
	{
		shijishu=1;
	}
	else
	{
		shijishu=0;
	}
	if((shijishu==1)&&(sign==1))
	{
		cout<<"-";
	}
		cout<<digui(nn)<<endl;
	} 
	return 0;
}
