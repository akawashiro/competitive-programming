//AOJ0108
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;
vector<int> f(vector<int> v){
	int n=v.size();
	vector<int> r(n);
	map<int,int> ma;
	for(int i=0;i<n;i++)
		ma[v[i]]++;
	for(int i=0;i<n;i++)
		r[i]=ma[v[i]];
	return r;
}
int main(){
	while(1){
		int n,m=0;
		vector<int> b,v;
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			v.push_back(a);
		}
		b=v;
		v=f(b);
		for(;v!=b;m++){
			b=v;
			v=f(b);
		}
		printf("%d\n",m);
		for(int i=0;i<n;i++){
			if(i!=0)
				printf(" ");
			printf("%d",v[i]);
		}
		printf("\n");
	}
	return 0;
}

