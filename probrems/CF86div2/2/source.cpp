#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int isWrong[20][20];

int popCount(int _mask)
{
	int r=0;
	for(int i=0;i<28;i++)
		if(_mask & (1<<i))
			r++;
	return r;
}

int main()
{
	map<string,int> s2i;
	map<int,string> i2s;
	vector<string> ans;
	memset(isWrong,0,sizeof(isWrong));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		s2i[s]=i;
		i2s[i]=s;
	}
	for(int i=0;i<m;i++)
	{
		string s,t;
		cin>>s>>t;
		isWrong[s2i[s]][s2i[t]]=1;
		isWrong[s2i[t]][s2i[s]]=1;
	}
	for(int team=0;team<(1<<n);team++)
	{
		int isBad=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if((team&(1<<i)) && (team&(1<<j)) && isWrong[i][j])
					isBad=1;
		if(!isBad && (int)ans.size()<popCount(team))
		{
			ans.clear();
			for(int i=0;i<n;i++)
				if(team & (1<<i))
					ans.push_back(i2s[i]);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<(int)ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}
	
