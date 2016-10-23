#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int C,T,K;
	scanf("%d%d%d",&C,&T,&K);
	pair<int,int> p[1000+10];
	for(int i=0;i<C;i++)
	{
		scanf("%d",&p[i].first);
		p[i].second=0;
		for(int j=0;j<p[i].first;j++)
		{
			int a;
			scanf("%d",&a);
			a--;
			p[i].second|=1<<a;
		}
		if(p[i].first<K)
		{
			i--;
			C--;
		}
	}
	sort(p,p+C);
	set<int> se;
	int ans=0;
	for(int i=0;i<C;i++)
		{
			int onbit[30],idx[30];
			for(int j=0,k=0;j<T;j++)
				if(p[i].second & (1<<j))
					onbit[k++]=1<<j;
			for(int j=0;j<p[i].first-K;j++)
				idx[j]=0;
			for(int j=p[i].first-K;j<p[i].first;j++)
				idx[j]=1;
			do{
				int f=0;
				for(int j=0;j<p[i].first;j++)
					if(idx[j])
						f|=onbit[j];
				if(se.find(f)==se.end())
				{
					se.insert(f);
					ans++;
					break;
				}
			}while(next_permutation(idx,idx+p[i].first));
		}
	printf("%d\n",ans);
	return 0;
}


