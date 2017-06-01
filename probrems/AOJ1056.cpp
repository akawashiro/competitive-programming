#include <stdio.h>
#include <math.h>
#define MAX_N 100000 

int n;
//double cache[MAX_N+10][32];
double DP[MAX_N+10][32];

/*double rec(int day,int seq)
{
	if(-1<cache[day][seq])
		return cache[day][seq];
	else if(day==n || seq==30)
		return cache[day][seq]=0;
	else
		return cache[day][seq]=pow(0.5,seq)*(1.0+rec(day+1,seq+1))+(1-pow(0.5,seq))*rec(day+1,0);
}*/

int main()
{
	while(1){
		scanf("%d",&n);
		if(n==0)
			break;
		/*for(int i=0;i<MAX_N+10;i++)
			for(int j=0;j<n;j++)
				cache[i][j]=-2.0;*/
		for(int day=n;0<=day;day--)
			for(int seq=0;seq<=10;seq++)
				if(day==n || seq==10)
					DP[day][seq]=0;
				else{
					double p=pow(0.5,seq);
					DP[day][seq]=p*(1+DP[day+1][seq+1])+(1.0-p)*DP[day+1][0];
				}
		printf("%lf\n",DP[0][0]);
	}
	return 0;
}

