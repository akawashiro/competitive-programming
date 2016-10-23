#include <stdio.h>
int main()
{
	while(1){
		int l,ans=100;
		scanf("%d",&l);
		if(!l)
			break;
		for(int i=1;i<13;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			l-=(a-b);
			if(l<=0 && ans==100)
				ans=i;
		}
		if(ans==100)
			printf("NA\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}

