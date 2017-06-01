#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

int R;
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int W[2],H[2],X[2],Y[2];
int office[2][500][500];
vector<int> roomNum[2];
vector<int> level[2];

void input(int num)
{
	//printf("input%d-s\n",num);

	cin >> W[num] >> H[num] >> X[num] >> Y[num];
	X[num]--;
	Y[num]--;

	//printf("input %d--W=%d,H=%d,X=%d,Y=%d\n",num,W[num],H[num],X[num],Y[num]);

	for(int i=0;i<H[num];i++)
		for(int j=0;j<W[num];j++)
			scanf("%d",&office[num][i][j]);


	/*for(int i=0;i<H[num];i++)
	{
		for(int j=0;j<W[num];j++)
			printf("%4d",office[num][i][j]);
		printf("\n");
	}*/

	//printf("input%d-e\n",num);
}

void BFS(int num)
{
	//printf("BFSs-%d\n",num);

	bool isAdded[H[num]][W[num]];
	memset(isAdded,false,sizeof(isAdded));

	priority_queue<
		pair<int,pair<int,int> >,
		vector<pair<int,pair<int,int> > >,
		greater<pair<int,pair<int,int> > >
			> que;

	int ro=0;
	int le=0;

	que.push(make_pair(1,make_pair(X[num],Y[num])));
	isAdded[Y[num]][X[num]]=true;

	level[num].clear();
	roomNum[num].clear();

	while(que.size()!=0)
	{
		int l=que.top().first;
		int x=que.top().second.first;
		int y=que.top().second.second;
		que.pop();

		//printf("poped l=%d x=%d y=%d nowle=%d\n",l,x,y,le);
		

		if(le < l)
		{
			if(le!=0)
			{
				level[num].push_back(le);
				roomNum[num].push_back(ro);
			}
			le=l;
		}

		ro++;

		for(int i=0;i<4;i++)
		{
			int xx=x+mv[i][0],yy=y+mv[i][1];
			if(!(0<=xx && xx<W[num] && 0<=yy && yy<H[num]))
				continue;
			if(isAdded[yy][xx])
				continue;

			int ll=office[num][yy][xx];
			que.push(make_pair(ll,make_pair(xx,yy)));
			//printf("pushed l=%d x=%d y=%d\n",ll,xx,yy);
			isAdded[yy][xx]=true;
		}
	}
	level[num].push_back(le);
	roomNum[num].push_back(ro);

	//for(int i=0;i<level[num].size();i++)
	//	printf("level=%d room=%d\n",level[num][i],roomNum[num][i]);

	//printf("BFSe-%d\n",num);
}

void solve()
{
	while(1)
	{
		cin >> R;
		if(R==0)
			break;

		input(0);
		BFS(0);
		input(1);
		BFS(1);

		int ans=(1<<28);
		for(int i=0;i<(int)roomNum[0].size();i++)
		{
			if(R-roomNum[0][i]<=0)
			{
				ans=min(ans,level[0][i]);
				continue;
			}

			vector<int>::iterator it;
			it=lower_bound(roomNum[1].begin(),roomNum[1].end(),R-roomNum[0][i]);
			if(it==roomNum[1].end())
				continue;

			int j=it-roomNum[1].begin();
			int a=level[0][i]+level[1][j];
			ans=min(ans,a);
		}
		printf("%d\n",ans);
	}
}

int main()
{
	solve();
}

