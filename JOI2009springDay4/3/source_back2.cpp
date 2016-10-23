#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int L[4000+10];
int x[4000+10];
int y[4000+10];
int data[4000*8];
int datb[4000*8];

int add(int a,int b,int k,int l,int r,int x)
{
	if(r<=a || b<=l){
		return datb[k];
	}else if(a<=l && r<=b){
		data[k]+=x;
		datb[k]+=x;
		return datb[k];
	}else{
		return datb[k]=data[k]+max(add(a,b,k*2+1,l,(l+r)/2,x),add(a,b,k*2+2,(l+r)/2,r,x));
	}
}

int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d",&x[i],&y[i],&L[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(L[j]>L[j+1])
				swap(x[j],x[j+1]),swap(y[j],y[j+1]),swap(L[j],L[j+1]);

	for(int iL=0;iL<n;iL++){
		int m;
		map<int,int> comp;
		vector<pair<int,int> > query;	//(y,x)	x<-1 -> delete
		for(int i=0;i<n;i++)
			if(L[iL]<=L[i]){
				query.push_back(make_pair(y[i],x[i]));
				query.push_back(make_pair(y[i]+L[iL],-x[i]-1));
				comp[x[i]]=0;
				comp[x[i]+L[iL]]=0;
			}
		sort(query.begin(),query.end());
		m=0;
		for(map<int,int>::iterator it=comp.begin();it!=comp.end();it++,m++){
			(*it).second=m;
		}
		memset(data,0,sizeof(data));
		memset(datb,0,sizeof(datb));
		for(int iQ=0;iQ<(int)query.size();iQ++){
			int yy,xx,b,e;
			yy=query[iQ].first;
			xx=query[iQ].second;
			if(xx<-1){
				xx=-(xx+1);
				b=comp[xx];
				e=comp[xx+L[iL]]+1;
				add(b,e,0,0,m,-1);
			}else{
				b=comp[xx];
				e=comp[xx+L[iL]]+1;
				add(b,e,0,0,m,1);
			}
			ans=max(ans,datb[0]);
		}
	}
	printf("%d\n",ans);
	return 0;
}

