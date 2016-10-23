#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n,A,B,C;
	vector<int> D;
	scanf("%d%d%d%d",&n,&A,&B,&C);
	for(int i=0;i<n;i++){
		int d;
		scanf("%d",&d);
		D.push_back(d);
	}
	sort(D.begin(),D.end());
	reverse(D.begin(),D.end());
	int pr=A,cl=C,ans=cl/pr;
	for(int i=0;i<n;i++){
		pr+=B;
		cl+=D[i];
		ans=max(ans,cl/pr);
	}
	printf("%d\n",ans);
}

