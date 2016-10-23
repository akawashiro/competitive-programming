#include <queue>
#include <stdio.h>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
int main(){
	int n;
	map<int,int> ma;
	priority_queue<P> que;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		ma[a]++;
	}
	for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
		que.push(make_pair((*it).second,(*it).first));
	vector<vector<int> > ans;
	while(2<que.size()){
		pair<int,int> p,q,r;
		p=que.top();que.pop();
		q=que.top();que.pop();
		r=que.top();que.pop();
		vector<int> v(3);
		v[0]=p.second,v[1]=q.second,v[2]=r.second;
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		ans.push_back(v);
		if(1<p.first)	que.push(make_pair(p.first-1,p.second));
		if(1<r.first)	que.push(make_pair(r.first-1,r.second));
		if(1<q.first)	que.push(make_pair(q.first-1,q.second));
	}
	printf("%d\n",ans.size());
	for(int i=0;i<(int)ans.size();i++)
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}

