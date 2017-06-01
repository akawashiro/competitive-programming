//AOJ1169
#include <string.h>
#include <stdio.h>
#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 45
using namespace std;
struct Edge{
	int to;
	string lab;
};
Edge makeE(int t,string s){
	Edge e={t,s};
	return e;
};
bool operator < (const Edge &e,const Edge &f){
	if(e.lab==f.lab)
		return e.to<f.to;
	else
		return e.lab<=f.lab;
}
int wf[MAX_V][MAX_V];
vector<Edge> graph[MAX_V];
int main(){
	while(1){
		memset(wf,0,sizeof(wf));
		for(int i=0;i<MAX_V;i++)
			graph[i].clear();
		int N,A,S,G;
		cin>>N>>A>>S>>G;
		if(N==0&&A==0&&S==0&&G==0)	break;
		for(int i=0;i<A;i++){
			int a,b;
			string s;
			cin>>a>>b>>s;
			graph[a].push_back(makeE(b,s));
			wf[a][b]=1;
		}
		for(int k=0;k<N;k++){
			wf[k][k]=1;
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					if(wf[i][k]&&wf[k][j])
						wf[i][j]=1;
		}
		if(!wf[S][G]){
			cout<<"NO"<<endl;
			continue;
		}
		set<Edge> se;
		se.insert(makeE(S,""));
		while(1){
			Edge e=*(se.begin());
			se.erase(se.begin());
			if(e.to==G){
				cout<<e.lab<<endl;
				break;
			}
			if(6*N<=(int)e.lab.size()){
				cout<<"NO"<<endl;
				break;
			}
			for(int i=0;i<(int)graph[e.to].size();i++)
				if(wf[graph[e.to][i].to][G])
					se.insert(makeE(graph[e.to][i].to,e.lab+graph[e.to][i].lab));
		}
	}
	return 0;
}

