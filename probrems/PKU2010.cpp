#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int C,N,F;
vector<pair<int,int> > calf;

int check(int k)
{
	//lower.clear();
	//upper.clear();
	vector<int> lower,upper;
	for(int i=0;i<k;i++)
		lower.push_back(calf[i].second);
	for(int i=k+1;i<C;i++)
		upper.push_back(calf[i].second);
	if(lower.size()<(N/2) || upper.size()<(N/2))
		return 0;
	int m=calf[k].second;
	sort(lower.begin(),lower.end());
	sort(upper.begin(),upper.end());
	for(int i=0;i<(N/2);i++)
		m+=(lower[i]+upper[i]);
	return (m<=F);
}

int main()
{
	scanf("%d%d%d",&N,&C,&F);
	for(int i=0;i<C;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		calf.push_back(make_pair(a,b));
	}
	sort(calf.begin(),calf.end());

	int c=C-1,b=0;
	while(1<c-b)
	{
		int m=(c+b)/2;
		if(check(m))
			b=m;
		else
			c=m;
	}
	if(check(c))
		cout<<calf[c].first<<endl;
	else if(check(b))
		cout<<calf[b].first<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}

