#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	for(int t=1;t<=T;t++){
		vector<vector<LL> > coffee;
		int n;
		LL k;
		cin>>n>>k;
		//cout<<n<<" "<<k<<endl;
		for(int i=0;i<n;i++){
			vector<LL> v(3);
			cin>>v[0]>>v[1]>>v[2];
			coffee.push_back(v);
			//cout<<i<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n-1;j++)
				if(coffee[j][1]>coffee[j+1][1])
					swap(coffee[j],coffee[j+1]);
		LL day=1,sum=0;
		for(day=1;day<=k;day++){
			LL maxS=-1,maxI=-1;
			for(int i=0;i<n;i++)
				if(0<coffee[i][0] && day<=coffee[i][1] && maxS<coffee[i][2]){
					maxS=coffee[i][2];
					maxI=i;
				}
			if(maxI==-1)
				continue;
			coffee[maxI][0]--;
			sum+=coffee[maxI][2];
		}
		cout<<"Case #"<<t<<": "<<sum<<endl;
	}
	return 0;
}

