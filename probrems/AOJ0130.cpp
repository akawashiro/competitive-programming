#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int time=0;time<n;time++){
		int level=0;
		string patrol;
		vector<pair<int,char> > train;
		cin>>patrol;
		for(int p=0;;){
			train.push_back(make_pair(level,patrol[p]));
			p++;
			if(p==patrol.size())
				break;
			if(patrol[p]=='<')
				level--;
			else
				level++;
			p+=2;
		}
		sort(train.begin(),train.end());
		train.erase(unique(train.begin(),train.end()),train.end());
		for(int i=0;i<(int)train.size();i++)
			cout<<train[i].second;
		cout<<endl;
	}
	return 0;
}

