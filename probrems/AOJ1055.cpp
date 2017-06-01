//AOJ1055
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Edge{
	public:
		int to,cost;
		Edge(int t,int c){to=t;cost=c;}
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge> > Graph;
int main(){
	while(1){
		int n;
			scanf("%d",&n);
		if(!n)
			break;
		Graph G(n);
		vector<int> used(n,1);
		for(int i=0;i<2*n;i++){
			int b,c;
			scanf("%d%d",&b,&c);
			G[i/2].push_back(Edge(b,c));
		}
		int ans=1;
		for(int s=0;s<n;s++)
			if(used[s]){
				vector<int> e;
				int p,b;
				e.push_back(G[s][0].cost);
				p=G[s][0].to;
				b=s;
				used[s]=0;
				while(used[p]){
					for(int i=0;i<2;i++)
						if(G[p][i].to!=b){
							used[p]=0;
							e.push_back(G[p][i].cost);
							b=p;
							p=G[p][i].to;
							break;
						}	
				}
				sort(e.begin(),e.end());
				int m=0;
				for(int i=e.size()-1;0<=i&&e.back()==e[i];i--,m++);
				ans*=m;
				ans%=10007;
			}
		printf("%d\n",ans);
	}
	return 0;
}

