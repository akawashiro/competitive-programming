#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string reJ(string s)
{
	int n=s.size();
	string r(n,'#');
	for(int i=0;i<n;i++)
		r[i]=s[(i-1+n)%n];
	return r;
}

string reC(string s)
{
	int n=s.size();
	string r(n,'#');
	for(int i=0;i<n;i++)
		r[i]=s[(i+1+n)%n];
	return r;
}

string reE(string s)
{
	int n=s.size();
	int w=(n%2==0)?n/2:(n/2+1);
	for(int i=0;i+w<n;i++)
		swap(s[i],s[i+w]);
	return s;
}

string reA(string s)
{
	reverse(s.begin(),s.end());
	return s;
}

string reP(string s)
{
	int n=s.size();
	for(int i=0;i<n;i++)
		if('0'<=s[i] && s[i]<='9')
			s[i]=(s[i]=='0')?'9':s[i]-1;
	return s;
}

string reM(string s)
{
	int n=s.size();
	for(int i=0;i<n;i++)
		if('0'<=s[i] && s[i]<='9')
			s[i]=(s[i]=='9')?'0':s[i]+1;
	return s;
}

int main()
{
	int n;
	cin>>n;
	for(n;0<=n;n--)
	{
		string order,enc;
		cin>>order>>enc;
		for(int i=(int)order.size()-1;0<=i;i--)
		{
			if(order[i]=='J')
				enc=reJ(enc);
			else if(order[i]=='J')
				enc=reJ(enc);
			else if(order[i]=='C')
				enc=reC(enc);
			else if(order[i]=='E')
				enc=reE(enc);
			else if(order[i]=='A')
				enc=reA(enc);
			else if(order[i]=='P')
				enc=reP(enc);
			else if(order[i]=='M')
				enc=reM(enc);
			else
				;
		}
		cout<<enc<<endl;
	}
	return 0;
}

