#include <stdio.h>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>

using namespace std;

int dat[100000*16];
vector<pair<int,int> > typ;
vector<vector<int> > query;
map<pair<int,int>,int> ans;
map<int,int> comp;

void add(int a,int b,int k,int l,int r)
{
	//printf("add a=%d b=%d k=%d l=%d r=%d \n",a,b,k,l,r);
	//fflush(stdout);
	if(r<=a || b<=l)
		return;
	else if(a<=l && r<=b)
		dat[k]++;
	else{
		add(a,b,k*2+1,l,(l+r)/2);
		add(a,b,k*2+2,(l+r)/2,r);
	}
}

int sum(int a,int b,int k,int l,int r)
{
	//printf("sum a=%d b=%d k=%d l=%d r=%d \n",a,b,k,l,r);
	//fflush(stdout);
	if(l==a && b==r)
		return dat[k];
	else if(l<=a && b<=r){
		return dat[k]+sum(a,b,k*2+1,l,(l+r)/2)+sum(a,b,k*2+2,(l+r)/2,r);
	}
	else
		return 0;
}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		b++;
		comp[a]=comp[b]=0;
		typ.push_back(make_pair(a,b));
	}
	for(int i=0;i<m;i++){
		vector<int> v(3);
		scanf("%d%d%d",&v[0],&v[1],&v[2]);
		comp[v[0]]=0;
		v[1]--;
		query.push_back(v);
		ans[make_pair(v[1],v[0])]=-1;
		ans[make_pair(v[2],v[0])]=-1;
	}
	int tmp=0;
	for(map<int,int>::iterator it=comp.begin();it!=comp.end();it++,tmp++)
		(*it).second=tmp;
	k=comp.size();
	int t=0;
	for(map<pair<int,int>,int>::iterator it=ans.begin();it!=ans.end();it++){
		int q=(*it).first.first,p=(*it).first.second;
		//printf("p=%d q=%d\n",p,q);
		//fflush(stdout);
		while(t<q){
			add(comp[typ[t].first],comp[typ[t].second],0,0,k);
			t++;

			/*for(int i=0;i<k;i++)
				printf("%d ",sum(i,i+1,0,0,k));
			printf("\n");*/
		}
		ans[make_pair(q,p)]=sum(comp[p],comp[p]+1,0,0,k);
	}
	for(int i=0;i<m;i++)
		printf("%d\n",ans[make_pair(query[i][2],query[i][0])]-ans[make_pair(query[i][1],query[i][0])]);
	return 0;
}

