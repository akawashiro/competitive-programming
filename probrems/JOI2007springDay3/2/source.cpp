#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n;
int ok[100+10][100+10][100+10];
int minCost[100+10][100+10];
vector<int> x,y;
vector<int> toG[100+10];
vector<int> costG[100+10];

class Q
{
	public:
		int be,no,co;
		Q(int bb,int nn,int cc)
		{
			be=bb,no=nn,co=cc;
		}
		bool operator< (const Q &q) const
		{
			return co>q.co;
		}
};

int main()
{
	{
		int r;
		scanf("%d%d",&n,&r);
		x.push_back(-12345);
		y.push_back(-12345);
		for(int i=0;i<n;i++)
		{
			int xx,yy;
			scanf("%d%d",&xx,&yy);
			x.push_back(xx);
			y.push_back(yy);
		}
		for(int i=0;i<r;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			toG[a].push_back(b);
			toG[b].push_back(a);
			costG[a].push_back(c);
			costG[b].push_back(c);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				long long x1=x[i]-x[j],y1=y[i]-y[j];
				long long x2=x[k]-x[j],y2=y[k]-y[j];
				ok[i][j][k]=((long long)0>=(x1*x2+y1*y2));
			}
	{
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				minCost[i][j]=10000*1000;
		int ans=10000*1000;
		Q q(0,1,0);
		priority_queue<Q> que;
		for(int i=0;i<toG[1].size();i++)
		{
			q.be=1,q.no=toG[1][i],q.co=costG[1][i];
			que.push(q);
		}
		while(!que.empty())
		{
			int bef=que.top().be;
			int now=que.top().no;
			int cos=que.top().co;
			que.pop();
			if(minCost[bef][now]<=cos)
				continue;
			minCost[bef][now]=cos;
			if(now==2)
			{
				ans=min(cos,ans);
				break;
			}
			for(int i=0;i<(int)toG[now].size();i++)
			{
				int m=toG[now][i];
				if(ok[bef][now][m])
				{
					q.be=now,q.no=m,q.co=cos+costG[now][i];
					que.push(q);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

