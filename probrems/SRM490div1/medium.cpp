#include <vector>
#include <string>
#include <map>
#include <set>
#include <stream>

using namespace std;

vector<string> dic;
vector<string> digit;
map<string,int> type;

void BT(string D)
{
	int l=(int)D.size();

	set<string> U;
	for(int i=0;i<(int)dic.size();i++)
		if(digit[i].size() >= D.size() && digit[i].substr(0,l)==D)
			U.insert(dic[i].substr(0,l));

	int c=0;
	for(set<string>::iterator u=U.begin();u!=U.end();u++,c++)
		for(int i=1;i<=l;i++)
		{
			string s=u->substr(0,i);
			int t= i==l ? l+c+1 : l+c+(l-i);
			if(type.count(s)==0 || t<type[s])
				type[s]=t;
		}

	if(0<U.size())
		for(int i=2;i<9;i++)
			BT(D+char('0'+i));
}

class QuickT9
{
	public:
		int minimumPressings( vector <string> t9, string word )
		{
			dic.clear();
			for(int i=0;i<(int)t9.size();i++)
			{
				stringstream ss(t9[i]);
				string d;
				while(ss >> d)
					dic.push_back(d);
			}

			int button[26]={ 2,2,2, 3,3,3, 4,4,4, 5,5,5,
				6,6,6, 7,7,7,7, 8,8,8, 9,9,9,9 };

			digit.clear();
			for(int i=0;i<(int)dic.size();i++)
			{
				digit.push_back("");
				for(int j=0;j<(int)dic.size();j++)
					digit.back+=char('0'+button[dic[i][j]-'a']);
			}

			type.clear();
			for(int i=2;i<9;i++)
				BT(string(1,'0'+i));

			int n=word.size();
			vector<int> T(n+1,(1<<30));
			T[0]=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<i;j++)
				{
					string s=word.substr(j,i-j);
					if(type.count(s) > 0)
						T[i]=min(T[i],T[j]+type[s]);
				}

			return T[n]<(1<<30) ? T[n] : -1;
		}
};

