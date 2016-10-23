//AOJ0161
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		vector<pair<int,int> > vp;
		for(int i=0;i<n;i++){
			int c,m1,s1,m2,s2,m3,s3,m4,s4;
			scanf("%d%d%d%d%d%d%d%d%d",&c,&m1,&s1,&m2,&s2,&m3,&s3,&m4,&s4);
			vp.push_back(make_pair((m1+m2+m3+m4)*60+s1+s2+s3+s4,c));
		}
		sort(vp.begin(),vp.end());
		printf("%d\n%d\n%d\n",vp[0].second,vp[1].second,vp[n-2].second);
	}
	return 0;
}

