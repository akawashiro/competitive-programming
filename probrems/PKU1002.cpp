#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string,int> ans;
	for(int i=0;i<n;i++)
	{
		string s,t;
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			if('A'<=s[j] && s[j]<='C')
				t+='2';
			if('D'<=s[j] && s[j]<='F')
				t+='3';
			if('G'<=s[j] && s[j]<='I')
				t+='4';
			if('J'<=s[j] && s[j]<='L')
				t+='5';
			if('M'<=s[j] && s[j]<='O')
				t+='6';
			if('P'<=s[j] && s[j]<='S' && s[j]!='Q')
				t+='7';
			if(s[j]=='T' || s[j]=='U' || s[j]=='V')
				t+='8';
			if(s[j]=='W' || s[j]=='X' || s[j]=='Y')
				t+='9';
			if('0'<=s[j] && s[j]<='9')
				t+=s[j];
		}
		t.insert(3,"-");
		//if(ans.find(t)==ans.end())
		//	ans[t]=1;
		//else
			ans[t]++;
	}
	map<string,int>::iterator it;
	bool isOutputed=false;
	for(it=ans.begin();it!=ans.end();it++)
	{
		string s=(*it).first;
		int a=(*it).second;
		if(a!=1)
		{
			cout << s;
			cout << " " << a << endl;
			isOutputed=true;
		}
	}
	if(!isOutputed)
		cout << "No duplicates." << endl;

	return 0;
}

