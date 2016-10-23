//AOJ0029
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	string freq,len;
	map<string,int> ma;
	string s;
	while(cin>>s){
		ma[s]++;
		if(len.size()<s.size())
			len=s;
	}
	int f=0;
	for(map<string,int>::iterator it=ma.begin();it!=ma.end();it++)
		if(f<(*it).second)
			f=(*it).second,freq=(*it).first;
	cout<<freq<<" "<<len<<endl;
	return 0;
}

