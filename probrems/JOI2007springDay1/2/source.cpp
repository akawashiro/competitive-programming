#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

vector<pair<int,int> > primeFactor(int num) //first->prime,second->pow
{
	if(num==1)
	{
		vector<pair<int,int> > r;
		r.push_back(make_pair(1,1));
		return r;
	}
	else
	{
		vector<pair<int,int> > r;
		for(int i=2;i*i<=num;i++)
		{
			if(num%i==0)
			{
				int p=0;
				while(num%i==0)
					num/=i,p++;
				r.push_back(make_pair(i,p));
			}
		}
		if(num!=1)
			r.push_back(make_pair(num,1));
		return r;
	}
}

int rPow(int num,int p)
{
	int r=0;
	while(num%p==0)
		num/=p,r++;
	return r;
}

int main()
{
	int n,ans=0;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	vector<pair<int,int> > prime=primeFactor(n);
	for(int i=0;i<prime.size();i++)
	{
		int t=0;
		while(0<prime[i].second)
		{
			t+=prime[i].first;
			prime[i].second-=rPow(t,prime[i].first);
		}
		ans=max(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}

