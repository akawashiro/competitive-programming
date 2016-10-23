//AOJ0201
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
map<string,int> price;
map<string,vector<string> > recipe;
int p(string s)
{
	if(recipe.find(s)!=recipe.end()){
		int a=0;
		for(int i=0;i<(int)recipe[s].size();i++)
			a+=p(recipe[s][i]);
		if(price.find(s)!=price.end())
			price[s]=min(price[s],a);
		else
			price[s]=a;
	}
	return price[s];
}
int main()
{
	while(1){
		price.clear();
		recipe.clear();
		int n,m;
		string s;
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<n;i++){
			int a;
			cin>>s>>a;
			price[s]=a;
		}
		cin>>m;
		for(int i=0;i<m;i++){
			int a;
			string t;
			cin>>s;
			cin>>a;
			for(int j=0;j<a;j++){
				cin>>t;
				recipe[s].push_back(t);
			}
		}
		cin>>s;
		cout<<p(s)<<endl;
	}
	return 0;
}

