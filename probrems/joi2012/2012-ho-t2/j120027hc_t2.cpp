#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
short dp[5010][5010];
short ac[5010],bc[5010];
int rec(int ap,int bp){
	if(ap<0||bp<0)
		return 0;
	else if(dp[ap][bp]!=-1)
		return dp[ap][bp];
	else{
		int r=rec(ap-1,bp);
		if(ac[ap]==bc[bp])
			r=max(r,rec(ap-1,bp-1)+1);
		return dp[ap][bp]=r;
	}
}
int main(){
	int an,bn;
	scanf("%d%d",&an,&bn);
	for(int i=0;i<an;i++)
		scanf("%d",ac+i);
	for(int i=0;i<bn;i++)
		scanf("%d",bc+i);
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int i=0;i<an;i++)
		for(int j=0;j<bn;j++)
			ans=max(ans,rec(i,j));
	printf("%d\n",ans);
	return 0;
}

