#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int ans=0;

class DIRECTORY
{
	public:

		string name;
		vector<DIRECTORY> children;

		DIRECTORY(string s)
		{
			name=s;
		}

		void mkdir(vector<string> list,int p)
		{
			if(p==(int)list.size())
				return;
			int i,n=children.size();
			for(i=0;i<n;i++)
				if(children[i].name==list[p])
				{
					children[i].mkdir(list,p+1);
					break;
				}
			if(i==n)
			{
				ans++;
				//cout << list[p] << endl;
				DIRECTORY d(list[p]);
				children.push_back(d);
				children[i].mkdir(list,p+1);
			}
			return;
		}
};

void solve(int T)
{
	ans=0;
	DIRECTORY root("/");
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n+m;i++)
	{
		string s;
		cin >> s;
		for(int j=0;j<(int)s.size();j++)
			if(s[j]=='/')
				s[j]=' ';
		stringstream ss(s);
		vector<string> vs;
		//vs.push_back("/");
		while(ss >> s)
			vs.push_back(s);

		//cout << endl;
		//for(int j=0;j<vs.size();j++)
			//cout << vs[j] << " ";
		//cout << endl;
		
		root.mkdir(vs,0);
		if(i<n)
			ans=0;
		//cout << "ans=" << ans << endl;
	}
	printf("Case #%d: %d\n",T,ans);
	return;
}

int main()
{
	int TT;
	cin >> TT;
	for(int i=0;i<TT;i++)
		solve(i+1);
	return 0;
}

