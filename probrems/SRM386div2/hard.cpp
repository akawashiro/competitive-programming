//飛ばします、眠いし嫌い

#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LittleTree
{
	public:
		int tree[100][100];
		int depth[100];
		int N,height;

		void DFS(int index,int d)
		{
			for(int i=0;i<N;i++)
				if(tree[index][i])
					DFS(i,d+1);
			depth[index]=d;
			return;
		}

		int minCost(int _N, vector <string> edges, int _height)
		{
			N=_N;
			height=_height;
			memset(tree,false,sizeof(tree));
			for(int i=0;i<(int)edges.size();i++)
			{
				stringstream ss(edges[i]);
				int p,c;
				ss >> p >> c;
				cout << "p=" << p << " c=" << c << endl;
				tree[p][c]=true;
			}
			DFS(0,0);
		}
};

