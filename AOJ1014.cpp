//AOJ1014
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <functional>
#define INF 1000000
#define P pair<int,int>
#define MP make_pair
using namespace std;
int main(){
	while(1){
		int s,c,ans=0;
		scanf("%d%d",&s,&c);
		if(!s&&!c)	break;
		vector<vector<int> > sp(s,vector<int>(c,INF));
		vector<vector<int> > ci(c,vector<int>(c,INF));
		vector<int> di(c,INF);
		priority_queue<P,vector<P>,greater<P> > que;
		for(int i=0;i<s;i++)
			for(int j=0;j<c;j++){
				scanf("%d",&sp[i][j]);
				if(sp[i][j]==0)
					sp[i][j]=INF;
				que.push(MP(sp[i][j],j));
			}
		for(int i=0;i<c-1;i++)
			for(int j=1;j<c-i;j++){
				int a;
				scanf("%d",&a);
				if(a==0)
					a=INF;
				ci[i][i+j]=ci[i+j][i]=a;
			}
		while(!que.empty()){
			int d=que.top().first;
			int v=que.top().second;
			que.pop();
			if(di[v]!=INF)	continue;
			di[v]=d;
			ans+=d;
			for(int i=0;i<c;i++)
				que.push(MP(ci[v][i],i));
		}
		printf("%d\n",ans);
	}
	return 0;
}

