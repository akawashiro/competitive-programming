//AOJ1210
#include <string>
#include <iostream>
using namespace std;
int main(){
	while(1){
		int n;
		cin>>n;
		if(!n)	break;
		int d[6]={1,2,4,5,3,6};
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			if(s=="north"){
				int t=d[0];
				d[0]=d[3],d[3]=d[5],d[5]=d[1],d[1]=t;
			}
			if(s=="south"){
				int t=d[0];
				d[0]=d[1],d[1]=d[5],d[5]=d[3],d[3]=t;
			}
			if(s=="west"){
				int t=d[0];
				d[0]=d[2],d[2]=d[5],d[5]=d[4],d[4]=t;
			}
			if(s=="east"){
				int t=d[0];
				d[0]=d[4],d[4]=d[5],d[5]=d[2],d[2]=t;
			}
		}
		cout<<d[0]<<endl;
	}
	return 0;
}

