
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class RECT
{
	public:
		int left,right,ceil,bottom;
};

int w,h;

void solve()
{
	int n;
	scanf("%d",&n);

	vector<RECT> input(n);
	set<int> xPos;
	set<int> yPos;

	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&(input[i].left),&(input[i].bottom),
				&(input[i].right),&(input[i].ceil));
		input[i].right--,input[i].ceil--;

		if(0<input[i].left)
			xPos.insert(input[i].left-1);
		xPos.insert(input[i].left);
		if(input[i].left<w-1)
			xPos.insert(input[i].left+1);

		if(0<input[i].right)
			xPos.insert(input[i].right-1);
		xPos.insert(input[i].right);
		if(input[i].right<w-1)
			xPos.insert(input[i].right+1);

		if(0<input[i].bottom)
			yPos.insert(input[i].bottom-1);
		yPos.insert(input[i].bottom);
		if(input[i].bottom<h-1)
			yPos.insert(input[i].bottom+1);

		if(0<input[i].ceil)
			yPos.insert(input[i].ceil-1);
		yPos.insert(input[i].ceil);
		if(input[i].ceil<h-1)
			yPos.insert(input[i].ceil+1);
	}
	yPos.insert(0),yPos.insert(h-1);
	xPos.insert(0),xPos.insert(w-1);

	int hh=yPos.size(),ww=xPos.size();
	//printf("hh=%d ww=%d\n",hh,ww);

	vector<string> board(hh,string(ww,'.'));
	for(int i=0;i<n;i++)
	{
		int r,l,b,c;
		r=distance(xPos.begin(),xPos.find(input[i].right));
		l=distance(xPos.begin(),xPos.find(input[i].left));
		b=distance(yPos.begin(),yPos.find(input[i].bottom));
		c=distance(yPos.begin(),yPos.find(input[i].ceil));

		//printf("%d %d %d %d\n",l,b,r,c);

		for(int y=b;y<=c;y++)
			for(int x=l;x<=r;x++)
			{
				board[y][x]='B';
			}
	}

	/*for(int k=0;k<hh;k++)
		cout << board[k] << endl;
	cout << endl;*/

	int ans=0;
	for(int y=0;y<hh;y++)
		for(int x=0;x<ww;x++)
			if(board[y][x]=='.')
			{
				ans++;

				char color=board[y][x];
				queue<pair<int,int> > que;
				que.push(make_pair(y,x));

				while(!que.empty())
				{
					int yy=que.front().first,xx=que.front().second;
					que.pop();

					if(yy<0 || hh<=yy || xx<0 || ww<=xx || board[yy][xx]!=color)
						continue;
					board[yy][xx]='C';

					que.push(make_pair(yy-1,xx));
					que.push(make_pair(yy+1,xx));
					que.push(make_pair(yy,xx-1));
					que.push(make_pair(yy,xx+1));
				}
			}

	printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d%d",&w,&h);
		if(w==0 && h==0)
			break;
		solve();
	}
	return 0;
}


