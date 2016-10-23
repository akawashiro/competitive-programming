#include <cstring>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

class PickGuitars
{
	public:

		vector<int> guiter;
		pair<int,int> cache[50][50][2];

		pair<int,int> rec(int f,int e,bool isPlayer)
		{
			pair<int,int> &r=cache[f][e][(isPlayer)?1:0];

			if(r.first!=-1)
				;
			else if(f==e)
				r.first=0,r.second=0;
			else
			{
				if(isPlayer)
				{
					r.first=-1;
					for(int i=f;i<e;i++)
					{
						pair<int,int> p,q;
						p=rec(f,i,false),q=rec(i+1,e,false);
						if(r.first<p.first+guiter[i]+q.first)
						{
							r.first=p.first+guiter[i]+q.first;
							r.second=p.second+q.second;
						}
					}
				}
				else
				{
					r.second=-1;
					for(int i=f;i<e;i++)
					{
						pair<int,int> p,q;
						p=rec(f,i,true),q=rec(i+1,e,true);
						if(r.second<p.second+guiter[i]+q.second)
						{
							r.second=p.second+guiter[i]+q.second;
							r.first=p.first+q.first;
						}
					}

				}
			}

			return r;
		}

		int maxValue(vector<int> guitarValues)
		{
			int n=guitarValues.size();
			int ans=0;
			for(int i=0;i<n;i++)
			{
				vector<int> v;
				for(int j=i+1;j<n;j++)
					v.push_back(guitarValues[j]);
				for(int j=0;j<i;j++)
					v.push_back(guitarValues[j]);
				guiter=v;
				memset(cache,-1,sizeof(cache));
				ans=max(ans,guitarValues[i]+rec(0,n-1,false).first);
			}

			return ans;
		}
};

