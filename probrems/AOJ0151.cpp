//AOJ0151
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int DP[255][255];
int mv[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
int main(){
	while(1){
		int n;
		vector<string> grid;
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			grid.push_back(s);
		}
		int ans=0;
		for(int i=0;i<4;i++){
			memset(DP,0,sizeof(DP));
			for(int y=0;y<n;y++)
				for(int x=0;x<n;x++){
					int yy=y+mv[i][0],xx=x+mv[i][1];
					if(yy<0||n<=yy||xx<0||n<=xx)
						DP[y][x]=(grid[y][x]=='1')?1:0;
					else
						DP[y][x]=(grid[y][x]=='1')?DP[yy][xx]+1:0;
					ans=max(ans,DP[y][x]);
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}

		
