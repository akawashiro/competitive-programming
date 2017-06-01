#include <stdio.h>
#include <string.h>
#include <set>
#include <utility>
using namespace std;
typedef pair<int,pair<int,int> > P;
P makeP(int x,int y,int z){return make_pair(x,make_pair(y,z));}

int main()
{
	while(1){
	int n,h;
	set<P> se;
	scanf("%d%d",&n,&h);
	if(n==0 && h==0)
		break;
	for(int i=0;i<h;i++){
		char s[10];
		int x,y,z;
		scanf("%s,",s);
		if(strcmp(s,"xy")==0){
			scanf("%d%d",&x,&y);
			for(z=1;z<=n;z++)
				se.insert(makeP(x,y,z));
		}else if(strcmp(s,"yz")==0){
			scanf("%d%d",&y,&z);
			for(x=1;x<=n;x++)
				se.insert(makeP(x,y,z));
		}else{
			scanf("%d%d",&x,&z);
			for(y=1;y<=n;y++)
				se.insert(makeP(x,y,z));
		}
	}
	printf("%d\n",n*n*n-se.size());
	}
	return 0;
}

