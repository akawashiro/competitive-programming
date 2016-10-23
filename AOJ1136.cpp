#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#define FI first
#define SE second
#define PB push_back
#define MP make_pair

using namespace std;

int main()
{
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)
			break;
		vector<pair<int,int> > vv;
		for(int l=0;l<=n;l++){
			int m;
			vector<pair<int,int> > v;
			vector<pair<int,int> > r;
			scanf("%d",&m);
			for(int i=0;i<m;i++){
				int x,y;
				scanf("%d%d",&x,&y);
				v.PB(MP(x,y));
			}
			for(int i=1;i<m;i++)
				v[i].FI-=v[0].FI,v[i].SE-=v[0].SE;
			v[0].FI=0,v[0].SE=0;
			r=v;
			reverse(r.begin(),r.end());
			for(int i=1;i<m;i++)
				r[i].FI-=r[0].FI,r[i].SE-=r[0].SE;
			r[0].FI=0,r[0].SE=0;
			if(l==0)
				vv=v;
			else{
				for(int i=0;i<4;i++){
					for(int j=0;j<m;j++){
						int xx=-v[j].SE,yy=v[j].FI;
						v[j].FI=xx,v[j].SE=yy;
						xx=-r[j].SE,yy=r[j].FI;
						r[j].FI=xx,r[j].SE=yy;
					}
					if(vv==v || vv==r){
						printf("%d\n",l);
						break;
					}
				}
			}
		}
		printf("+++++\n");
	}
	return 0;
}

