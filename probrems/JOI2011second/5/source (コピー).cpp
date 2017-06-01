#include <stdio.h>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> ai,can,bi2ai;
vector<pair<int,int> > bi;

int ok(int k)
{
	if(k==0)
		return 1;
	double sumA=0;
	for(int i=0;i<n;i++)
		can[i]=1;
	for(int i=0;i<k;i++)
		sumA+=ai[i];
	int lastA=k-1;
	for(int b=0;b+k<=n;b++)
	{
		if(sumA/(double)k<=(double)bi[b].first)
			return 1;
		int tP=bi2ai[b];
		can[tP]=0;
		if(tP<=lastA)
		{
			sumA-=ai[tP];
			lastA++;
			if(lastA>=n)
				return 0;
			while(!can[lastA])
				lastA++;
			sumA+=ai[lastA];
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ai.push_back(a);
		can.push_back(1);
		bi2ai.push_back(-1);
		can[i]=1;
		bi.push_back(make_pair(b,-a));
	}
	sort(ai.begin(),ai.end());
	sort(bi.begin(),bi.end());
	for(int i=0;i<n;i++)
	{
		int a=-bi[i].second;
		int tB=lower_bound(ai.begin(),ai.end(),a)-ai.begin();
		int tE=upper_bound(ai.begin(),ai.end(),a)-ai.begin();
		int tP;
		for(tP=tB;tP<tE;tP++)
			if(can[tP])
				break;
		can[tP]=0;
		bi2ai[i]=tP;
	}
	int b=0,c=n;
	while(1<c-b)
	{
		int m=(b+c)/2;
		if(ok(m))
			b=m;
		else
			c=m;
	}
	if(ok(c))
		printf("%d\n",c);
	else
		printf("%d\n",b);
	return 0;
}

