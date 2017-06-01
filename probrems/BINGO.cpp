#include <stdio.h>
#include <string.h>

int DP[2][2000+100][3000+100];

int main()
{
	while(1)
	{
		int _n,n,M,S,ans=0;
		scanf("%d%d%d",&_n,&M,&S);
		n=_n*_n;
		if(n==0 && M==0 && S==0)
			break;
		memset(DP[0],0,sizeof(DP[0]));
		DP[0][1][n]=1;
		int p,ap,s;
		for(p=0;p<n;p++)
		{
			int pnow=p%2,pnext=(p+1)%2;
			int l1=M-n+p+1;
			int l2=S-(n-p-1)*(n-p)/2;
			//memset(DP[pnext],0,sizeof(DP[pnext]));
			for(s=1;s<=l2;s++)
				for(ap=1;ap<=l1;ap++)
				{
					DP[pnow][ap][s]%=100000;
					int now=DP[pnow][ap][s];
					if(now==0)
						continue;
					//printf("DP[%d][%d][%d]=%d\n",p,ap,s,now);
					DP[pnow][ap+1][s+(n-p)]+=now;
					DP[pnext][ap+1][s+(n-p-1)]+=now;
				}
		}
		int plast=(n-1)%2;
		for(int a=1;a<=M;a++)
			ans=(ans+DP[plast][a][S])%100000;
		printf("%d\n",ans);
	}
	return 0;
}

