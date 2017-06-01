#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	while(1){
		int n,U;
		scanf("%d%d",&n,&U);
		if(!n&&!U)	break;
		vector<int> c(n);
		vector<int> req(n);
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
			req[i]=0;
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				int r;
				scanf("%d",&r);
				req[i]+=1<<r;
			}
		}
		int ans=n;
		for(int m=0;m<(1<<n);m++){
			int t=0;
			int a=0;
			for(int i=0;i<n;i++)
				if(m&(1<<i)){
					a++;
					if(((m-req[i])|req[i])==m)
						t+=c[i];
				}
			if(U<=t&&a<ans)
				ans=a;
		}
		printf("%d\n",ans);
	}
	return 0;
}


