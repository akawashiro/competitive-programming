#include <stdio.h>
int used[1000+1][1000+1];
double dp[1000+1][1000+1];
double rec(int w,int b){
	if(w<=0||b<0)
		return 0;
	if(used[w][b])	
		return dp[w][b];
	else{
		dp[w][b]=(double)w/(w+b);
		if(2<=b){
			double p=(double)b/(w+b)*(b-1)/(w+b-1);
			if(1<=w)
				dp[w][b]+=p*w/(w+b-2)*rec(w-1,b-2);
			if(3<=b)
				dp[w][b]+=p*(b-2)/(w+b-2)*rec(w,b-3);
		}
	}
	used[w][b]=1;
	//printf("dp[%d][%d]=%lf\n",w,b,dp[w][b]);
	return dp[w][b];
}
int main(){
	int w,b;
	scanf("%d%d",&w,&b);
	printf("%.15lf\n",rec(w,b));
	return 0;
}
