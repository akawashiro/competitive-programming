#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long LL;

LL damage[100000+10],heal[100000+10];

int main()
{
	int n,ans=0;
	LL H,hp;
	scanf("%d%lld",&n,&H);
	hp=H;
	for(int i=0;i<n;i++)
		scanf("%lld%lld",damage+i,heal+i);
	priority_queue<int,vector<int>,greater<int> > que;

	for(int step=0;step<n;step++)
	{
		que.push(heal[step]);
		hp-=damage[step];
		while(hp<=0)
		{
			hp+=que.top();
			que.pop();
			ans++;
		}
		if(H<hp)
			hp=H;
	}
	printf("%d\n",ans);
	return 0;
}


