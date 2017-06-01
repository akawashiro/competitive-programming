#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int n;
string source;
int cache[1000000];

int rec(int p)
{
	int r=0;
	if(cache[p]!=-1)
		r=cache[p];
	else if(p==n)
		r=1;
	else
	{
		if(p<n-1 && (source[p]=='1' || source[p]=='2'))
			r+=rec(p+2);
		if(source[p]!='0')
			r+=rec(p+1);
	}
	return cache[p]=r;
}

int main()
{
	while(1)
	{
		cin>>source;
		if(source=="0")
			break;
		n=source.size();
		memset(cache,-1,sizeof(cache));
		cout<<rec(0)<<endl;
	}
	return 0;
}

