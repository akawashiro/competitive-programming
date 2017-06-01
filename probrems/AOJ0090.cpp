#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
double x[100],y[100];
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)	break;
		for(int i=0;i<n;i++)
			scanf("%lf,%lf\n",&x[i],&y[i]);
		int ans=0;
		for(double a=0;a<=10.1;a+=0.01)
			for(double b=0;b<=10.1;b+=0.01){
				int t=0;
				for(int i=0;i<n;i++)
					if((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i])<=1.001)
						t++;
				ans=max(ans,t);
			}
		printf("%d\n",ans);
	}
	return 0;
}
