#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class ParallelProgramming
{
	public:

		vector<string> depend;
		vector<int> time;
		int n;

		vector<bool> isAdded;
		vector<int> OK;

		bool check(int index)
		{
			if(OK[index]!=-1)
				return OK[index]==1;
				
			if(isAdded[index])
			{
				OK[index]=0;
				return false;
			}
			isAdded[index]=true;
			
			for(int i=0;i<n;i++)
				if(depend[index][i]=='Y')
					if(!check(i))
					{
						OK[index]=0;
						return false;
					}
						
			isAdded[index]=false;
			
			OK[index]=1;
			return true;
		}

		vector<int> cache;

		int cost(int index)
		{
			if(cache[index]!=-1)
				return cache[index];

			int r=0;
			for(int i=0;i<n;i++)
				if(depend[index][i]=='Y')
					r=max(r,cost(i));
			return cache[index]=r+time[index];
		}

		int minTime(vector <int> _time, vector <string> prec)
		{
			n=prec.size();
			time=_time;

			for(int i=0;i<n;i++)
			{
				string s;
				for(int j=0;j<n;j++)
					s+=prec[j][i];
				depend.push_back(s);
			}

			OK=vector<int>(n,-1);
			for(int i=0;i<n;i++)
			{
				isAdded=vector<bool>(n,false);
				if(!check(i))
					return -1;
			}
			
			cache=vector<int>(n,-1);
			int ans=0;
			for(int i=0;i<n;i++)
				ans=max(ans,cost(i));
			return ans;
		}
};

