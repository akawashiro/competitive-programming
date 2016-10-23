//AOJ1121
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int ans[38][38];
int main(){
	map<string,int> s2i;
	map<int,string> i2s;
	for(int i=0;i<26;i++)
		s2i[string(1,'a'+i)]=i;
	s2i["ld"]=26;s2i["mb"]=27;s2i["mp"]=28;s2i["nc"]=29;s2i["nd"]=30;
	s2i["ng"]=31;s2i["nt"]=32;s2i["nw"]=33;s2i["ps"]=34;s2i["qu"]=35;
	s2i["cw"]=36;s2i["ts"]=37;
	for(int i=0;i<26;i++)
		i2s[i]=string(1,'a'+i);
	i2s[26]="ld";i2s[27]="mb";i2s[28]="mp";i2s[29]="nc";i2s[30]="nd";
	i2s[31]="ng";i2s[32]="nt";i2s[33]="nw";i2s[34]="ps";i2s[35]="qu";
	i2s[36]="cw";i2s[37]="ts";
	int n;
	string s;
	cin>>n;
	while(cin>>s){
		int m=s.size();
		vector<int> vi;
		int i=0;
		while(i<m)
			if(i<m-1&&s2i.find(s.substr(i,2))!=s2i.end())
				vi.push_back(s2i[s.substr(i,2)]),i+=2;
			else
				vi.push_back(s2i[s.substr(i,1)]),i++;
		for(int i=0;i<(int)vi.size()-1;i++)
			ans[vi[i]][vi[i+1]]++;
	}
	for(int i=0;i<38;i++){
		int v=0,m=0;
		for(int j=0;j<38;j++)
			if(m<ans[i][j])
				v=j,m=ans[i][j];
		cout<<i2s[i]<<" "<<i2s[v]<<" "<<m<<endl;
	}
	return 0;
}

