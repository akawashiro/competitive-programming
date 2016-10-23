#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define SZ(i) ((int)i.size())

int main(){
     int N;
     string name;
     vector<string> boards;
     cin>>N>>name;
     for(int i=0;i<N;i++){
	  string s;
	  cin>>s;
	  boards.push_back(s);
     }
//     cout<<SZ(name)<<endl;
     int ans=0;
     for(int i=0;i<N;i++)
	  for(int s=0;s<SZ(boards[i]);s++)
	       for(int o=1;o<SZ(boards[i]);o++)
		    if(s+o*(SZ(name)-1)<SZ(boards[i])){
			 int j;
			 for(j=0;j<SZ(name);j++)
			      if(boards[i][s+o*j]!=name[j])
				   break;
			 if(j==SZ(name)){
			      ans++;
			      s=SZ(boards[i]);
			      o=SZ(boards[i]);
			 }
		    }
     cout<<ans<<endl;
     return 0;
}
       
  
