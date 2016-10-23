#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class SortingGame
{
	public:
		
		int fewestMoves(vector <int> board, int k)
		{
			int n=board.size();
			map<vector<int>,int> dist;
			dist[board]=0;

			queue<vector<int> > q;
			q.push(board);

			while(!q.empty())
			{
				vector<int> v=q.front();
				q.pop();

				int i;
				for(i=0;i<n-1;i++)
					if(v[i]>v[i+1])
						break;
				if(i==n-1)
					return dist[v];

				for(int i=0;i<=n-k;i++)
				{
					vector<int> w=v;
					reverse(w.begin()+i,w.begin()+i+k);
					if(dist.count(w)==0)
					{
						dist[w]=dist[v]+1;
						q.push(w);
					}
				}
			}
			return -1;
		}
};

