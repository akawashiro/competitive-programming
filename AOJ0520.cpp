#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

struct BRANCH{LL l1;LL l2;LL w1;LL w2;};

int n;
vector<LL> cahce;
vector<BRANCH> branch;

LL gcd(const LL a,const LL b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

LL rec(int index)
{
	if(cahce[index]!=-1)
		return cahce[index];

	LL l1=branch[index].l1;
	LL l2=branch[index].l2;
	LL w1=branch[index].w1;
	LL w2=branch[index].w2;

	if(w1!=0)
		w1=rec(w1-1);
	if(w2!=0)
		w2=rec(w2-1);

	if(w1==0 && w2==0)
	{
		branch[index].w1=l1;
		branch[index].w2=l2;
		return cahce[index]=l1+l2;
	}
	if(w1!=0 && w2==0)
	{
		LL w11=l1*w1/gcd(w1,l1);
		LL w22=w11*l2/l1;

		branch[index].w1=w11;
		branch[index].w2=w22;
		return cahce[index]=w11+w22;
	}
	if(w1==0 && w2!=0)
	{
		LL w22=l2*w2/gcd(w2,l2);
		LL w11=w22*l1/l2;

		branch[index].w1=w11;
		branch[index].w2=w22;
		return cahce[index]=w11+w22;
	}
	if(w1!=0 && w2!=0)
	{
		LL w11=w1*l1*w2/gcd(w1*l2,w2*l1);
		LL w22=w1*l2*w2/gcd(w1*l2,w2*l1);

		branch[index].w1=w11;
		branch[index].w2=w22;
		return cahce[index]=w11+w22;
	}
}

void solve()
{
	cahce.clear();
	cahce=vector<LL>(n,-1);
	branch.clear();
	branch=vector<BRANCH>(n);

	for(int i=0;i<n;i++)
	{
		int p,q,r,b;
		cin >> p >> q >> r >> b;

		//printf("p=%d q=%d r=%d b=%d\n",p,q,r,b);

		branch[i].l1=q/gcd(p,q);
		branch[i].l2=p/gcd(p,q);
		branch[i].w1=r;
		branch[i].w2=b;
	}

	LL ans=0;
	for(int i=0;i<n;i++)
	{
		//printf("l1=%d l2=%d w1=%d w2=%d\n",branch[i].l1,branch[i].l2
		//		,branch[i].w1,branch[i].w2);
		ans=max(ans,rec(i));
	}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		solve();
	}
	return 0;
}

				
