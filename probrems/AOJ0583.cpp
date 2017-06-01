#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define ALL(X)      (X).begin(),(X).end()

using namespace std;

vector<pair<int,int> > primeFactor(int num){ //first->prime,second->pow{
    if(num==1){
	 vector<pair<int,int> > r;
	 r.push_back(make_pair(1,1));
	 return r;
    }else{
	 vector<pair<int,int> > r;
	 for(int i=2;i*i<=num;i++){
	      if(num%i==0){
		   int p=0;
		   while(num%i==0)
			num/=i,p++;
		   r.push_back(make_pair(i,p));
	      }
	 }
	 if(num!=1)
	      r.push_back(make_pair(num,1));
	 return r;
    }
}

vector<pair<int,int> > cp;
vector<int> ans;

inline int ipow(int n,int p){
     int r=1;
     FOR(i,0,p)r*=n;
     return r;
}

void rec(int k,int r){
     if(k==SZ(cp)){
	  ans.push_back(r);
     }else{
	  for(int i=0;i<=cp[k].second;i++)
	       rec(k+1,r*ipow(cp[k].first,i));
     }
}

int main(void)
{
     int n;
     scanf("%d",&n);
     vector<pair<int,int> > vp[3];
     FOR(i,0,n){
	  int a;
	  scanf("%d",&a);
	  vp[i]=primeFactor(a);
     }
     cp=vp[0];
     
     for(int i=0;i<SZ(cp);i++){
	  for(int j=0;j<n;j++){
	       int k;
	       for(k=0;k<SZ(vp[j]);k++)
		    if(cp[i].first==vp[j][k].first){
			 cp[i].second=min(cp[i].second,vp[j][k].second);
			 break;
		    }
	       if(k==SZ(vp[j]))
		    cp[i].second=0;
		    
	  }
     }
     sort(ALL(cp));
/*     for(int i=0;i<SZ(cp);i++)
       printf("(%d %d)\n",cp[i].first,cp[i].second);*/
     rec(0,1);
     sort(ALL(ans));
     FORIT(it,ans)printf("%d\n",*it);
     return 0;
}
