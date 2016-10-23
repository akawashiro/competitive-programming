//AOJ1104
#include <string>
#include <iostream>
using namespace std;
int mv[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
	while(1){
		int w,h;
		cin>>w>>h;
		if(!w)	break;
		int y=1,x=1,m=0;
		while(1){
			string s;
			int a;
			cin>>s;
			if(s=="FORWARD"){
				cin>>a;
				y+=mv[m][0]*a,x+=mv[m][1]*a;
			}else if(s=="BACKWARD"){
				cin>>a;
				y-=mv[m][0]*a,x-=mv[m][1]*a;
			}else if(s=="RIGHT"){
				m=(m+1)%4;
			}else if(s=="LEFT"){
				m=(m-1+4)%4;
			}else{
				break;
			}
			if(y<1)	y=1;
			if(h<y)	y=h;
			if(x<1)	x=1;
			if(w<x)	x=w;
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}

