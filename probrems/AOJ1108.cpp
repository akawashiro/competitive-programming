//AOJ1108
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
vector<int> to[11];
vector<int> dist[11];
vector<int> en[11];
pair<int,vector<int> > dfs(int k,int used){
	int len=0;
	vector<int> seq;
	for(int i=0;i<(int)to[k].size();i++)
		if(!(used&en[k][i])){
			pair<int,vector<int> > p=dfs(to[k][i],used|en[k][i]);
			p.first+=dist[k][i];
			if(len<p.first){
				len=p.first;
				seq=p.second;
			}
		}
	vector<int> v;
	v.push_back(k);
	for(int i=0;i<(int)seq.size();i++)	v.push_back(seq[i]);
	return make_pair(len,v);
}
int main(){
	while(1){
		int n,m;
		scanf("%d%d",&n,&m);
		if(!n)	break;
		for(int i=0;i<11;i++)	
			to[i].clear(),dist[i].clear(),en[i].clear();
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			to[a].push_back(b);dist[a].push_back(c);en[a].push_back(1<<i);
			to[b].push_back(a);dist[b].push_back(c);en[b].push_back(1<<i);
		}
		for(int i=0;i<11;i++)
			for(int j=0;j<(int)to[i].size()-1;j++)
				if(to[i][j]>to[i][j+1]){
					swap(to[i][j],to[i][j+1]);
					swap(dist[i][j],dist[i][j+1]);
					swap(en[i][j],en[i][j+1]);
				}
		pair<int,vector<int> > ans;
		ans.first=0;
		for(int i=1;i<=n;i++){
			pair<int,vector<int> > p=dfs(i,0);
			if(ans.first<p.first)
				ans=p;
		}
		printf("%d\n",ans.first);
		for(int i=0;i<(int)ans.second.size();i++){
			if(i!=0)
				printf(" ");
			printf("%d",ans.second[i]);
		}
		printf("\n");
	}
	return 0;
}

