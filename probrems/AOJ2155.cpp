//AOJ2155
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define MP make_pair
#define FI first
#define SE second
using namespace std;
int main(){
	while(1){
		int n,m;
		scanf("%d%d",&n,&m);
		if(!n)	break;
		vector<int> co(n,0);
		vector<pair<int,pair<int,int> > > vpp;
		for(int i=0;i<m;i++){
			int t,s,d;
			scanf("%d%d%d",&t,&s,&d);
			s--,d--;
			vpp.push_back(MP(t,MP(s,d)));
		}
		sort(vpp.begin(),vpp.end());
		co[0]=1;
		for(int i=0;i<m;i++)
			if(co[vpp[i].SE.FI])
				co[vpp[i].SE.SE]=1;
		int ans=0;
		for(int i=0;i<n;i++)
			if(co[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}

