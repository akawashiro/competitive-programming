#include <cstring>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;

class IngredientProportions
{
	public:

		int n;
		int propotion[10][10];
		vector<LL> pre;

		LL gcd(LL x,LL y)
		{
			if(y==0)
				return x;
			else
				return gcd(y,x%y);
		}

		void DFS(int s)
		{
			for(int i=0;i<n;i++)
				if(pre[i]==-1 && propotion[s][i]!=-1)
				{
					pre[i]=pre[s]/propotion[s][i]*propotion[i][s];
					DFS(i);
				}
		}

		vector <int> getMasses(vector<string> input)
		{
			n=0;
			memset(propotion,-1,sizeof(propotion));
			pre=vector<LL>(10,-1);

			LL m=1;

			for(int i=0;i<(int)input.size();i++)
			{
				int a,b,p,q;
				a=input[i][1]-'0';
				b=input[i][8]-'0';
				p=input[i][13]-'0';
				q=input[i][15]-'0';
				n=max(n,max(a+1,b+1));
				m*=(p*q/gcd(p,q)/gcd(p,q));
				propotion[a][b]=p/gcd(p,q);
				propotion[b][a]=q/gcd(p,q);
			}

			pre[0]=m;
			DFS(0);

			LL g=m;
			for(int i=0;i<n;i++)
				g=gcd(g,pre[i]);

			vector<int> ans(n);
			for(int i=0;i<n;i++)
				ans[i]=pre[i]/g;

			return ans;
		}
};

