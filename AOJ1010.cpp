#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UNIONFIND
{
	vector<int> data;
	vector<int> scale;
	public:
	UNIONFIND(int n)
	{
		for(int i=0;i<n;i++)
		{
			data.push_back(i);
			scale.push_back(1);
		}
	}
	int root(int n)
	{
		if(data[n]==n)
			return n;
		else
			return data[n]=root(data[n]);
	}
	void set(int x,int y)
	{
		if(root(x)==root(y))
			return;
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		data[root(x)]=data[root(y)];
	}
	int size(int n)
	{
		return scale[root(n)];
	}
};

int main(){
	int n;
	while(cin>>n){
		vector<int> ar(7,0);
		UNIONFIND un(7);
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			int v=s[0]-'0',u=s[1]-'0';
			ar[v]++;ar[u]++;
			un.set(u,v);
		}
		int o=0;
		for(int i=0;i<7;i++)
			if(ar[i]%2==1)
				o++;
		int b=1;
		for(int i=0;i<7;i++)
			for(int j=0;j<7;j++)
				if(0<ar[i]&&0<ar[j]&&(un.root(i)!=un.root(j)))
					b=0;
		if(2<o||o==1||!b)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}

