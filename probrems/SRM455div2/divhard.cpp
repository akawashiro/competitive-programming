#include <string>
#include <vector>

using namespace std;

class DonutsOnTheGrid{
	public:
		long long calc( int H, int W, int seed, int threshold )
		{
			vector<string> grid(H,string(W,'0'));

			for(int y=0;y<H;y++)
				for(int x=0;x<W;x++)
					if(threshold<=(seed=(seed*25173+13849)%65536))
						grid[y][x]='.';

			static bool zero[350][350][350];

			for(int y=0;y<H;y++)
				for(int x1=0;x1<W;x1++){
					zero[y][x1][x1]=(grid[y][x1]=='0');
					for(int x2=x1+1;x2<W;x2++)
						zero[y][x1][x2]=(zero[y][x1][x2-1] && grid[y][x2]=='0');
				}

			long long num=0;
			
			for(int x1=0;x1<W;x1++)
				for(int x2=x1+1;x2<W;x2++){
					int n=0;
					if(zero[y-2][x1][x2])
						n++;
					if(grid[y-1][x1]!='0' || grid[y-1][x2]!='0')
						n=0;
					if(zero[y][x1][x2])
						num+=n;
				}

			return num;
		}
};
