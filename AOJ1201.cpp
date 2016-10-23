//AOJ1201
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
char bed[5][5];
string parts[10];
string rparts[10];
int revEq[10];
int leftp=(1<<10)-1;
int dfs(int k){
	if(k<5){
		int res=0;
		for(int i=0;i<10;i++)
			if(leftp&(1<<i)){
				leftp-=(1<<i);
				for(int j=0;j<5;j++)
					bed[k][j]=parts[i][j];
				res+=dfs(k+1);
				if(!revEq[i]){
					for(int j=0;j<5;j++)
						bed[k][j]=rparts[i][j];
					res+=dfs(k+1);
				}
				leftp+=(1<<i);
			}
		return res;
	}else{
		int l=leftp;
		for(int i=0;i<5;i++){
			char st[5];
			for(int j=0;j<5;j++)
				st[j]=(bed[j][i]=='1')?'0':'1';
			for(int j=0;j<10;j++)
				if((l&(1<<j))){
					int o=0;
					for(o=0;o<5;o++)
						if(st[o]!=parts[j][o])
							break;
					if(o==5){
						l-=(1<<j);
						break;
					}
					for(o=0;o<5;o++)
						if(st[o]!=rparts[j][o])
							break;
					if(o==5){
						l-=(1<<j);
						break;
					}

				}
		}
		return (l==0);
	}
}
int main(){
	while(1){
		for(int i=0;i<10;i++){
			cin>>parts[i];
			if(parts[i]=="END")
				return 0;
			rparts[i]=parts[i];
			reverse(rparts[i].begin(),rparts[i].end());
			revEq[i]=(parts[i]==rparts[i]);
		}
		cout<<dfs(0)/8<<endl;
	}
	return 0;
}

