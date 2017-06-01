#include <string>
#include <cstdio>
#include<iostream>
#include <vector>

using namespace std;


void solve(int pNum)
{
	int comb[30][30];
	for(int i=0;i<30;i++)
		for(int j=0;j<30;j++)
			comb[i][j]=100;
	int combSize;
	cin >> combSize;
	for(int i=0;i<combSize;i++)
	{
		string s;
		cin >> s;

		comb[s[0]-'A'][s[1]-'A']=comb[s[1]-'A'][s[0]-'A']=s[2]-'A';
	}

	int opponent[30][30];
	for(int i=0;i<30;i++)
		for(int j=0;j<30;j++)
			opponent[i][j]=0;
	int opponentSize;
	cin >> opponentSize;
	for(int i=0;i<opponentSize;i++)
	{
		string s;
		cin >> s;
		opponent[s[0]-'A'][s[1]-'A']=opponent[s[1]-'A'][s[0]-'A']=1;
	}

	string ans;
	int inputSize;
	cin >> inputSize;
	string input;
	cin >> input;
	for(int c=0;c<inputSize;c++)
	{
		if(0==ans.size())
			ans+=input[c];
		else
		{
			ans+=input[c];
			while(1<ans.size())
			{
				int s=ans.size();
				int a=comb[ans[s-2]-'A'][ans[s-1]-'A'];
				if(a!=100)
					ans=ans.substr(0,s-2)+char(a+'A');
				else
					break;
			}
			for(int i=0;i<ans.size();i++)
				for(int j=0;j<ans.size();j++)
					if(opponent[ans[i]-'A'][ans[j]-'A'])
						ans="";
		}

		//cout << ans << endl;
	}

	printf("Case #%d: [",pNum);
	for(int i=0;i<ans.size();i++)
		if(i==0)
			printf("%c",ans[i]);
		else
			printf(", %c",ans[i]);
	printf("]\n");

	return;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		solve(i+1);
	return 0;
}

