#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

int field[60][60];
int cache[60][60][60][60];

class CountPaths 
{
	public:

		int rec(int y,int x,int v,int l)
		{
			if(y<1 || x<1 || v<0)
				return 0;
			else
			{
				int &r=cache[y][x][v][l];

				if(r!=-1)
					;
				else if(y==1 && x==1)
				{
					if(field[y][x]!=-1 && v==1)
						r=(field[y][x]<l)?1:0;
					else if(field[y][x]==-1 && v==0)
						r=1;
					else
						r=0;
				}
				else if(field[y][x]!=-1 && field[y][x]<l)
					r=(rec(y-1,x,v-1,field[y][x])+rec(y,x-1,v-1,field[y][x]))%1000007;
				else if(field[y][x]==-1)
					r=(rec(y-1,x,v,l)+rec(y,x-1,v,l))%1000007;
				else
					r=0;

				return r;
			}
		}

		vector <int> difPaths(int r, int c, vector <int> fieldrow, vector <int> fieldcol) 
		{
			memset(cache,-1,sizeof(cache));
			for(int i=0;i<=r;i++)
				for(int j=0;j<=c;j++)
					field[i][j]=-1;
			for(int i=0;i<fieldrow.size();i++)
				field[fieldrow[i]][fieldcol[i]]=i;

			vector<int> ans;
			for(int i=0;i<=fieldrow.size();i++)
				ans.push_back(rec(r,c,i,51));

			return ans;
		}
};

