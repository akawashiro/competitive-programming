#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class RoughStrings
{
	public:

		map<vector<int>,int> cache;

		int rec(vector<int> v,int n)
		{
			v.erase(remove(v.begin(),v.end(),0),v.end());
			sort(v.begin(),v.end());

			if(cache.find(v)!=cache.end())
				return cache[v];
			if(n==0)
				return cache[v]=v[v.size()-1]-v[0];

			int r=(v[v.size()-1]-v[0]);
			v[0]--;
			r=min(r,rec(v,n-1));
			v[0]++;

			v[v.size()-1]--;
			r=min(r,rec(v,n-1));
			v[v.size()-1]++;

			return cache[v]=r;
		}

		int minRoughness(string s, int n)
		{
			vector<int> v(26,0);
			for(int i=0;i<s.size();i++)
				v[s[i]-'a']++;
			return rec(v,n);
		}
};

