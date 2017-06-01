//AOJ2069
#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
int coin[50];
int dist[50000];
int main(){
	for(int T=1;;T++){
		int n;
		scanf("%d",&n);
		if(!n)	break;
		for(int i=0;i<n;i++)	scanf("%d",coin+i);
		if(coin[0]!=1){
			printf("Case #%d: Cannot pay some amount\n",T);
		}else{
			for(int i=0;i<50000;i++)
				dist[i]=50000;
			dist[0]=0;
			queue<pair<int,int> > que;
			que.push(make_pair(0,0));
			while(!que.empty()){
				int d=que.front().first;
				int p=que.front().second;
				que.pop();
				if(dist[p]<d)	continue;
				for(int i=0;i<n;i++){
					int dd=d+1,pp=p+coin[i];
					if(pp<50000&&dd<dist[pp]){
						dist[pp]=dd;
						que.push(make_pair(dd,pp));
					}
				}
			}
			int b=1;
			for(int i=0;i<50000;i++){
				int p=i,d=0;
				for(int j=n-1;0<=j;j--){
					d+=p/coin[j];
					p%=coin[j];
				}
				if(dist[i]!=d){
					b=0;
				}
			}
			if(b)
				printf("Case #%d: OK\n",T);
			else
				printf("Case #%d: Cannot use greedy algorithm\n",T);
		}
	}
	return 0;
}

