#include <map>
#include <iostream>
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		if(!n)
			break;
		map<int,int> ma;
		int b=0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			ma[a]++;
		}
		for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
			if(n<(*it).second*2){
				b=1;
				cout<<(*it).first<<endl;
			}
		if(!b)
			cout<<"NO COLOR"<<endl;
	}
	return 0;
}

