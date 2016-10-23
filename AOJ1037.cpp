#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int pos;
int table[20];

int stringToInt(string s)
{
	stringstream ss(s);
	int r;
	ss>>r;
	return r;
}

class Tree{
	public:
		int v;
		Tree *lc,*rc;
};

void parse(string s,Tree *t)
{
	if(s[pos]!='('){
		(*t).v=table[s[pos]-'0'];
		//cout<<"(*t).v="<<(*t).v<<endl;
		pos++;
	}else{
		(*t).v=-1;
		pos++;
		t->lc=new Tree;
		parse(s,(*t).lc);
		pos++;
		t->rc=new Tree;
		parse(s,(*t).rc);
		pos++;
	}
}

vector<int> calc(Tree *t)
{
	if(t->v!=-1){
		//cout<<"v="<<(*t).v<<endl;
		vector<int> res;
		res.push_back(t->v);
		/*for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
		cout<<endl;*/
		return res;
	}
	else{
		vector<int> vl=calc(t->lc);
		vector<int> vr=calc(t->rc);
		vector<int> res;
		for(int i=0;i<(int)vl.size();i++)
			for(int j=0;j<(int)vr.size();j++){
				res.push_back(vl[i]&vr[j]);
				res.push_back(vl[i]|vr[j]);
				res.push_back(vl[i]^vr[j]);
			}
		/*for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
		cout<<endl;*/
		return res;
	}
}

int main()
{
	while(1){
		int n;
		string s;
		Tree tree;
		while(s.size()<2)
			getline(cin,s);
		//cout<<s<<endl;
		if(s=="END")
			break;
		cin>>n;
		//cout<<n<<endl;
		for(int i=1;i<=n;i++){
			int a=0;
			for(int j=0;j<4;j++){
				int b;
				cin>>b;
				a=a*2+b;
			}
			table[i]=a;
			//cout<<a<<endl;
		}
		pos=0;
		parse(s,&tree);
		//cout<<"parse-end"<<endl;
		vector<int> v=calc(&tree);
		//cout<<"calc-end"<<endl;
		int ans=0;
		for(int i=0;i<(int)v.size();i++)
			if(v[i]==15)
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}

