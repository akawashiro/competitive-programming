//AOJ2185
#include <stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(T;0<T;T--){
		int x,y,w,h,n,s,t,ans=0;
		scanf("%d%d%d%d%d",&x,&y,&w,&h,&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&s,&t);
			if(x<=s&&s<=x+w&&y<=t&&t<=y+h)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

