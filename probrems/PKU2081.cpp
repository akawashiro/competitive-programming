#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int used[10000000];

int main()
{
	while(1)
	{
		memset(used,0,sizeof(used));
		int k;
		cin>>k;
		if(k==-1)
			break;
		int a,b=0;
		for(int i=1;i<=k;i++)
		{
			a=(0<b-i && !used[b-i])?b-i:b+i;
			used[a]=1;
			b=a;
		}
		cout<<a<<endl;
	}
	return 0;
}

