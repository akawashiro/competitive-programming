//AOJ1016
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N,V,d;
	N=1001;
	while(scanf("%d%d",&V,&d)!=EOF){
		vector<int> v;
		int a=1,b=1;
		for(int i=0;i<V;i++){
			v.push_back((a+b)%N);
			int c=(a+b)%N;
			a=b,b=c;
		}
		sort(v.begin(),v.end());
		int ans=1;
		for(int i=0;i<V-1;i++)
			if(d<=v[i+1]-v[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}

