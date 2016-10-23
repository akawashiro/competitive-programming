#include <vector>
#include <string>
using namespace std;

class UnfoldingTriangles
{
	public:
		int solve(vector <string> grid, int unfoldLimit)
		{
			int width=grid[0].size(),height=grid.size();
			int ans=-1;
			for(int x=0;x<width;x++)
				for(int y=0;y<height;y++)
					for(int scale=1;scale<=min(x,y)+1;scale++)
					{
						bool isEdge=true;
						int require=0;
						for(int px=x-scale+1,py=y;px<=x;px++,py--)
							if(grid[py][px]!='/')
							{
								isEdge=false;
								break;
							}
						if(x!=width-1)
							for(int py=y-scale+1;py<=y;py++)
								if(grid[py][x+1]=='#')
								{
									isEdge=false;
									break;
								}
						if(y!=height-1)
							for(int px=x-scale+1;px<=x;px++)
								if(grid[y+1][px]=='#')
								{
									isEdge=false;
									break;
								}
						if(!isEdge)
							continue;
						//if(scale==1)
						//	ans=max(ans,1);
						for(int s=scale-1;0<s;s--)
							for(int t=0;t<s;t++)
							{
								if(grid[y-t][x-(scale-1-s)]=='.')
									require+=3000;
								if(grid[y-t][x-(scale-1-s)]=='/')
									require++;
							}
						if(require<=unfoldLimit)
							ans=max(ans,(scale*scale+scale)/2);
					}
			return ans;
		}
};
