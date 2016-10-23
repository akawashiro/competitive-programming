#include <cstring>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class UNIONFIND
{
	vector<int> date;
	vector<int> scale;
	public:
	UNIONFIND(int n)
	{
		for(int i=0;i<n;i++)
		{
			date.push_back(i);
			scale.push_back(1);
		}
	}
	int root(int n)
	{
		if(date[n]==n)
			return n;
		else
			return date[n]=root(date[n]);
	}
	void unionSet(int x,int y)
	{
		if(root(x)==root(y))
			return;
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		date[root(x)]=date[root(y)];
	}
	int unionSize(int n)
	{
		return scale[root(n)];
	}
};

class CactusCount
{
	public:

		int visited[200];
		vector<int> edge[200];

		bool DFS(int pre,int now)
		{
			//printf("pre=%d now=%d\n",pre,now);
		
			visited[now]++;
			if(visited[now]==3)
				return false;
			if(visited[now]==2)
				return true;
			for(int i=0;i<(int)edge[now].size();i++)
				if(edge[now][i]!=pre && !DFS(now,edge[now][i]))
					return false;
			return true;
		}

		int countCacti(int n, vector <string> _edges)
		{
			UNIONFIND U(n);

			string input;
			for(int i=0;i<(int)_edges.size();i++)
				input+=_edges[i];
			for(int i=0;i<(int)input.size();i++)
				if(input[i]==',')
					input[i]=' ';
			stringstream ss(input);
			int cactus1,cactus2;
			while(ss >> cactus1 >> cactus2)
			{
				cactus1--,cactus2--;
				edge[cactus1].push_back(cactus2);
				edge[cactus2].push_back(cactus1);
				U.unionSet(cactus1,cactus2);
			}

			vector<int> OK(n,-2);
			for(int i=0;i<n;i++)
				if(OK[U.root(i)]==-2)
				{
					//printf("U.root(i)==%d\n",U.root(i));
					
					for(int j=0;j<n;j++)
						if(U.root(j)==U.root(i) && OK[U.root(i)]==-2)
						{
							memset(visited,0,sizeof(visited));
							if(!DFS(-1,j))
								OK[U.root(i)]=-1;
						}
					if(OK[U.root(i)]==-2)
						OK[U.root(i)]=0;
				}

			int ans=0;
			for(int i=0;i<n;i++)
				if(OK[i]==0)
					ans++;
			return ans;
		}
};
