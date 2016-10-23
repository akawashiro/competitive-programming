#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		vector<vector<LL> > coffee;
		LL n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			vector<LL> v(3);
			cin>>v[0]>>v[1]>>v[2];
			coffee.push_back(v);
		}
		LL day=1,sum=0;
		for(day=1;day<=k;day++){
			int maxI=-1,maxS=-1;
			for(int i=0;i<n;i++)
				if(maxS<coffee[i][2] && 0<coffee[i][0] && day<=coffee[i][1]){
					maxS=coffee[i][2];
					maxI=i;
				}
			if(maxI==-1)
				break;
			coffee[maxI][0]--;
			sum+=coffee[maxI][2];
		}
		cout<<"Case #"<<t<<": "<<sum<<endl;
	}
	return 0;
}


