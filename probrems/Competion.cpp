//CF103div2Competition
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct Node{int x,y,id;};
bool operator< (const Node &s,const Node &t){
	if(s.x!=t.x)	return s.x<t.x;
	else			return s.y<t.y;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<Node> vn;
	vector<int> ans;
	set<int> se;
	for(int i=0;i<m;i++){
		Node no;
		scanf("%d%d",&(no.x),&(no.y));
		no.id=i+1;
		vn.push_back(no);
	}
	sort(vn.begin(),vn.end());
	for(int i=0;i<n;i++)se.insert(i);
	for(int i=0;i<m;i++){
		set<int>::iterator it=se.lower_bound(n-vn[i].y);
		if(it==se.end())	continue;
		if(*it<vn[i].x){
			se.erase(it);
			ans.push_back(vn[i].id);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

