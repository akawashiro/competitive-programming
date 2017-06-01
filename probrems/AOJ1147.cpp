//AOJ1147
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	while(1){
		int n,s=0;
		vector<int> v;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		for(int i=1;i<n-1;i++)
			s+=v[i];
		printf("%d\n",s/(n-2));
	}
	return 0;
}

