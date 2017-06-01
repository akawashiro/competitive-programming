//AOJ2207
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#define INF (1<<20)
using namespace std;
int stringToInt(string s){
	stringstream ss(s);
	int r;
	ss>>r;
	return r;
}
int G[200][200];
int g[200][200];
int main(){
	while(1){
		for(int i=0;i<200;i++)for(int j=0;j<200;j++){G[i][j]=INF,g[i][j]=0;}
		for(int i=0;i<200;i++)G[i][i]=0;
		int n;
		cin>>n;
		if(!n)	break;
		vector<string> vs1(n),vs2(n),vs3(n);
		map<string,int> ma;
		for(int i=0;i<n;i++){
			string s,t;
			cin>>s>>vs1[i]>>t>>vs2[i]>>vs3[i];
			vs2[i]=vs2[i].substr(3);
			if(ma.find(vs1[i])==ma.end())
				ma[vs1[i]]=ma.size();
			if(ma.find(vs3[i])==ma.end())
				ma[vs3[i]]=ma.size();
			//cout<<vs1[i]<<" "<<vs2[i]<<" "<<vs3[i]<<endl;
		}
		for(int i=0;i<n;i++){
			G[ma[vs1[i]]][ma[vs3[i]]]=stringToInt(vs2[i]);
			G[ma[vs3[i]]][ma[vs1[i]]]=-stringToInt(vs2[i]);
			g[ma[vs1[i]]][ma[vs3[i]]]=1;
			g[ma[vs3[i]]][ma[vs1[i]]]=1;
			//printf("from %d to %d = %d\n",ma[vs1[i]],ma[vs3[i]],stringToInt(vs2[i]));
		}
		int ok=1;
		for(int k=0;k<200;k++)
			for(int i=0;i<200;i++)
				for(int j=0;j<200;j++){
					if(G[i][k]+G[k][j]<G[i][j]&&g[i][j]){
						//printf("i=%d j=%d\n",i,j);
						ok=0;
					}
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				}
		if(ok)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

