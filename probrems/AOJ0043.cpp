//AOJ0043
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int pi[14];
int dp[1<<14];
int popCount(int _mask){
	int r=0;
	for(int i=0;i<31;i++)if(_mask & (1<<i))r++;
	return r;
}
int dfs(int left){
	if(dp[left]!=-1)	return dp[left];
	if(popCount(left)==2){
		for(int i=0;i<14;i++)
			for(int j=i+1;j<14;j++)
				if((left&(1<<i))&&(left&(1<<j))&&pi[i]==pi[j])
					return dp[left]=1;
		return dp[left]=0;
	}
	for(int i=0;i<14;i++)
		for(int j=i+1;j<14;j++)
			for(int k=j+1;k<14;k++)
				if((left&(1<<i))&&(left&(1<<j))&&(left&(1<<k))){
					int a=pi[i],b=pi[j],c=pi[k];
					int l=left-(1<<i)-(1<<j)-(1<<k);
					if(((a==b&&b==c)||(a+1==b&&b+1==c))&&dfs(l))
						return dp[left]=1;
				}
	return dp[left]=0;
}
int main(){
	while(1){
		string s;
		vector<int> co(10,0);
		vector<int> ans;
		if(!(cin>>s))	break;
		for(int i=0;i<10;i++)	co[i]=count(s.begin(),s.end(),i+'0');
		for(int i=1;i<10;i++)
			if(co[i]<4){
				for(int j=0;j<13;j++)	pi[j]=s[j]-'0';
				pi[13]=i;
				sort(pi,pi+14);
				memset(dp,-1,sizeof(dp));
				if(dfs((1<<14)-1))	ans.push_back(i);
			}
		if(ans.size()==0)	cout<<0<<endl;
		else{
			for(int i=0;i<(int)ans.size();i++){
				if(i!=0)	cout<<" ";
				cout<<ans[i];
			}
			cout<<endl;
		}
	}
	return 0;
}

