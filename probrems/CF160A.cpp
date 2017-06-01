#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,s=0,t=0;
	vector<int> vi;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		t+=a;
		vi.push_back(a);
	}
	sort(vi.begin(),vi.end());
	reverse(vi.begin(),vi.end());
	int ans=0;
	for(ans=0;s<=t&&ans<n;ans++)
		s+=vi[ans],t-=vi[ans];
	printf("%d\n",ans);
	return 0;
}


