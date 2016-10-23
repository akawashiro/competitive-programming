#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	vector<pair<int,int> > vi;
	vector<int> v;
	while(1){
		int a,b;
		scanf("%d,%d",&a,&b);
		if(!a&&!b)
			break;
		vi.push_back(make_pair(b,a));
	}
	sort(vi.begin(),vi.end());
	reverse(vi.begin(),vi.end());

	int r=1,n=vi.size();
	for(int i=0;i<n;i++){
		if(0<i && vi[i-1].first>vi[i].first)
			r++;
		v.push_back(r);
	}
	while(1){
		int a;
		if(scanf("%d",&a)==EOF)
			break;
		int i;
		for(i=0;i<n;i++)
			if(vi[i].second==a)
				break;
		printf("%d\n",v[i]);
	}
	return 0;
}

