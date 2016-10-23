#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> ai,can;
vector<pair<int,int> > bi;

int ok(int k)
{
	double sumA=0;
	for(int i=0;i<n;i++)
		can[i]=1;
	for(int i=0;i<k;i++)
		sumA+=ai[i];
	int lastA=k;
	for(int b=0;b+k<=n;b++)
	{
		if(sumA/(double)k<=(double)bi[b].first)
			return 1;
		int a=-bi[b].second;
		int tB=lower_bound(ai.begin(),ai.end(),a)-ai.begin();
		int tE=upper_bound(ai.begin(),ai.end(),a)-ai.begin();
		int tP;
		for(tP=tB;tP<tE;tP++)
			if(can[tP])
				break;
		can[tP]=0;
		if(tP<lastA)
		{
			sumA-=ai[tP];
			while(!can[lastA])
				lastA++;
			sumA+=ai[lastA-1];
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
		bi.push_back(make_pair(a,-b));
	}
	sort(ai.begin(),ai.end());
	sort(bi.begin(),bi.end());
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
		printf("%d",b);
	return 0;
}

