#include <stdio.h>
#include <string.h>

typedef long long LL;

char input[100000+10];
LL DP3[100000+10];
LL DP5[100000+10];
LL DP23[100000+10];
LL DP25[100000+10];

int main()
{
	for(int i=0;i<100000+10;i++)
		if(i==0){
			DP3[i]=1;
			DP5[i]=1;
		}else{
			DP3[i]=0;
			for(int j=i-1;0<=j && i-3<=j;j--)
				DP3[i]=(DP3[i]+DP3[j])%100000007;
			DP5[i]=0;
			for(int j=i-1;0<=j && i-5<=j;j--)
				DP5[i]=(DP5[i]+DP5[j])%100000007;
		}
	for(int i=0;i<100000+10;i++){
		if(i<4)
			DP23[i]=DP3[i];
		else
			DP23[i]=(DP3[i]+DP23[i-3])%100000007;
	}
	for(int i=0;i<100000+10;i++){
		if(i<6)
			DP25[i]=DP5[i];
		else
			DP25[i]=(DP5[i]+DP25[i-5])%100000007;
	}
	while(1){
		scanf("%s",input);
		int n=strlen(input);
		if(input[0]=='#')
			break;
		LL ans=1;
		int s=0;
		char c='#';
		for(int p=0;p<n;p++){
			if(input[p]==c)
				s++;
			else{
				if(c=='8' || c=='0')
					ans=ans*DP23[s]%100000007;
				else
					ans=ans*DP25[s]%100000007;
				c=input[p];
				s=1;
			}
		}
		if(c=='8' || c=='0')
			ans=ans*DP23[s]%100000007;
		else
			ans=ans*DP25[s]%100000007;
		printf("%lld\n",ans);
	}
	return 0;
}

