#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

class UNIONFIND
{
	public:
		vector<int> data;

		UNIONFIND(int size)
		{
			for(int i=0;i<size;i++)
				data.push_back(i);
		}

		int root(int a)
		{
			if(data[a]==a)
				return data[a];
			else
				return data[a]=root(data[a]);
		}

		void set(int a,int b)
		{
			if(root(a)!=root(b))
				data[root(a)]=data[root(b)];
		}
};

class BRANCH
{
	public:
		int left,right,cost;
		string id;

		bool operator<(const BRANCH &b) const
		{
			if(cost!=b.cost)
				return (cost>b.cost);
			else
				return (id>b.id);
		}
};

class RoadReconstruction
{
	public:
		set<string> cities;
		int s2i(string s)
		{
			return (int)distance(cities.begin(),cities.find(s));
		}

		string selectReconstruction(vector<string> roads)
		{
			for(int i=0;i<roads.size();i++)
			{
				stringstream ss(roads[i]);
				string id,c1,c2;
				ss >> id >> c1 >> c2;

				cities.insert(c1);
				cities.insert(c2);
			}

			int n=cities.size();
			UNIONFIND uni(n);
			priority_queue<BRANCH> que;

			for(int i=0;i<roads.size();i++)
			{
				stringstream ss(roads[i]);
				string id,c1,c2;
				ss >> id >> c1 >> c2;

				int c;
				if(ss >> c)
				{
					BRANCH b;
					b.left=s2i(c1),b.right=s2i(c2),b.cost=c,b.id=id;
					que.push(b);
				}
				else
				{
					uni.set(s2i(c1),s2i(c2));
				}
			}

			vector<string> vs;
			while(!que.empty())
			{
				BRANCH b=que.top();
				que.pop();
				if(uni.root(b.left)!=uni.root(b.right))
				{
					vs.push_back(b.id);
					uni.set(b.left,b.right);
				}
			}

			int chech=uni.root(0);
			for(int i=0;i<n;i++)
				if(uni.root(i)!=chech)
					return "IMPOSSIBLE";

			sort(vs.begin(),vs.end());
			string ans;
			for(int i=0;i<vs.size();i++)
			{
				if(i!=0)
					ans+=" ";
				ans+=vs[i];
			}

			return ans;
		}
};

