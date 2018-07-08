#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>
#include <algorithm>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
class BigInt
{
	private	:
		string S;
	public:
		BigInt();
		BigInt(string s);
		void setstring(string s);
		string getstring();
		BigInt operator+(BigInt &x);
		BigInt operator-(BigInt &x);			
		BigInt operator*(BigInt &x);
		BigInt operator/(BigInt &X);
		BigInt operator%(BigInt &x);
		bool operator>(BigInt &x);
		bool operator==(BigInt &x);
		bool operator<(BigInt &x);
		friend ostream &operator<<(ostream& output,const BigInt &);
		friend istream &operator>>(istream& in, BigInt &x);			
};
string BigInt::getstring()
{
	return S;
}
void BigInt::setstring(string s)
{
	S=s;
}
BigInt::BigInt()
{
	S='\0';
}
BigInt::BigInt(string s)
{
	S=s;
}
istream &operator>>(istream& in,BigInt &x)
{
	in>>x.S;
	if(!in)
	{
		BigInt x;
	}
	return in;
}
ostream &operator<<(ostream& output,const BigInt &x)
{
	output<<x.S;
	return output;
}
BigInt BigInt::operator+(BigInt &x)
{//��a����S��
	BigInt ans;
	string& a=this->S;
	string& b=x.S; 
	int flag=0;
	int sign1=0,sign2=0;
	if(a[0]=='-')sign1=1;
	if(b[0]=='-')sign2=1;
	string na(a,sign1,-1);
	string nb(b,sign2,-1);
	if((sign1==0&&sign2==0)||(sign1==1&&sign2==1))
	{//�����������,��������������� 
	 	int t1,t2,sum,flag=0; 
	 	int l1=na.length();
		int l2=nb.length();
		if(l1<l2)
		{
			swap(na,nb);
			int t=l2;
			l2=l1;
			l1=t;
		}//l1,naΪ��ĳ��Ⱥ�����ַ��� 
		while(l1-1>=0)
		{
			t1=na[l1-1]-'0';
			if(l2-1>=0)
			{
				t2=nb[l2-1]-'0';
			}
			else
			{
				t2=0;
			}
			sum=t1+t2+flag;
			na[l1-1]=sum%10+'0';
			flag=sum/10;
			l1--;
			l2--;
		}
		if(flag==1)
		{
			na="1"+na;
		}
		if(sign1==1&&sign2==1)
		{
			na="-"+na;
		}
		ans.S=na;
		return ans;
	}
	else//һ��һ�� 
	{
			if(atoi(na.c_str())>=atoi(nb.c_str()))
			{ //a�ľ���ֵ��b�� 
				 int t1,t2,flag=0,sub;
				 int l1=na.length();
				 int l2=nb.length();
				 while(l1-1>=0)
				 {
				 	t1=na[l1-1]-'0'-flag;
				 	if(l2-1>=0)
				 	{
				 		t2=nb[l2-1]-'0';		
					 }
					  else
					{
					 	t2=0;
					}
					 if(t1>=t2)
					{
						sub=t1-t2;
						flag=0;
					}	
						else
						{
							sub=t1+10-t2;
							flag=1;
						}
						na[l1-1]=sub+'0';
					 l1--;
					 l2--;
				 }
				 if(na[0]=='0')
				 {
				 	if(na.size()==1)
				 	{
				 		ans.S='0';
					 }
				 	else {
					 string na1(na,1,-1);
				 	if(sign1==1)
					 {
					 	ans.S="-"+na1;
					  } 
				 	else ans.S=na1;
					}
				 }
				 else
				 {
				 	if(sign1==1)
					 {
					 	ans.S="-"+na;
					  } 
				 	else ans.S=na;
				 }
				 return ans;
			}
			else
			{
				//a�ľ���ֵС��b��
				 int t1,t2,flag=0,sub;
				 int l1=nb.length();
				 int l2=na.length();
				 while(l1-1>=0)
				 {
				 	t1=nb[l1-1]-'0'-flag;
				 	if(l2-1>=0)
				 	{
				 		t2=na[l2-1]-'0';		
					 }
					  else
					 {
					 	t2=0;
					 }
					 if(t1>=t2)
					{
							sub=t1-t2;
							flag=0;
					}	
						else
						{
							sub=t1+10-t2;
							flag=1;
						}
						nb[l1-1]=sub+'0';
					 l1--;
					 l2--;
				 }
				 if(nb[0]=='0')
				 {
				 	if(nb.size()==1)
				 	{
				 		ans.S='0';
					 }
				 	else
					 {
					 string nb1(nb,1,-1);
				 	if(sign1==0)
				 	ans.S="-"+nb1;
				 	else
				 	ans.S=nb1;
				 }
				 }
				 else
				 {
				 	if(sign1==0)
				 	ans.S="-"+nb;
				 	else
				 	ans.S=nb;
				 }
				 return ans;
			}
		}
	}//�ӷ�����	
