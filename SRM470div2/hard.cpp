#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

inline int ABS(int n)
{
	return (n<0) ? -n : n;
}

class EDGE
{
	public:
		int left,right,cost;
		bool operator> (const EDGE e)
			const{
				return (cost>e.cost);
			}
};

class UNIONFIND
{
	private:
		vector<int> data;

	public:

		UNIONFIND (int size)
		{
			data=vector<int>(size);
			for(int i=0;i<size;i++)
				data[i]=i;
		}

		bool isSame(int a,int b)
		{
			return (root(a)==root(b));
		}

		int root(int index)
		{
			if(data[index]==index)
				return data[index];
			else
				return data[index]=root(data[index]);
		}

		void set(int a,int b)
		{
			if(isSame(a,b))
				return;
			else
				data[root(a)]=data[root(b)];
		}
};

class ActivateGame 
{
	public:
		int findMaxScore(vector <string> grid)
		{
			int h=grid.size(),w=grid[0].size();

			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					if('0'<=grid[i][j] && grid[i][j]<='9')
						grid[i][j]-='0';
					else if('a'<=grid[i][j] && grid[i][j]<='z')
						grid[i][j]-='a',grid[i][j]+=10;
					else if('A'<=grid[i][j] && grid[i][j]<='Z')
						grid[i][j]-='A',grid[i][j]+=36;
				}

			/*for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
					printf("%4d",(int)grid[i][j]);
				printf("\n");
			}*/

			UNIONFIND unionfind(h*w);
			vector<EDGE> branch(h*w);

			for(int l=0;l<h*w;l++)
				for(int r=l+1;r<h*w;r++)
				{
					int ly,lx,ry,rx;
					ly=l%h,lx=l/h,ry=r%h,rx=r/h;
					
					//printf("ly=%d lx=%d ry=%d rx=%d \n",ly,lx,ry,rx);
					//fflush( stdout );
					
					if( (ly==ry && ABS(lx-rx)==1) || (lx==rx && ABS(ly-ry)==1) )
					{
						EDGE e;
						e.left=l;
						e.right=r;
						e.cost=ABS(grid[ly][lx]-grid[ry][rx]);
						branch.push_back(e);
					}
				}

			sort(branch.begin(),branch.end(),greater<EDGE>());

			int ans=0;
			for(int b=0;b<branch.size();b++)
			{
				int l=branch[b].left,r=branch[b].right,c=branch[b].cost;
				if(!unionfind.isSame(l,r))
				{
					//printf("l=%d r=%d c=%d \n",l,r,c);
					unionfind.set(r,l);
					ans+=c;
				}
			}
			return ans;
		}
};
