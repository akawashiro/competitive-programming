#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int,int> > vp;
	for(int i=0;i<n;i++)
		vp.push_back(make_pair(0,i));
	for(int i=0;i<n*(n-1)/2;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--,b--;
		if(c<d)	vp[b].first+=3;
		if(c==d)	vp[a].first++,vp[b].first++;
		if(c>d)	vp[a].first+=3;
	}
	sort(vp.begin(),vp.end());
	reverse(vp.begin(),vp.end());
	vector<int> ans(n);
	int p=1;
	for(int i=0;i<n;i++){
		if(0<i&&vp[i-1].first!=vp[i].first)
			p=i+1;
		ans[vp[i].second]=p;
	}
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);
	return 0;
}

