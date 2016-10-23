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

int n,m,h,k;

void solve()
{
	int num[1010];
	for(int i=0;i<1010;i++)
		num[i]=i;

	int point[1010];
	for(int i=1;i<=n;i++)
		scanf("%d",point+i);

	vector<	pair<int,vector<int> > > beam;
	for(int i=0;i<m;i++)
	{
		beam.push_back(make_pair(0,vector<int>(5)));
		scanf("%d%d",&(beam[i].second[0]),&(beam[i].first));
	}

	sort(beam.begin(),beam.end());

	for(int i=0;i<m;i++)
	{
		int left=beam[i].second[0];
		int right=left+1;

		swap(num[left],num[right]);

		beam[i].second[1]=num[left];
		beam[i].second[2]=num[right];
	}

	int sum=0;
	for(int i=1;i<=n;i++)
		if(num[i]<=k)
			sum+=point[i];

	reverse(beam.begin(),beam.end());

	for(int i=0;i<m;i++)
	{
		int left=beam[i].second[0];
		int right=left+1;

		beam[i].second[3]=point[left];
		beam[i].second[4]=point[right];

		swap(point[left],point[right]);
	}

	int maxDec=0;
	for(int i=0;i<m;i++)
	{
		if(beam[i].second[1]<=k && k<beam[i].second[2])
			maxDec=max(maxDec,beam[i].second[3]-beam[i].second[4]);
		if(beam[i].second[2]<=k && k<beam[i].second[1])
			maxDec=max(maxDec,beam[i].second[4]-beam[i].second[3]);
	}


	printf("%d\n",sum-maxDec);
}

int main()
{
	while(1)
	{
		scanf("%d%d%d%d",&n,&m,&h,&k);
		if(n==0 && m==0 && h==0 && k==0)
			break;
		solve();
	}
	return 0;
}
