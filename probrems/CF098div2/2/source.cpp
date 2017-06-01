#include <vector>
#include <stdio.h>
using namespace std;
int v[10000];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(n<a||v[a])
			ans++;
		if(a<=n)
			v[a]=1;
	}
	printf("%d\n",ans);
	return 0;
}

