//AOJ1124
#include <stdio.h>
#include <map>
using namespace std;
int main(){
	while(1){
		int n,q;
		scanf("%d%d",&n,&q);
		if(!n&&!q)
			break;
		map<int,int> ma;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			for(int j=0;j<a;j++){
				int b;
				scanf("%d",&b);
				ma[b]++;
			}
		}
		ma[0]=0;
		int ans=0;
		for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
			if(q<=(*it).second && ma[ans]<(*it).second)
				ans=(*it).first;
		printf("%d\n",ans);
	}
	return 0;
}

