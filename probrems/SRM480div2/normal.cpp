#include <list>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class InternetSecurity{
		public:
				vector <string> determineWebsite(vector <string> address,
							   	vector <string> keyword, 
								vector <string> dangerous, int threshold);
};

vector<string> InternetSecurity::determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold)
{
		vector<string> ans;
		vector<list<string> > keylist;
		bool isadded[(int)address.size()];
		for(int i=0;i<address.size();i++)
				isadded[i]=false;
		for(int i=0;i<(int)keyword.size();i++){
				list<string> k;
				int b=0;
				for(int e=0;e<(int)keyword[i].size();e++)
						if(keyword[i][e]==' '){
								k.push_back(keyword[i].substr(b,e-b));
								b=e+1;
								e=b+1;
						}
				k.push_back(keyword[i].substr(b,keyword[i].size()-b));
				keylist.push_back(k);
		}
		for(int k=0;k<(int)address.size();k++){
				for(int i=0;i<(int)address.size();i++){
						int match=0;
						for(list<string>::iterator it=keylist[i].begin();it!=keylist[i].end();it++){
										for(int j=0;j<(int)dangerous.size();j++){
												if((*it)==dangerous[j]){
														match++;
														break;
												}
										}
						}
						//cout << address[i] << "---" << match << endl;
						if(threshold<=match && !isadded[i]){
								isadded[i]=true;
								ans.push_back(address[i]);
								for(list<string>::iterator it=keylist[i].begin();it!=keylist[i].end();it++)
										dangerous.push_back((*it));
						}
				}
		}
		return ans;
}

int main()
{
		vector <string> address;
		vector <string> keyword;
		vector <string> dangerous;
		string s;
		s="top";	address.push_back(s);
		s="evil";	address.push_back(s);
		s="hack top fan kop";	keyword.push_back(s);
		s="hack yong fan";	keyword.push_back(s);
		s="hack";		dangerous.push_back(s);
		s="fan";		dangerous.push_back(s);
		s="kop";		dangerous.push_back(s);
		InternetSecurity i;
		cout << i.determineWebsite(address,keyword,dangerous,2).size() << endl;
}
