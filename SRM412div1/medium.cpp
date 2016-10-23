#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringsAndTabs
{
	public:
		vector <string> transformTab(vector <string> tab, vector <int> stringsA, vector <int> stringsB, int d)	
		{
			int AsN=stringsA.size(),tLen=tab[0].size(),BsN=stringsB.size();
			vector<string> ans(BsN,string(tLen,'-'));

			for(int time=0;time<tLen;time++)
			{
				vector<int> pitch;
				for(int i=0;i<AsN;i++)
				{
					char c=tab[i][time];
					if(c!='-')
					{
						int a=stringsA[i]+(('0'<=c && c<='9')?c-'0':c-'A'+10)+d;
						pitch.push_back(a);
					}
				}
				sort(pitch.begin(),pitch.end());
				reverse(pitch.begin(),pitch.end());

				bool b=true;
				for(int i=0;i<pitch.size();i++)
				{
					int minOpen=50;
					int st=-1;
					for(int j=BsN-1;0<=j;j--)
						if(ans[j][time]=='-')
						{
							int o=pitch[i]-stringsB[j];
							if(0<=o && o<=35 && o<minOpen)
								minOpen=o,st=j;
						}
					if(st==-1)
					{
						b=false;
						break;
					}
					char c=(minOpen<10)?minOpen+'0':minOpen-10+'A';
					ans[st][time]=c;
				}
				if(!b)
					for(int i=0;i<BsN;i++)
						ans[i][time]='x';
			}
			return ans;
		}
};

					
