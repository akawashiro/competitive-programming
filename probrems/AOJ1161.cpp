//AOJ1161
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		if(!n)
			break;
		int used[26];
		int cou[26];
		int ng0[26];
		for(int i=0;i<26;i++){used[i]=0;cou[i]=0;ng0[i]=0;}
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=(int)s.size()-1,k=1;0<=j;j--,k*=10){
				used[s[j]-'A']=1;
				cou[s[j]-'A']+=(i!=n-1)?k:-k;
				if(j==0&&s.size()!=1)
					ng0[s[j]-'A']=1;
			}
		}
		int m=0;
		vector<int> pats;
		vector<int> zero;
		for(int i=0;i<26;i++)
			if(used[i]){
				m++;
				pats.push_back(cou[i]);
				zero.push_back(ng0[i]);
			}
		int ans=0;
		int nums[10];
		for(int i=0;i<10;i++)	nums[i]=i;
		do{
			int sum=0;
			int b=1;
			for(int j=0;j<m&&b;j++){
				if(zero[j]&&nums[j]==0)
					b=0;
				sum+=pats[j]*nums[j];
			}
			if(sum==0&&b){
				ans++;
			}
			reverse(nums+m,nums+10);
		}while(next_permutation(nums,nums+10));
		cout<<ans<<endl;
	}
	return 0;
}

