#include <stdio.h>
int main(){
	int y,m,d;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF){
		int t=y*10000+m*100+d;
		if(t<18680908)
			printf("pre-meiji\n");
		else if(t<19120730)
			printf("meiji %d %d %d\n",y-1868+1,m,d);
		else if(t<19261225)
			printf("taisho %d %d %d\n",y-1912+1,m,d);
		else if(t<19890108)
			printf("showa %d %d %d\n",y-1926+1,m,d);
		else
			printf("heisei %d %d %d\n",y-1989+1,m,d);
	}
	return 0;
}

