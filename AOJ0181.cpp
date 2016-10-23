//AOJ0181
#include <stdio.h>
int n,m;
int book[100];
int check(int w){
	int res=0;
	int a=0;
	for(int i=0;i<n;i++){
		if(w<book[i])
			return 0;
		if(w<a+book[i]){
			a=0;
			res++;
		}
		a+=book[i];
	}
	if(0<a)
		res++;
	return res<=m;
}
int main(){
	while(1){
		scanf("%d%d",&m,&n);
		if(!m&&!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",book+i);
		int ce=1500000,bo=0;
		while(1<ce-bo){
			int mi=(ce+bo)/2;
			if(check(mi))
				ce=mi;
			else
				bo=mi;
		}
		if(check(bo))
			printf("%d\n",bo);
		else
			printf("%d\n",ce);
	}
	return 0;
}

