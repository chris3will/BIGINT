#include "BigInt.h"
#include<iostream>
using namespace std;
BigInt ntwo(BigInt n);
BigInt ntwo(BigInt n)
{
	BigInt two("2");
	BigInt one("1");
	BigInt zero("0");
	if((n==zero))
	{
		return one;
	}
	else
	{
		BigInt nsub1((n-one).getstring());
		BigInt haventwo(ntwo(nsub1).getstring());
		return two*haventwo;
	}
}
int main()
{
	cout<<"���������һ������n���м��ÿո������ֱ���㲻������λ�ã������ʾ2^n;"<<endl;
	BigInt n;
	
	BigInt zero("0");
	BigInt one("1");
	BigInt two("2");
	while(cin>>n)
	{
	
	cout<<ntwo(n)<<endl; 
	}
	return 0;
}
