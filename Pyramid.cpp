#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <stack>

using namespace std;
typedef vector<int> V; //(h,(y,x))
typedef long long LL;
LL desert[3000+10][3000+10];
int isUsed[3000][3000];
int mv[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
stack<LL> sta[3000+10];

LL makeLL(int y,int x,int b)
{
	LL r=y;
	r*=5000;
	r+=x;
	r*=5000;
	r+=b;
	return r;
}

void parseLL(LL l,int &y,int &x,int &b)
{
	b=l%5000;
	l/=5000;
	x=l%5000;
	l/=5000;
	y=l%5000;
}

int main()
{
	int H,W;
	cin>>H>>W;
	vector<int> chr[9];
	chr[0].push_back(0);chr[0].push_back(1);chr[0].push_back(3);
	chr[1].push_back(1);
	chr[2].push_back(1);chr[2].push_back(2);chr[2].push_back(4);
	chr[3].push_back(3);
	chr[4].push_back(4);
	chr[5].push_back(3);chr[5].push_back(5);chr[5].push_back(6);
	chr[6].push_back(6);
	chr[7].push_back(6);chr[7].push_back(7);chr[7].push_back(4);
	for(int i=0;i<8;i++)
		chr[8].push_back(i);

	{
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			int h,x,y;
			cin>>x>>y>>h;
			sta[h].push(makeLL(y,x,8));
			desert[y][x]=max(desert[y][x],(LL)h);
		}
	}
	int qNum=0;
	for(int h=3000;0<h;h--)
	{
		while(!sta[h].empty())
		{
			qNum++;
			int y,x,b;
			parseLL(sta[h].top(),y,x,b);
  		//cout<<h<<" "<<y<<" "<<x<<" "<<b<<endl;

			sta[h].pop();
			if(isUsed[y][x])
				continue;
			desert[y][x]=h;
			isUsed[y][x]=1;
			for(int i=0;i<(int)chr[b].size();i++)
			{
				int d=chr[b][i];
				int yy=y+mv[d][0],xx=x+mv[d][1],hh=h-1;
				if(yy<0 || xx<0 || H<=yy || W<=xx || hh<=desert[yy][xx])
					continue;
				desert[yy][xx]=hh;
				sta[hh].push(makeLL(yy,xx,d));
			}
		}
	}
	cout<<"qNum="<<qNum<<endl;
	{
		LL ans=0;
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
				ans+=desert[i][j];
		cout<<ans<<endl;
	}
	return 0;
}

