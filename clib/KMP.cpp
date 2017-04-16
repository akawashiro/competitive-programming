//sの中にtがいくつ含まれているかを表示する
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s,t;
	int ans=0;
	cin >> s;
	cin >> t;

	cout << endl;

	vector<int> next(t.size()+1);
	vector<int> pre(256,0);
	for(int i=0;i<(int)next.size();i++)
	{
		if(i==0 || i==(int)next.size()-1)
			next[i]=1;
		else
		{
			next[i]=i-pre[t[i]];
			pre[t[i]]=i;
		}
		cout << "next[" << i << "]= " << next[i] << endl;
	}

	for(int b=0;b+(int)t.size()<=(int)s.size();)
	{
		int i;
		for(i=b;i<b+(int)t.size();i++)
			if(s[i]!=t[i-b])
				break;
		if(i==b+(int)t.size())
			ans++;
		//printf("next[%d]=%d\n",i-b,next[i-b]);
		b+=next[i-b];
	}

	cout << ans << endl;
	return 0;
}

