//this is copy
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

class TheSwap
{
	public:
	
		map<pair<int,int>,int> memo;
	
		int value_of(vector<int> n)
		{
			int r=0;
			for(int i=0;i<n.size();i++)
			{
				r*=10;
				r+=n[i];
			}
			return r;
		}
		
		int rec(vector<int> num,int k)
		{
			int n=value_of(num);
			if(k==0)
				return n;
			if(memo.find(make_pair(n,k))!=memo.end())
				return memo[make_pair(n,k)];
			int r=-1;
			for(int i=0;i<num.size();i++)
				for(int j=i+1;j<num.size();j++)
				{
					if(i==0 && num[j]==0)
						continue;
					swap(num[i],num[j]);
					r=max(r,rec(num,k-1));
					swap(num[i],num[j]);
				}
			return memo[make_pair(n,k)]=r;
		}
		
		int findMax(int n,int k)
		{
			vector<int> num;
			while(n!=0)
			{
				num.push_back(n%10);
				n/=10;
			}
			reverse(num.begin(),num.end());
			return rec(num,k);
		}
};
