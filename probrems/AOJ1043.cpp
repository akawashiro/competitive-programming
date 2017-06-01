#include <map>
#include <stdio.h>
#include <string.h>
#define MP make_pair
#define FI first
#define SE second

using namespace std;
int univ[1000+10];

int main()
{
	while(1){
		int n,s=0;
		map<pair<pair<int,int>,int>,pair<int,int> > ma;
		scanf("%d",&n);
		if(n==0)
			break;
		memset(univ,0,sizeof(univ));
		for(int i=0;i<n;i++){
			int l,u,a,p;
			scanf("%d%d%d%d",&l,&u,&a,&p);
			ma[MP(MP(-a,p),l)]=MP(l,u);
		}
		map<pair<pair<int,int>,int>,pair<int,int> >::iterator it;
		for(it=ma.begin();it!=ma.end();it++)
			if(s<10 && univ[(*it).SE.SE]<3){
				s++;
				univ[(*it).SE.SE]++;
				printf("%d\n",(*it).SE.FI);
			}
			else if(s<20 && univ[(*it).SE.SE]<2){
				s++;
				univ[(*it).SE.SE]++;
				printf("%d\n",(*it).SE.FI);
			}
			else if(s<26 && univ[(*it).SE.SE]<1){
				s++;
				univ[(*it).SE.SE]++;
				printf("%d\n",(*it).SE.FI);
			}
	}
	return 0;
}

