#include <stdio.h>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>

using namespace std;

int dat[100000*16];
vector<int> t1,t2;
vector<int> q1,q2,q3;
map<pair<int,int>,int> ans;
map<int,int> comp;

void add(int a,int b,int k,int l,int r)
{
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
	int res=0;
	while(1){
		res+=dat[k];
		if(l==a && b==r){
			break;
		}else{
			if(b<=(l+r)/2)
				r=(l+r)/2,k=k*2+1;
			else
				l=(l+r)/2,k=k*2+2;
		}
	}
	return res;
}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		comp[a]=comp[b]=0;
		t1.push_back(a);
		t2.push_back(b);
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		comp[a]=0;
		b--;
		q1.push_back(a);
		q2.push_back(b);
		q3.push_back(c);
		ans[make_pair(b,a)]=-1;
		ans[make_pair(c,a)]=-1;
	}
	int tmp=0;
	for(map<int,int>::iterator it=comp.begin();it!=comp.end();it++,tmp++)
		(*it).second=tmp;
	k=comp.size();
	int t=0;
	for(map<pair<int,int>,int>::iterator it=ans.begin();it!=ans.end();it++){
		int q=(*it).first.first,p=(*it).first.second;
		while(t<q){
			add(comp[t1[t]],comp[t2[t]]+1,0,0,k);
			t++;
		}
		(*it).second=sum(comp[p],comp[p]+1,0,0,k);
	}
	for(int i=0;i<m;i++)
		printf("%d\n",ans[make_pair(q3[i],q1[i])]-ans[make_pair(q2[i],q1[i])]);
	return 0;
}

