#include <algorithm>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Q
{
	public:
		int y,x;
		char s;
};

class FloodRelief
{
	public:
		int minimumPumps(vector <string> heights)
		{
			int h=heights.size(),w=heights[0].size();
			int ans=0;

			for(char c='a';c<='z';c++)
				for(int y=0;y<h;y++)
					for(int x=0;x<w;x++)
						if(heights[y][x]==c)
						{
							ans++;
							queue<Q> que;
							Q q;q.y=y;q.x=x;q.s=c;
							que.push(q);

							while(!que.empty())
							{
								int yy=que.front().y,xx=que.front().x;
								char ss=que.front().s;
								que.pop();

								if(yy<0 || h<=yy || xx<0 || w<=xx)
									continue;
								if(heights[yy][xx]=='#')
									continue;
								if(heights[yy][xx]<ss)
									continue;

								q.y=yy-1,q.x=xx,q.s=heights[yy][xx];
								que.push(q);
								q.y=yy+1,q.x=xx,q.s=heights[yy][xx];
								que.push(q);
								q.y=yy,q.x=xx-1,q.s=heights[yy][xx];
								que.push(q);
								q.y=yy,q.x=xx+1,q.s=heights[yy][xx];
								que.push(q);

								heights[yy][xx]='#';
							}
						}

			return ans;
		}
};

