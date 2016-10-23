#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int n,S;
int M[30];
int cache[1<<13][25];

int rec(int left,int k)
{
	int &r=cache[left][k];
	if(cache[left][k]!=-1)
		;
	else if(left==1)
		r=0;
	else
	{
		r=0;
		for(int i=1;i<left && i<=M[k];i++)
			if(!rec(left-i,(k+1)%(n*2)))
				r=1;
	}
	return r;
}

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		cin>>S;
		for(int i=0;i<n*2;i++)
			cin>>M[i];
		memset(cache,-1,sizeof(cache));
		cout<<rec(S,0)<<endl;
	}
	return 0;
}

