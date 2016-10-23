#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int insect[55][55];
int DP[55][55];

int main()
{
	int h,w;
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			char c='\n';
			while(c=='\n')
				scanf("%c",&c);
			insect[i][j]=c-'0';
		}
	for(int y=h-1;0<=y;y--)
		for(int x=w-1;0<=x;x--)
		{
			if(y==h-1 && x==w-1)
			{
				DP[y][x]=0;
			}
			else
			{
				DP[y][x]=10*50*50;
				if(y<h-1)
					DP[y][x]=min(DP[y][x],DP[y+1][x]);
				if(x<w-1)
					DP[y][x]=min(DP[y][x],DP[y][x+1]);
				DP[y][x]+=insect[y][x];
			}
		}
	printf("%d\n",DP[0][0]);
	return 0;
}

