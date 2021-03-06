#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		vector<vector<LL> > coffee;
		int n;
		LL k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			vector<LL> v(3);
			cin>>v[0]>>v[1]>>v[2];
			coffee.push_back(v);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n-1;j++)
				if(coffee[j][1]>coffee[j+1][1])
					swap(coffee[j],coffee[j+1]);
		LL day=1,sum=0;
		while(1){
			LL maxS=-1,maxI=-1;
			for(int i=0;i<n;i++)
				if(day<=coffee[i][1] && maxS<coffee[i][2]){
					maxS=coffee[i][2];
					maxI=i;
				}
			if(maxI==-1)
				break;
			LL d=min(min(k+1-day,coffee[maxI][1]+1-day),coffee[maxI][0]);
			sum+=d*maxS;
			day+=d;
			coffee[maxI][2]=-1;
			if(day==k+1)
				break;
		}
		cout<<"Case #"<<t<<": "<<sum<<endl;
	}
	return 0;
}

