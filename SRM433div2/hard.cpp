#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

typedef long long LL;
using namespace std;

class MakingPotions
{
	public:
		int getCost(vector <string> marketGoods, vector <int> cost, vector <string> recipes)
		{
			int n=recipes.size();
			map<string,LL> ans;
			vector<string> result(n);
			vector<vector<string> > ingredient(n,vector<string>(0));
			vector<vector<LL> > amount(n,vector<LL>(0));

			for(int i=0;i<(int)marketGoods.size();i++)
				ans[marketGoods[i]]=cost[i];
				
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<recipes[i].size();j++)
				{
					char c=recipes[i][j];
					recipes[i][j]=(c=='=' || c=='+')?' ':c;
				}
				string s;
				int a;
				stringstream ss(recipes[i]);
				ss >> result[i];
				
				cout << result[i];
				
				while(ss >> a >> s)
				{
					cout << " " <<  a << " " << s;
					
					amount[i].push_back(a);
					ingredient[i].push_back(s);
				}
				
				cout << endl;
			}

			for(int time=0;time<n;time++)
				for(int i=0;i<n;i++)
				{
					bool b=true;
					for(int j=0;j<(int)ingredient[i].size();j++)
						if(ans.find(ingredient[i][j])==ans.end())
							b=false;
					if(!b)
						continue;
					LL a=0;
					for(int j=0;j<(int)ingredient[i].size();j++)
						a=min((LL)1000000001,a+amount[i][j]*ans[ingredient[i][j]]);
					if(ans.find(result[i])!=ans.end())
						ans[result[i]]=min(ans[result[i]],a);
					else
						ans[result[i]]=min((LL)1000000001,a);
						
					cout << "a=" << a << endl;
				}

			return (int)(ans.find("LOVE")!=ans.end())?ans["LOVE"]:-1;
		}
};

