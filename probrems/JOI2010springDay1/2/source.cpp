#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long LL;

int main()
{
	int l,n;
	LL ans=0;
	scanf("%d%d",&l,&n);
	vector<int> odd,even,other;
	set<pair<int,int> > ses;
	set<pair<int,int> > sed;
	for(int i=0;i<n;i++)
	{
		int x,y,s,d;
		scanf("%d%d",&x,&y);
		s=x+y,d=abs(x-y);
		s=(s<l)?s+1:l-(s-l+1),d=(l-d);
		ses.insert(make_pair(x+y<l,s));
		sed.insert(make_pair(x<y,d));
	}
	for(set<pair<int,int> >::iterator it=ses.begin();it!=ses.end();it++)
	{
		int s=(*it).second;
		if(s%2==0)
			even.push_back(s);
		else
			odd.push_back(s);
		ans+=s;
		//printf("s=%d ",s);
	}
	//printf("\n");
	sort(even.begin(),even.end());
	sort(odd.begin(),odd.end());
	/*for(int i=0;i<odd.size();i++)
		printf("odd[%d]=%d ",i,odd[i]);
	printf("\n");
	for(int i=0;i<even.size();i++)
		printf("even[%d]=%d ",i,even[i]);
	printf("\n");*/
	for(set<pair<int,int> >::iterator it=sed.begin();it!=sed.end();it++)
	{
		int d=(*it).second;
		ans+=d;
		if(l%2==1)
			if(d%2==0)
			{
				ans-=even.end()-lower_bound(even.begin(),even.end(),(l-d));
			}
			else
			{
				ans-=odd.end()-lower_bound(odd.begin(),odd.end(),(l-d));
			}
		else
			if(d%2==1)
			{
				ans-=even.end()-lower_bound(even.begin(),even.end(),(l-d));
			}
			else
			{
				ans-=odd.end()-lower_bound(odd.begin(),odd.end(),l-d);
			}

	}
	printf("%lld\n",ans);
}
