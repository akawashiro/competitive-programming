//ArrivalOfTheGeneral
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int ai[100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",ai+i);
	int maxP=-1,minP;
	for(int i=0;i<n;i++){
		if(maxP==-1&&ai[i]==*max_element(ai,ai+n))
			maxP=i;
		if(ai[i]==*min_element(ai,ai+n))
			minP=i;
	}
	if(minP<maxP)
		minP++;
	printf("%d\n",maxP+n-1-minP);
	return 0;
}

