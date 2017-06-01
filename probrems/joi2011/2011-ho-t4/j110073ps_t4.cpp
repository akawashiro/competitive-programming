#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long LL;

LL ABS(LL n)
{
	if(n<0)
		return -n;
	return n;
}

int main()
{
	int W,H,N;
	scanf("%d%d%d",&W,&H,&N);
	vector<int> xPos(N);
	vector<int> yPos(N);
	for(int i=0;i<N;i++)
		scanf("%d %d",&xPos[i],&yPos[i]);

	LL ans=((LL)1<<60);
	int minX=0,minY=0;
	for(int xN=0;xN<N;xN++)
		for(int yN=0;yN<N;yN++)
		{
			LL l=0;
			LL maxD=0;
			for(int i=0;i<N;i++)
			{
				l+=(ABS(xPos[xN]-xPos[i])+ABS(yPos[yN]-yPos[i]))*2;
				maxD=max(ABS(xPos[xN]-xPos[i])+ABS(yPos[yN]-yPos[i]),maxD);
			}
			l-=maxD;

			if(l<ans)
			{
				ans=l;
				minX=xPos[xN];
				minY=yPos[yN];
			}
			else if(l==ans && xPos[xN]<minX)
			{
				minX=xPos[xN];
				minY=yPos[yN];
			}
			else if(l==ans && xPos[xN]==minX && yPos[yN]<minY)
			{
				minY=yPos[yN];
			}
		}

	printf("%lld\n",ans);
	printf("%d %d\n",minX,minY);
}

