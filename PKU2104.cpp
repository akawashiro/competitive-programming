#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int input[100000+10];
vector<int> dat[(1<<18)-1];

void init(int k,int l,int r)
{
	if(r-l==1)
		dat[k].push_back(input[l]);
	else
	{
		int lch=k*2+1,rch=k*2+2;
		init(lch,l,(l+r)/2);
		init(rch,(l+r)/2,r);
		dat[k].resize(r-l);
		merge(dat[lch].begin(),dat[lch].end(),dat[rch].begin(),dat[rch].end(),dat[k].begin());
	}
}

int check(int a,int b,int x,int k,int l,int r)
{
	if(b<=l || r<=a)
		return 0;
	else if(a<=l && r<=b)
		return upper_bound(dat[k].begin(),dat[k].end(),x)-dat[k].begin();
	else
	{
		int res=0;
		res+=check(a,b,x,k*2+1,l,(l+r)/2);
		res+=check(a,b,x,k*2+2,(l+r)/2,r);
		return res;
	}
}

int main()
{
	int Q;
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",input+i);
	init(0,0,N);
	sort(input,input+N);
	for(int i=0;i<Q;i++)
	{
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		a--;
		int ce=N-1,bo=-1;
		while(ce-bo>1)
		{
			int m=(ce+bo)/2;
			int r=check(a,b,input[m],0,0,N);
			if(k<=r)
				ce=m;
			else
				bo=m;
		}
		printf("%d\n",input[ce]);
	}
	return 0;
}
