#include <stdio.h>
#include <string.h>
int r[50000],c[50000];
int A[50000],B[50000],o[50000];
int main(){
	while(1){
		int h,w,q;
		scanf("%d%d%d",&h,&w,&q);
		if(!h&&!w&&!q)
			break;
		for(int i=0;i<q;i++)
			scanf("%d%d%d",A+i,B+i,o+i);
		long long ans=0;
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		for(int i=q-1;0<=i;i--){
			if((!A[i])&&(!r[B[i]])){
				r[B[i]]=1;
				h--;
				if(o[i]){
					ans+=w;
				}
			}else if(A[i]&&!c[B[i]]){
				c[B[i]]=1;
				w--;
				if(o[i]){
					ans+=h;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

