#include <stdio.h>
#include <algorithm>
using namespace std;
int gr[20];
int main(){
	int k;
	scanf("%d",&k);
	for(int i=0;i<12;i++)	scanf("%d",gr+i);
	sort(gr,gr+12);reverse(gr,gr+12);
	int ans=0,g=0;
	for(int i=0;i<12&&g<k;i++){
		g+=gr[i];
		ans++;
	}
	if(g<k)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}

