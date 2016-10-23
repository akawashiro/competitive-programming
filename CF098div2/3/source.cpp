#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	int n;
	vector<pair<int,int> > vp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		vp.push_back(make_pair(a,b));
	}
	sort(vp.begin(),vp.end());
	int e=-1,ans=0;
	for(int i=0;i<n;i++){
		if(vp[i].second<e)
			ans++;
		e=max(e,vp[i].second);
	}
	printf("%d\n",ans);
	return 0;
}

