#include <vector>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

class MarblesRegroupingHard
{
	public:
		int minMoves(vector<string> input)
		{
			vector<vector<int> > boxes;
			for(int i=0;i<(int)input.size();i++)
			{
				vector<int> v;
				stringstream ss(input[i]);
				int a;
				while(ss >> a)
					v.push_back(a);
				boxes.push_back(v);
			}

			int numBox=boxes.size();
			int numColor=boxes[0].size();

			int gatherCost[numBox][numColor];
			for(int i=0;i<numBox;i++)
				for(int j=0;j<numColor;j++)
				{
					int a=0;
					for(int k=0;k<numBox;k++)
						if(k!=i)
							a+=boxes[k][j];
					gatherCost[i][j]=a;
				}

			int DP[numBox+1][(1<<numColor)];
			for(int b=numBox;0<=b;b--)
				for(int c=(1<<numColor)-1;0<=c;c--)
				{
					DP[b][c]=(1<<25);
					if(c==(1<<numColor)-1)
						DP[b][c]=0;
					else if(b!=numBox)
					{
						for(int i=0;i<numColor;i++)
							if(c ^ (1<<i))
								DP[b][c]=min(DP[b][c],DP[b+1][c|(1<<i)]+gatherCost[b][i]);
						DP[b][c]=min(DP[b][c],DP[b+1][c]);
					}
				}

			return DP[0][0];
		}
};

