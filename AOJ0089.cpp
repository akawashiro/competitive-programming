#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

vector<int> string2vi(string s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]==',')
			s[i]=' ';
	vector<int> r;
	stringstream ss(s);
	int a;
	while(ss>>a)
		r.push_back(a);
	return r;
}

vector<vector<int> > rhombic;
int cache[100+10][100+10];

int rec(int y,int x)
{
	if(cache[y][x]!=-1)
		return cache[y][x];
	else if(y==rhombic.size()-1)
		return cache[y][x]=rhombic[y][x];
	else
	{
		int r=-1;
		if(x<rhombic[y+1].size())
			r=max(r,rec(y+1,x));
		if(x+1<rhombic[y+1].size() && y<rhombic.size()/2)
			r=max(r,rec(y+1,x+1));
		if(0<x && rhombic.size()/2<=y)
			r=max(r,rec(y+1,x-1));
		return cache[y][x]=r+rhombic[y][x];
	}
}

int main()
{
	string s;
	while(cin>>s)
		rhombic.push_back(string2vi(s));
	memset(cache,-1,sizeof(cache));
	/*for(int i=0;i<rhombic.size();i++)
	{
		for(int j=0;j<rhombic[i].size();j++)
			cout<<rec(i,j)<<" ";
		cout<<endl;
	}*/
	cout<<rec(0,0)<<endl;
	return 0;
}

