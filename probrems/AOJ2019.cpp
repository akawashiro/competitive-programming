#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N,M;

void solve()
{
	vector<pair<int,int> > load(N);
	for(int i=0;i<N;i++)
		cin >> load[i].second >> load[i].first;
	sort(load.begin(),load.end());
	reverse(load.begin(),load.end());

	int ans=0;
	for(int i=0;i<N;i++)
	{
		int d=load[i].second,p=load[i].first;
		
		if(0<=M-d)
		{
			M-=d;
		}
		else if(0<M && M-d<0)
		{
			ans+=(d-M)*p;
			M-=d;
		}
		else
		{
			ans+=d*p;
		}
	}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> N >> M;
		if(N==0 && M==0)
			break;
		solve();
	}
	return 0;
}

