#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>
#define SE second
using namespace std;

int pb;
string buf;
vector<pair<string,vector<int> > > GUI;
vector<int> child;

void rec()
{
	string name,tmp;
	vector<int> a(4);
	pb++;
	while(buf[pb]!='>')
		name+=buf[pb],pb++;
	pb++;
	for(int i=0;i<4;i++){
		while(buf[pb]!=',' && buf[pb]!='<')
			tmp+=buf[pb],pb++;
		a[i]=atoi(tmp.c_str());
		tmp="";
		pb++;
	}
	pb--;
	int c=0;
	for(c=0;buf[pb+1]!='/';c++){
		rec();
	}
	child.push_back(c);
	pb+=2+name.size()+1;
	GUI.push_back(make_pair(name,a));
}

int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		pb=0;
		buf="";
		GUI.clear();
		child.clear();
		cin>>buf;
		rec();
		for(int i=0;i<n;i++){
			int x,y;
			string s;
			cin>>x>>y;
			int j;
			for(j=0;j<(int)GUI.size();j++)
				if(GUI[j].second[0]<=x && GUI[j].second[1]<=y &&
						x<=GUI[j].second[2] && y<=GUI[j].second[3]){
					s=GUI[j].first;
					break;
				}
			if(s=="")
				cout<<"OUT OF MAIN PANEL 1"<<endl;
			else
				cout<<s<<" "<<child[j]<<endl;
		}
	}
	return 0;
}

