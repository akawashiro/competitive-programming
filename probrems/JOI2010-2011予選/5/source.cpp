#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int H,W;

int dist(int x1,int y1,int x2,int y2,vector<vector<int> > town)
{
	town[y1][x1]=0;
	queue<int> qX;
	queue<int> qY;
	qX.push(x1);
	qY.push(y1);

	for(int d=0;town[y2][x2]==-2;d++)
	{
		queue<int> nX,nY;

		while(qX.size()!=0)
		{
			int x=qX.front();
			qX.pop();
			int y=qY.front();
			qY.pop();
			if(0<=y-1 && town[y-1][x]==-2)
			{
				town[y-1][x]=d+1;
				nX.push(x),nY.push(y-1);
			}
			if(y+1<H && town[y+1][x]==-2)
			{
				town[y+1][x]=d+1;
				nX.push(x),nY.push(y+1);
			}
			if(0<=x-1 && town[y][x-1]==-2)
			{
				town[y][x-1]=d+1;
				nX.push(x-1),nY.push(y);
			}
			if(x+1<W && town[y][x+1]==-2)
			{
				town[y][x+1]=d+1;
				nX.push(x+1),nY.push(y);
			}
		}
		qX=nX;
		qY=nY;
	}

	return town[y2][x2];
}

int main()
{
	int N;
	vector<vector<int> > town(1000,vector<int>(1000,-10));
	vector<int> targetX(10);
	vector<int> targetY(10);
	cin >> H >> W >> N;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			char c=getchar();
			if(c=='\n')
				c=getchar();
			town[i][j]=-2;
			if(c=='S')
				targetX[0]=j,targetY[0]=i;
			if('0'<=c && c<='9')
				targetX[c-'0']=j,targetY[c-'0']=i;
			if(c=='X')
				town[i][j]=-1;
		}
	}

	int ans=0;
	for(int i=0;i<N;i++)
		ans+=dist(targetX[i],targetY[i],targetX[i+1],targetY[i+1],town);

	cout << ans << endl;
	return 0;
}
