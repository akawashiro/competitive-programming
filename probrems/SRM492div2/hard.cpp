#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

typedef long long LL;
using namespace std;

class EDGE
{
	public:
		LL cost;
		int left,right;
		bool operator< (const EDGE &e)
			const{
				return cost>e.cost;
			}
};

class UNIONFIND
{
	public:
		vector<int> data;
		UNIONFIND(int size)
		{
			for(int i=0;i<size;i++)
				data.push_back(i);
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
			if(root(a)!=root(b))
				data[root(b)]=data[root(a)];
		}
};

class TimeTravellingSalesman
{
	public:
		LL determineCost(int N, vector <string> roads)
		{
			UNIONFIND unionFind(N);
			priority_queue<EDGE> que;

			string input;
			stringstream ss;
			EDGE e;
			for(int i=0;i<(int)roads.size();i++)
				input+=roads[i];
			ss.str(input);
			while(ss >> input)
			{
				sscanf(input.c_str(),"%d,%d,%lld",&(e.left),&(e.right),&(e.cost));
				//printf("l=%d r=%d c=%lld\n",e.left,e.right,e.cost);
				que.push(e);
			}

			LL ans=0;
			while(!que.empty())
			{
				int l,r;
				LL c;
				l=que.top().left,r=que.top().right,c=que.top().cost;
				que.pop();
				
				if(unionFind.root(l)!=unionFind.root(r))
				{
					ans+=c;
					unionFind.set(l,r);
				}
			}

			int ro=unionFind.root(0);
			for(int i=0;i<N;i++)
				if(unionFind.root(i)!=ro)
					ans=-1;

			return ans;
		}
};