BigInt BigInt::operator%(BigInt &x)
{
	BigInt ans;
	string& a=this->S;
	string& b=x.S; 
	int flag=0;
	int sign1=0,sign2=0;
	if(a[0]=='-')sign1=1;
	if(b[0]=='-')sign2=1;
	string na(a,sign1,-1);
	string nb(b,sign2,-1);
	BigInt beichu(na);
	BigInt chu(nb);
	BigInt zheng((beichu/chu).S);
	BigInt fan((zheng*chu).S);
	BigInt bgf((beichu-fan).S);
	if(na.size()<nb.size())
	{//��ܹؼ� 
		ans.S=a;
	}
 	else if(nb=="0")ans.S="Error!";
 	else if(fan==beichu)
 	{
 		ans.S="0";
	}
	else
	{
		ans.S=(beichu-fan).S;
	}
	if(ans.S[0]=='0'&&ans.S.size()>1)
	{
		ans.S.erase(0,1);
	}
	if(!((sign1==0&&sign2==0)||(sign1==1&&sign2==1)))if(ans.S!="0")ans.S="-"+ans.S;
	return ans;
}
BigInt BigInt::operator-(BigInt &x)
{
	BigInt temp1(this->S);
	BigInt ans;
	//�������жϱ������������ţ�Ϊ���ž�ֱ�ӵ��üӷ���Ϊ���ž���������ǰ��һ�������ٵ��üӷ���
	int sign;
	if(x.S[0]=='-')
	{
		sign=1;
	 } 
	 else
	 {
	 	sign=0;
	 }
	 string t(x.S,sign,-1);
	 BigInt temp2(t);
	 if(sign==1)ans.S=(temp1+temp2).S;
	 else
	 {
	 	BigInt temp3("-"+t);
	 	 ans.S=(temp1+temp3).S;
	 }
	 return ans;
 } //�������üӷ���д�ꣻ 
BigInt BigInt::operator*(BigInt &x)
{
	BigInt ans;
	string& a=this->S;
	string& b=x.S; 
	int sign1=0,sign2=0;
	if(a[0]=='-')sign1=1;
	if(b[0]=='-')sign2=1;
	string na(a,sign1,-1);
	string nb(b,sign2,-1);
	BigInt result("0");//����
	int la=na.size();
	//ȡa��ÿһλ����b�����ݣ�
	BigInt toplus(nb); 
	int count=0;
	while(la-1>=0)
	{
		int cnum=na[la-1]-'0';
		int i=1;
		while(i<=cnum)
		{
			result.S=(result+toplus).S;
			i++;
		}
		toplus.S=toplus.S+'0';
		la--;
	}
	if(!((sign1==0&&sign2==0)||(sign1==1&&sign2==1)))result.S="-"+result.S;
	return result;
} //�˷�д��
  BigInt BigInt::operator/(BigInt &x)
{
	BigInt ans;
	string& a=this->S;
	string& b=x.S; 
	int sign1=0,sign2=0;
	if(a[0]=='-')sign1=1;
	if(b[0]=='-')sign2=1;
	string na(a,sign1,-1);
	string nb(b,sign2,-1);
	int flag=nb.size()-1;
	if(na.size()<nb.size())
	{//��ܹؼ� 
		ans.S="0";
	}
	else if(nb=="0")
	{
		ans.S="error!!!";
	}
	else 
	{
	BigInt jian(nb);
	BigInt def("0"); 
	string temp(na,0,flag+1);
	int tocount=0;
	stringstream sss;
	BigInt ttemp;
	while(flag<=na.size()-1)
	{//�ӱ�������һλ��ʼ�ƶ��� 
		//cout<<"ѭ���տ�ʼflag��na��λ��"<<flag<<endl; 
		ttemp.S=temp;
		//cout<<"����ÿһ��ѭ����temp��"<<temp<<"�������"<<endl;
		while((ttemp-jian)>def)
		{
			tocount++;
			ttemp.S=(ttemp-jian).S;
		}
		//cout<<"����tocount��"<<tocount<<"���������"<<endl;
		sss<<tocount;
		tocount=0;
		temp.clear();
		temp.append(ttemp.S);
		//cout<<"temp�ĳ��ȣ�"<<temp.size()<<"������:"<<temp<<endl;
		flag++;
		temp=temp+na[flag]; 
	}
	ans.S=sss.str();
	}
	if(S[0]=='0'&&S.size()!=1)
	{
		string ssss(this->S,1,-1);
		ans.S=ssss;
	}
	if(!((sign1==0&&sign2==0)||(sign1==1&&sign2==1)))if(!S[0]=='0')ans.S="-"+ans.S;
	return ans;
 } // ����д��
bool BigInt::operator>(BigInt &x)
{
	BigInt t1(this->S);
	BigInt t2(x.S);
	if((t1-t2).S[0]=='-')
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool BigInt::operator==(BigInt &x)
{
	BigInt t1(this->S);
	BigInt t2(x.S);
	if((t1-t2).S[0]=='0')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BigInt::operator<(BigInt &x)
{
	BigInt t1(this->S);
	BigInt t2(x.S);
	if((t1-t2).S[0]=='-')
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif


