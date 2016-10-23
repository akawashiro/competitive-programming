//AOJ2284
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#define Fi first
#define Se second
#define INF 1000000
using namespace std;
int stoi(string s){
	stringstream ss(s);
	int r;
	ss>>r;
	return r;
}
int np,h,w;
vector<vector<int> > pos;
vector<vector<int> > dp;
int rec(int k,int p){
	if(k==np-1)	return 0;
	else if(dp[k][p]!=-1)	return dp[k][p];
	else{
		dp[k][p]=INF;
		for(int i=0;i<(int)pos[k+1].size();i++){
			int y=pos[k][p]/w-pos[k+1][i]/w;
			int x=pos[k][p]%w-pos[k+1][i]%w;
			if(y<0)	y=-y;
			if(x<0)	x=-x;
			dp[k][p]=min(dp[k][p],y+x+rec(k+1,i));
		}
		return dp[k][p];
	}
}
int main(){
	while(1){
		map<int,vector<int> > ma;
		cin>>w>>h;
		if(!w&&!h)	break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				string s;
				cin>>s;
				if(s==".")
					;
				else if(s=="S")
					ma[0].push_back(i*w+j);
				else if(s=="G")
					ma[INF].push_back(i*w+j);
				else
					ma[stoi(s)].push_back(i*w+j);
			}
		pos.clear();
		np=ma.size();
		int v=0;
		for(map<int,vector<int> >::iterator it=ma.begin();it!=ma.end();it++){
			v=max(v,(int)(*it).second.size());
			pos.push_back((*it).second);
		}
		dp=vector<vector<int> >(np,vector<int>(v,-1));
		cout<<rec(0,0)<<endl;
	}
	return 0;
}

