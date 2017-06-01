//AOJ0159
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
double Abs(double d){	return (0<d)?d:-d;	}
using namespace std;
int main(){
	while(1){
		int n;
		vector<pair<double,int> > vp;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int j;
			double h,w;
			scanf("%d%lf%lf",&j,&h,&w);
			h/=100;
			vp.push_back(make_pair(Abs(22-w/h/h),j));
		}
		sort(vp.begin(),vp.end());
		printf("%d\n",vp[0].second);
	}
	return 0;
}

