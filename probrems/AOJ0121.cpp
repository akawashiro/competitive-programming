//AOJ0121
#include <map>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;
int main(){
	vector<int> vi(8);
	for(int i=0;i<8;i++)
		vi[i]=i;
	map<vector<int>,int> ma;
	queue<pair<vector<int>,int> > que;
	que.push(make_pair(vi,0));
	ma[vi]=0;
	while(!que.empty()){
		vi=que.front().first;
		int d=que.front().second;
		que.pop();
		int p;
		for(p=0;p<8;p++)
			if(vi[p]==0)
				break;
		if(p!=0&&p!=4){
			vector<int> v=vi;
			swap(v[p],v[p-1]);
			if(ma.find(v)==ma.end()){
				que.push(make_pair(v,d+1));
				ma[v]=d+1;
			}
		}
		if(p<4){
			vector<int> v=vi;
			swap(v[p],v[p+4]);
			if(ma.find(v)==ma.end()){
				que.push(make_pair(v,d+1));
				ma[v]=d+1;
			}
		}
		if(4<=p){
			vector<int> v=vi;
			swap(v[p],v[p-4]);
			if(ma.find(v)==ma.end()){
				que.push(make_pair(v,d+1));
				ma[v]=d+1;
			}
		}
		if(p!=3&&p!=7){
			vector<int> v=vi;
			swap(v[p],v[p+1]);
			if(ma.find(v)==ma.end()){
				que.push(make_pair(v,d+1));
				ma[v]=d+1;
			}
		}
	}
	while(1){
		for(int i=0;i<8;i++)
			if(scanf("%d",&vi[i])==EOF)
				return 0;
		printf("%d\n",ma[vi]);
	}
	return 0;
}

