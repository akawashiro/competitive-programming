//AOJ1017
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> shuffle(vector<int> v,int c){
	int n=v.size();
	vector<int> A,B,C;
	for(int i=0;i<n;i++){
		if(i<n/2)	B.push_back(v[i]);
		else			A.push_back(v[i]);
	}
	int a=0,b=0;
	while(a<A.size()||b<B.size()){
		for(int i=0;i<c&&a<A.size();i++,a++)
			C.push_back(A[a]);
		for(int i=0;i<c&&b<B.size();i++,b++)
			C.push_back(B[b]);
	}
	return C;
}
int main(){
	while(1){
		int n,r;
		if(scanf("%d%d",&n,&r)==EOF)	break;
		vector<int> v;
		for(int i=0;i<n;i++)
			v.push_back(i);
		for(int i=0;i<r;i++){
			int c;
			scanf("%d",&c);
			v=shuffle(v,c);
		}
		printf("%d\n",v.back());
	}
	return 0;
}

