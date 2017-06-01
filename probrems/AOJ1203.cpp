//AOJ1203
#include <string>
#include <iostream>
#include <set>
#include <string.h>
using namespace std;
int dp[1030][1030];
int main(){
	string s;
	while(getline(cin,s)){
		string in;
		for(int i=0;i<(int)s.size();i++)
			if('A'<=s[i]&&s[i]<='Z')	in+=s[i];
			else if('a'<=s[i]&&s[i]<='z')	in+=s[i]-'a'+'A';
		int n=in.size();
		memset(dp,0,sizeof(dp));
		set<string> ans,ng;
		for(int i=0;i<n;i++)
			dp[i][i]=1,dp[i][i+1]=1;
		for(int l=2;l<=n;l++)
			for(int i=0;i+l<=n;i++)
				if(dp[i+1][i+1+l-2]==1&&in[i]==in[i+l-1]){
					dp[i+1][i+l-2]=0;
					ng.insert(in.substr(i+1,l-2));
					dp[i][i+l]=1;
					ans.insert(in.substr(i,l));
				}
		for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
			if(3<=(*it).size()&&ng.find(*it)==ng.end())
				cout<<*it<<" ";
		cout<<endl;
	}
	return 0;
}

