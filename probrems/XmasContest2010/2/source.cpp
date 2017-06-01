#include <string>
#include <iostream>
using namespace std;

string judge(string expr)
{
	string ans="EVEN";
	int n=expr.size();
	for(int i=n-1;0<=i;i--)
	{
		char c=expr[i];
		if(i==n-1 && '0'<=c && c<='9')
		{
			if((c-'0')%2==1)
				ans=(ans=="EVEN") ? "ODD" : "EVEN";
		}
		else
		{
			char d=expr[i+1];
			if(!('0'<=d && d<='9') && '0'<=c && c<='9')
			{
				if((c-'0')%2==1)
					ans=(ans=="EVEN") ? "ODD" : "EVEN";
			}
		}
	}
	return ans;
}

int main()
{
	while(1)
	{
		string s;
		cin >> s;
		if(s=="#")
			break;
		cout << judge(s) << endl;
	}
	return 0;
}

