#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

int ans[5000+10];

int main()
{
	int n,h,w;
	map<pair<int,int>,int> ma;
	scanf("%d%d%d",&n,&h,&w);
	for(int i=0;i<n;i++)
	{
		int p,q,r,s;
		scanf("%d%d%d%d",&p,&q,&r,&s);
		for(int x=p;x<=r;x++)
			for(int y=q;y<=s;y++)
				ma[make_pair(x,y)]++;
	}
	memset(ans,0,sizeof(ans));
	for(map<pair<int,int>,int>::iterator it=ma.begin();it!=ma.end();it++)
		ans[(*it).second]++;
	for(int i=5000;0<=i;i--)
		if(0<ans[i])
		{
			printf("%d\n%d\n",i,ans[i]);
			break;
		}
	return 0;
}

