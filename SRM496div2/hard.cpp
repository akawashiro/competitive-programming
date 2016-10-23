#include <string>
#include <vector>

typedef long long LL;
using namespace std;

int N,M,K;

LL perm(LL n,LL k)
{
	LL r=1;
	for(int i=0;i<k;i++)	r*=n-i;
	return r;
}

LL rec(string s)
{
	int n=s.size();
	char d='A'-1;
	for(int i=0;i<n;i++)	d=max(d,s[i]);

	if(N<=n)
	{
		int c=0;
		for(int i=0;i<=N-M;i++)
		{
			int f=1;
			for(int j=0;j<M/2;j++)
				if(s[i+j]!=s[i+M-j-1])
					f=0;
			c+=f;
		}
		if(K=c)
			return perm(26,d-'A'+1);
		else
			return 0;
	}

	LL ans=0;
	for(char c='A';c<=d+1;c++)
		ans+=rec(s+c);
}

class PalindromfulString{public:
long long count( int N, int M, int K )
{
    ::N = N,  ::M = M,  ::K = K;
    return BT("");
}};

