#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int m;
	scanf("%d",&m);
	for(m;0<m;m--){
		int f,y,n,ans=-1;
		scanf("%d%d%d",&f,&y,&n);
		for(n;0<n;n--){
			int t,ma,mm=f,pl=0;
			double p;
			scanf("%d%lf%d",&t,&p,&ma);
			if(t)
				for(int i=0;i<y;i++)
					mm*=(p+1.0),mm-=ma;
			else{
				for(int i=0;i<y;i++)
					pl+=mm*p,mm-=ma;
				mm+=pl;
			}
			ans=max(ans,mm);
			//printf("t=%d mm=%d\n",t,mm);
		}
		printf("%d\n",ans);
	}
	return 0;
}

