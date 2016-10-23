#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class ProbabilisticTranslator
{
	public:

		int n;
		map<pair<int,string>,int> cache;
		vector<string> text;
		map<string,vector<string> > dictionary;
		map<string,int> frequencies;

		int freq(string b,string f)
		{
			//printf("freq-s\n");
			
			int r=0;
			if(frequencies.find(b+" "+f)!=frequencies.end())
				r=frequencies[b+" "+f];
			
			//printf("freq-e\n");	
			return r;
		}

		int rec(int time,string before)
		{
			//printf("rec-s\n");
			
			int r;
			pair<int,string> p=make_pair(time,before);
			if(cache.find(p)!=cache.end())
			{
				r=cache[p];
			}
			else
			{
				if(time==n)
				{
					r=0;
				}
				else
				{
					//printf("rec1-s\n");
					vector<string> v=dictionary[text[time]];
					//printf("rec1-2\n");
					
					r=0;
					string now;
					for(int j=0;j<v.size();j++)
					{
						now=v[j];
						r=max(r,freq(before,now)+rec(time+1,now));
					}
					
					//printf("rec1-e\n");
				}
			}
			
			//printf("rec-e\n");

			return cache[p]=r;
		}

		int maximumFidelity(vector<string> _txt,vector<string> _dict,vector<string> _freq)
		{
			for(int i=0;i<_txt.size();i++)
			{
				stringstream ss(_txt[i]);
				string s;
				while(ss >> s)
					text.push_back(s);
			}
			n=text.size();

			for(int i=0;i<_dict.size();i++)
			{
				stringstream ss(_dict[i]);
				string s,t;
				ss >> s;
				ss >> t;
				while(ss >> t)
					dictionary[s].push_back(t);
			}

			for(int i=0;i<_freq.size();i++)
			{
				stringstream ss(_freq[i]);
				string s,t;
				int a;
				ss >> s >> t;
				ss >> a;
				frequencies[s+" "+t]=a;
			}

			return rec(0,"###");
		}
};

