#include "BigInt.h"
#include<iostream>
#include<iomanip>  
using namespace std;
int main()
{
	BigInt x,y;
	cout<<"����������������X,Y�м��ÿո����������������"<<endl; 
	while(cin>>x>>y)
	{	cout<<"һ���жϽ��Ϊ1���棬Ϊ0�Ǽ�!"<<endl; 
		cout<<"X>y? "<<setw(6)<<(x>y)<<endl;
		cout<<"x<y? "<<setw(6)<<(x<y)<<endl;
		cout<<"x==y? "<<setw(5)<<(x==y)<<endl;
	}
	return 0;
}
