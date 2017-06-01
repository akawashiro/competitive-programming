//AOJ0167
#include <stdio.h>
#include <algorithm>
using namespace std;
int ar[100];
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",ar+i);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n-1;j++)
				if(ar[j]>ar[j+1]){
					swap(ar[j],ar[j+1]);
					ans++;
				}
		printf("%d\n",ans);
	}
	return 0;
}

