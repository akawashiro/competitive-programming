//AOJ0140
#include <stdio.h>
#include <vector>
using namespace std;
int s[15]={0,1,2,3,4,5,6,7,8,9,5,4,3,2,1};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		vector<int> ans(100,0);
		scanf("%d%d",&a,&b);
		for(int i=0;i<15;i++)
			if(a==s[i]){
				vector<int> v;
				for(int j=i;s[j]!=b;j=(j+1)%15)
					v.push_back(s[j]);
				v.push_back(b);
				if(v.size()<ans.size())
					ans=v;
			}
		for(int i=0;i<(int)ans.size();i++){
			if(i!=0)
				printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}

