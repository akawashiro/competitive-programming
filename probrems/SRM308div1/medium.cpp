#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

class CornersGame
{
	public:

		int cache[36][36][36][36];

		int countMoves(vector<string> board)
		{
			memset(cache,-1,sizeof(cache));
			int mv[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
			int jp[4][2]={{0,-2},{0,2},{-2,0},{2,0}};
			vector<int> firstState;
			firstState.push_back(28);
			firstState.push_back(29);
			firstState.push_back(34);
			firstState.push_back(35);
			queue<pair<vector<int>,int> > que;
			que.push(make_pair(firstState,0));
			
			while(!que.empty())
			{
				int dist=que.front().second;
				vector<int> state=que.front().first;
				que.pop();
				sort(state.begin(),state.end());
				int &r=cache[state[0]][state[1]][state[2]][state[3]];
				if(r!=-1 && r<=dist)
					continue;
				r=dist;

				vector<string> b=board;
				for(int i=0;i<4;i++)
					b[state[i]/6][state[i]%6]='s';

				for(int i=0;i<4;i++)
					for(int j=0;j<4;j++)
					{
						int yy=state[i]/6+mv[j][0];
						int xx=state[i]%6+mv[j][1];
						if(0<=yy && yy<6 && 0<=xx && xx<6 && b[yy][xx]=='.')
						{
							vector<int> v=state;
							v[i]=yy*6+xx;
							que.push(make_pair(v,dist+1));
						}
						int yj=state[i]/6+jp[j][0];
						int xj=state[i]%6+jp[j][1];
						if(0<=yy && yy<6 && 0<=xx && xx<6 && b[yy][xx]=='s' 
								&& 0<=yj && yj<6 && 0<=xj && xj<6 && b[yj][xj]=='.')
						{
							vector<int> v=state;
							v[i]=yj*6+xj;
							que.push(make_pair(v,dist+1));
						}
					}
			}

			return cache[0][1][6][7];
		}
};

