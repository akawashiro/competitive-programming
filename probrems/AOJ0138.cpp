//AOJ0138
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<pair<double,int> > ans;
	vector<pair<double,int> > tmp;
	for(int i=0;i<3;i++){
		vector<pair<double,int> > v;
		for(int j=0;j<8;j++){
			double d;
			int a;
			scanf("%d%lf",&a,&d);
			v.push_back(make_pair(d,a));
		}
		sort(v.begin(),v.end());
		ans.push_back(v[0]);
		ans.push_back(v[1]);
		for(int j=2;j<8;j++)
			tmp.push_back(v[j]);
	}
	sort(tmp.begin(),tmp.end());
	ans.push_back(tmp[0]);
	ans.push_back(tmp[1]);
	for(int i=0;i<8;i++)
		printf("%d %.2lf\n",ans[i].second,ans[i].first);
	return 0;
}

