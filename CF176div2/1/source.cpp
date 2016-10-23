#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(vector<string> &vs){
     for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	       if(vs[i][j]==vs[i+1][j]&&vs[i][j]==vs[i][j+1]&&vs[i][j]==vs[i+1][j+1])
		    return true;
     return false;
}

char opposite(char c){
     if(c=='#')return '.';
     else return '#';
}

int main(){
     vector<string> vs;
     for(int i=0;i<4;i++){
	  string s;
	  cin>>s;
	  vs.push_back(s);
     }
     string ans="NO";
     if(check(vs))
	  ans="YES";
     for(int i=0;i<4;i++)
	  for(int j=0;j<4;j++){
	       vs[i][j]=opposite(vs[i][j]);
	       if(check(vs))
		    ans="YES";
	       vs[i][j]=opposite(vs[i][j]);
	  }
     cout<<ans<<endl;
     return 0;
}
