//CF105div2TersePrincess
#include <stdio.h>
int ans[110];
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	ans[0]=1;
	int p=1,s=1,m=1;
	for(int i=p;i<p+b;i++){
		ans[i]=s+1;
		s+=ans[i];
		if(m<ans[i])
			m=ans[i];
	}
	p+=b;
	for(int i=p;i<p+n-a-b-1;i++)
		ans[i]=1;
	p+=n-a-b-1;
	for(int i=p;i<n;i++){
		ans[i]=m+1;
		if(m<ans[i])
			m=ans[i];
	}

	/*printf("ans = ");
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");*/

	int aa=0,bb=0,ss=1,ma=1,ok=1;
	for(int i=1;i<n;i++){
		if(ss<ans[i])
			bb++;
		else if(ma<ans[i])
			aa++;
		if(50000<ans[i])
			ok=0;
		ss+=ans[i];
		if(ma<ans[i])
			ma=ans[i];
	}
	//printf("aa=%d bb=%d\n",aa,bb);
	if(aa==a&&bb==b&&ok){
		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}else{
		printf("-1\n");
	}
	return 0;
}

