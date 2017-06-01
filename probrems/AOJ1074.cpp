#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main()
{
	while(1){
		int n;
		int point[40];
		vector<int> data[40];
		map<int,string> IDToName;
		cin>>n;
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			point[i]=0;
			string name;
			int m;
			cin>>name;
			IDToName[i]=name;
			cin>>m;
			for(int j=0;j<m;j++){
				int d;
				cin>>d;
				data[d].push_back(i);
			}
		}
		for(int i=0;i<40;i++)
			for(int j=0;j<(int)data[i].size();j++)
				point[data[i][j]]+=n+1-data[i].size();
		int worstPoint=100000;
		string worstName;
		for(int i=0;i<n;i++)
			if(point[i]<worstPoint || (point[i]==worstPoint && IDToName[i]<worstName)){
				worstPoint=point[i];
				worstName=IDToName[i];
			}
		cout<<worstPoint<<" "<<worstName<<endl;
	}
	return 0;
}
