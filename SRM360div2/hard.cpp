#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int result[2][1000000+10];

class TakeSubstringGame
{
	public:
		vector<int> choice(int n)
		{
			vector<int> r;
			int num=n;
			while(num!=0)
			{
				int m=1;
				while(m<=num)
				{
					m*=10;
					int a=num%m;
					if(0<a && a<n)
						r.push_back(a);
				}
				num/=10;
			}
			return r;
		}

		int rec(int player,int num)
		{
			int &r=result[player][num];
			if(r!=2)
				return r;

			r=0;

			int opo=(player+1)%2;
			
			int n=num;
			while(n!=0)
			{
				int m=1;
				while(m<=n)
				{
					m*=10;
					int a=n%m;
					if(0<a && a<num && rec(opo,num-a)==0)
					{
						r=1;
						break;
					}
				}
				n/=10;
			}
			return r;
		}

		int winningMove(int n)
		{
			for(int i=0;i<2;i++)
				for(int j=0;j<=1000000;j++)
					result[i][j]=2;

			rec(0,n);


			vector<int> v=choice(n);
			sort(v.begin(),v.end());
			for(int i=0;i<(int)v.size();i++)
				if(result[1][n-v[i]]==0)
					return v[i];

			return -1;
		}
};

