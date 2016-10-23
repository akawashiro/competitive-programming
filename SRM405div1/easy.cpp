#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RelativePath
{
	public:
		string makeRelative(string path, string current)
		{
			vector<string> from,to;
			stringstream ss,st;
			string s;
			string ans;
			
			for(int i=0;i<path.size();i++)
				if(path[i]=='/')
					path[i]=' ';
			ss << path;
			while(ss >> s)
				to.push_back(s);
			
			for(int i=0;i<current.size();i++)
				if(current[i]=='/')
					current[i]=' ';

			st << current;
			while(st >> s)
				from.push_back(s);
				
			for(int i=0;i<from.size();i++)
				cout << from[i] << endl;
			for(int i=0;i<to.size();i++)
				cout << to[i] << endl;

			int index=0;
			for(index=0;index<min(to.size(),from.size());index++)
				if(to[index]!=from[index])
					break;
			
			printf("%d\n",index);
			
			for(int i=index;i<from.size();i++)
				ans+=".. ";
			for(int i=index;i<to.size();i++)
			{
				ans+=to[i];
				if(i!=to.size()-1)
					ans+=" ";
			}
			for(int i=0;i<ans.size();i++)
				if(ans[i]==' ')
					ans[i]='/';

			return ans;
		}
};
