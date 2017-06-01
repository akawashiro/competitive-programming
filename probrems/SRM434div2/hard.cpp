#include <string>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int c2i(char c)
{
	return (c<='9') ? c-'0' : c-'A'+10;
}

char i2c(int i)
{
	return (i<=9) ? (char)(i+'0') : (char)(i-10+'A');
}

string add(string a,string b)
{
	string r(60,0);
	int carry=0;
	for(int i=59;0<=i;i--)
	{
		int cur=a[i]+b[i]+carry;
		carry=cur/36;
		cur%=36;
		r[i]=cur;
	}

	return r;
}

class HexatridecimalSum
{
	public:
		string maximizeSum(vector<string> s_numbers,int p)
		{
			for(int i=0;i<s_numbers.size();i++)
				for(int j=0;j<s_numbers[i].size();j++)
					s_numbers[i][j]=c2i(s_numbers[i][j]);

			vector<string> numbers=s_numbers;
			int n=numbers.size();
			for(int i=0;i<n;i++)
			{
				int m=numbers[i].size();
				numbers[i]=string(60-m,0)+numbers[i];
			}
			
			vector<pair<string,int> > weight(36);
			for(int i=0;i<36;i++)
			{
				vector<string> tmp=s_numbers;
				for(int j=0;j<n;j++)
					for(int k=0;k<(int)tmp[j].size();k++)
						if(tmp[j][k]==i)
							tmp[j][k]=35;
				string s(60,0);
				for(int j=0;j<n;j++)
				{
					string t=string(60-tmp[j].size(),0)+tmp[j];
					s=add(s,t);
				}
				weight[i].first=s;
				weight[i].second=i;
			}

			sort(weight.begin(),weight.end());
			reverse(weight.begin(),weight.end());
			
			vector<string> tmp=s_numbers;
			for(int i=0;i<p;i++)
			{
				char c=weight[i].second;
				for(int j=0;j<n;j++)
				{
					for(int l=0;l<(int)tmp[j].size();l++)
						if(tmp[j][l]==c)
							tmp[j][l]=35;
				}
			}
			for(int i=0;i<n;i++)
				numbers[i]=string(60-tmp[i].size(),0)+tmp[i];
			
			string s(60,0);
			for(int i=0;i<n;i++)
				s=add(s,numbers[i]);
			int i=0;
			while(s[i]==0)
				i++;
			string ans;
			while(i<60)
			{
				ans+=i2c(s[i]);
				i++;
			}
			if(ans=="")
				ans="0";

			return ans;
		}
};

