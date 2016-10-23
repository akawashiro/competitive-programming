//CF100div2NewYearContest
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> prob(n);
	vector<int> sum(n,10);
	for(int i=0;i<n;i++)
		scanf("%d",&prob[i]);
	sort(prob.begin(),prob.end());
	for(int i=0;i<n;i++){
		if(0<i)
			sum[i]=sum[i-1];
		sum[i]+=prob[i];
	}
	int s=0,p=0;
	for(int i=0;i<n&&sum[i]<=720;i++){
		s++;
		if(360<sum[i])
			p+=sum[i]-360;
	}
	printf("%d %d\n",s,p);
	return 0;
}

