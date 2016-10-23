//AOJ2332
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#define MAX_N 100000
using namespace std;
typedef pair<int,int> P;
int n;
int p[MAX_N],serched[MAX_N],ng[MAX_N],dist[MAX_N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",p+i);
	for(int i=0;i<n;i++)
		if(serched[i]==0){
			int cr=i;
			vector<int> v;
			while(serched[cr]==0){
				serched[cr]=2;
				v.push_back(cr);
				cr+=p[cr];
			}
			int NG=((p[cr]!=0&&serched[cr]==2)||ng[cr]);
			for(int j=0;j<(int)v.size();j++){
				if(NG)
					ng[v[j]]=1;
				serched[v[j]]=1;
			}
		}
	for(int i=0;i<n;i++)
		dist[i]=MAX_N;
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(make_pair(0,0));
	while(!que.empty()){
		int d=que.top().first;
		int k=que.top().second;
		que.pop();
		if(dist[k]<=d||ng[k])	continue;
		dist[k]=d;
		if(p[k]!=0){
			que.push(make_pair(d,k+p[k]));
		}else{
			for(int i=1;i<=6;i++)
				que.push(make_pair(d+1,min(n-1,k+i)));
		}
	}
	printf("%d\n",dist[n-1]);
	return 0;
}


















