//AOJ2283
#include <vector>
#include <stdio.h>
#include <queue>
#include <map>
#include <iostream>
#define INF (1<<28)
#define MAX_V 600
using namespace std;
struct Edge{
	int to,cost;
};
Edge makeE(int t,int c){	Edge e;e.to=t,e.cost=c;return e;	}
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
int n;
int dist[MAX_V];
vector<Edge> G[MAX_V];
int minDist(int start,int goal){
	for(int i=0;i<MAX_V;i++)	dist[i]=INF;
	priority_queue<Edge> que;
	que.push(makeE(start,0));
	while(!que.empty()){
		Edge e=que.top();
		que.pop();
		if(dist[e.to]<e.cost)	continue;
		for(int i=0;i<(int)G[e.to].size();i++)
			if(e.cost+G[e.to][i].cost<dist[G[e.to][i].to]){
				dist[G[e.to][i].to]=e.cost+G[e.to][i].cost;
				que.push(makeE(G[e.to][i].to,e.cost+G[e.to][i].cost));
			}
	}
	return dist[goal];
}
map<string,int> ma;
int conv(string s){
	if(ma.find(s)==ma.end())
		ma[s]=ma.size();
	return ma[s];
}
int main(){
	while(1){
		for(int i=0;i<MAX_V;i++)	G[i].clear();
		ma.clear();
		int m,s,p,g;
		string s1;
		cin>>n>>m;
		if(!n&&!m)	break;
		cin>>s1;s=conv(s1);
		cin>>s1;p=conv(s1);
		cin>>s1;g=conv(s1);
		for(int i=0;i<m;i++){
			int a,b,c,d;
			cin>>s1;a=conv(s1);
			cin>>s1;b=conv(s1);
			cin>>c>>d;
			c=c/40+d;
			G[a].push_back(makeE(b,c));
			G[b].push_back(makeE(a,c));
		}
		cout<<minDist(s,p)+minDist(p,g)<<endl;
	}
	return 0;
}

