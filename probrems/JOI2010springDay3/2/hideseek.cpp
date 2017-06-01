#include <vector>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;
typedef pair<pair<int,int>,int> P;

int ans[50000+10][2];
int data[100000*4];
int datb[100000*4];
vector<P> hurdle;

int add(int a,int b,int k,int l,int r)
{
	//printf("add(%d,%d,%d,%d,%d)\n",a,b,k,l,r);
	//fflush(stdout);
	if(r<=a || b<=l)
		return datb[k];
	else if(a<=l && r<=b){
		data[k]++;
		datb[k]++;
		return datb[k];
	}
	else if(l<b && a<r){
		int res=0;
		res=max(res,add(a,b,k*2+1,l,(l+r)/2));
		res=max(res,add(a,b,k*2+2,(l+r)/2,r));
		return datb[k]=res+data[k];
	}
}

int maxX(int k,int l,int r,int x)
{
	//printf("maxX(%d,%d,%d,%d)\n",k,l,r,x);
	//fflush(stdout);
	if(datb[k]!=x)
		return -1;
	else if(r-l==1)
		return l;
	else{
		int res=maxX(k*2+1,l,(l+r)/2,x-data[k]);
		if(res!=-1)
			return res;
		else
			return maxX(k*2+2,(l+r)/2,r,x-data[k]);
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		hurdle.push_back(make_pair(make_pair(y,x),w));
	}
	sort(hurdle.begin(),hurdle.end());
	memset(ans,-1,sizeof(ans));
		//printf("h=%d\n",datb[0]);
	for(int i=0;i<n;i++){
		int y,x,w,h,xx;
		y=hurdle[i].first.first;
		x=hurdle[i].first.second;
		w=hurdle[i].second;
		add(x,x+w,0,1,100000+1);
		h=datb[0];
		//printf("h=%d\n",h);
		xx=maxX(0,1,100000+1,h);
		if(ans[h-1][0]==-1)
			ans[h-1][0]=xx,ans[h-1][1]=y;
	}
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		printf("%d %d\n",ans[a][0],ans[a][1]);
	}
	return 0;
}

