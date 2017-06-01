#include <cstring>
#include <string>

using namespace std;

class PalindromeFactory
{
	public:

		string source[50][50];
		int cache[50][50][50][50];

		int rec(int s1,int s2,int f,int e)
		{
			int &r=cache[s1][s2][f][e];
			string s=source[s1][s2];

			if(r!=-1)
				;
			else if(e<=f)
				r=0;
			else if(s[f]==s[e])
				r=rec(s1,s2,f+1,e-1);
			else
			{
				int a=1+rec(s1,s2,f,e-1);
				int b=1+rec(s1,s2,f+1,e);
				int c=1+rec(s1,s2,f+1,e-1);
				r=min(a,min(b,c));
			}

			return r;
		}

		int getEditDistance(string initial)
		{
			int n=initial.size();
			int ans=50;
			memeset(cache,-1,sizeof(cache));
			source[0][0]=initial;
			ans=min(ans,rec(0,0,0,n-1));
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
				{
					source[i][j]=initial;
					swap(source[i][j][i],source[i][j][j]);
					ans=min(ans,rec(i,j,0,n-1));
				}

			return ans;
		}
};

