#include<iostream>
using namespace std;
int fb(int n)
{
	if(n==1||n==2||n==3)
	{
		return 1;
	}
	else
	{
		return 2*fb(n-1)+3*fb(n-2)+5*fb(n-3);
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<fb(n)<<endl;
	return 0;
 } 
