//AOJ0142
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)	break;
		set<int> se;
		for(int i=1;i<n;i++)
			se.insert(i*i%n);
		vector<int> v(se.begin(),se.end());
		vector<int> r((n-1)/2+1,0);
		for(int i=0;i<(int)v.size();i++)
			for(int j=0;j<(int)v.size();j++){
				int a=v[i]-v[j];
				if(a<0)	a+=n;
				if((n-1)/2<a)	a=n-a;
				r[a]++;
			}
		for(int i=1;i<=(n-1)/2;i++)
			printf("%d\n",r[i]);
	}
	return 0;
}

