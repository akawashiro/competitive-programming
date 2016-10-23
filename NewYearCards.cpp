//CF100div2NewYearCards
#include <stdio.h>
#include <string.h>
int ans[300],alex[300];
int pref[300][300];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&pref[i][j]);
	for(int i=0;i<n;i++)
		scanf("%d",&alex[i]);
	memset(ans,-1,sizeof(ans));
	for(int c=1;c<=n;c++){
		int f=-1,s=-1;
		for(int i=0;i<n;i++)
			if(alex[i]<=c){
				if(f==-1)
					f=alex[i];
				else if(s==-1)
					s=alex[i];
			}
		for(int i=0;i<n;i++){
			int a=(f==i+1)?s:f;
			//printf("a=%d\n",a);fflush(stdout);
			if(a==-1)	continue;
			if(ans[i]==-1){
				ans[i]=a;
				continue;
			}else{
				for(int j=0;j<n;j++)
					if(pref[i][j]==ans[i])
						break;
					else if(pref[i][j]==a){
						ans[i]=a;
						break;
					}
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}

