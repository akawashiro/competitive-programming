#include <stdio.h>
#include <string.h>
int prf[400][400];
int ord[400];
int usd[400];
int ans[400];
int tmp[400];
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&prf[i][j]);
			prf[i][j]--;
		}
	for(i=0;i<n;i++){
		scanf("%d",&ord[i]);
		ord[i]--;
		ans[i]=n-1;
	}
	for(int card=0;card<n;card++){
		for(int to=0;to<n;to++){
			if(!usd[to]){
				memset(tmp,0,sizeof(tmp));
				int s=-1;
				for(i=0;i<n;i++)
					if(ord[i]<=card&&ord[i]!=to){s=ord[i];break;}
				//printf("card=%d to=%d s=%d\n",card,to,s);
				if(s==-1)	continue;
				ans[to]=s;
				i++;
				for(;i<n;i++)	tmp[ord[i]]=1;
				tmp[to]=1;
				i=0;
				while(i<n&&tmp[prf[to][i]])
					i++;
				if(i<n&&prf[to][i]==s){
					ans[to]=s;
					usd[to]=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]+1);
	return 0;
}

