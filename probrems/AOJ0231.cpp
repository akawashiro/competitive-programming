//AOJ0231
#include <vector>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	while(1){
		int n;
		vector<pair<int,int> > vp;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int m,a,b;
			scanf("%d%d%d",&m,&a,&b);
			vp.push_back(make_pair(a,m));
			vp.push_back(make_pair(b,-m));
		}
		sort(vp.begin(),vp.end());
		int f=1,t=0;
		for(int i=0;i<2*n;i++){
			t+=vp[i].second;
			if(150<t)
				f=0;
		}
		if(f)
			printf("OK\n");
		else
			printf("NG\n");
	}
	return 0;
}

