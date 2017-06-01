#include <vector>
using namespace std;

#define MAXN 12

int n,k,color[MAXN];
bool edge[MAXN][MAXN];

bool solve(int num)
{
	if(n==num)
	{
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(edge[i][j] && color[i]==color[j])
					return false;
		return true;
	}

	for(int i=0;i<k;i++)
	{
		color[num]=i;
		if(solve(num+1))
			return true;
	}
	return false;
}

class BunnyExam
{
	public:
		double getExpected(int m,int _k,vector<int> linkage)
		{
			k=_k;
			n=linkage.size()/2;

			for(int i=0;i<n;i++)
				if(abs(linkage[2*i]-linkage[2*i+1])==1)
					return -1;

			if(k==1)
				return m==1 ? 1 : -1;
			if(k==2)
				for(int i=0;i<n;i++)
					if(linkage[i*2]%2 != linkage[i*2+1]%2)
						return -1;
			if(k<=4)
			{
				for(int i=0;i<n;i++)
					for(int j=i+1;j<n;j++)
					{
						int a=linkage[i*2],b=linkage[i*2+1];
						int c=linkage[j*2],d=linkage[j*2+1];
						edge[i][j]=edge[j][i]= abs(a-c)==1 
							|| abs(a-d)==1 || abs(b-c)==1 || abs(b-d)==1;
					}
				if(!solve(0))
					return -1;
			}

			return (double)m/k;
		}
};


