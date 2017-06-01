#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mv[4][2]={{1,0},{0,1},{1,-1},{-1,-1}};
int main(){
	while(1){
		string s;
		vector<string> vs;
		for(int i=0;i<3;i++){
			cin>>s;
			if(s=="0")
				return 0;
			vs.push_back(s);
		}
		string ans="NA";
		for(int sy=0;sy<3;sy++)
			for(int sx=0;sx<3;sx++){
				for(int m=0;m<4;m++){
					int i;
					for(i=0;i<3;i++){
						int yy=sy+mv[m][0]*i;
						int xx=sx+mv[m][1]*i;
						if(yy<0||3<=yy||xx<0||3<=xx||vs[yy][xx]!='w')
							break;
					}
					if(i==3)
						ans="w";
					for(i=0;i<3;i++){
						int yy=sy+mv[m][0]*i;
						int xx=sx+mv[m][1]*i;
						if(yy<0||3<=yy||xx<0||3<=xx||vs[yy][xx]!='b')
							break;
					}
					if(i==3)
						ans="b";
				}
			}
		cout<<ans<<endl;
	}
}

