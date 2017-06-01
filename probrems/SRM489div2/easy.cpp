#include <string>
#include <vector>
using namespace std;

class BadVocabulary
{
	public:
		int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary)
		{
			int ans=0;
			for(int i=0;i<vocabulary.size();i++)
			{
				string s=vocabulary[i];
				if(badPrefix.size()<=s.size() && s.substr(0,badPrefix.size())==badPrefix)
				{
					ans++;
					continue;
				}
				if(badSubstring.size()<=s.size())
				{
					for(int i=1;i+badSubstring.size()-1<s.size()-1;i++)
						if(s.substr(i,badSubstring.size()) == badSubstring){
							ans++;
							goto B;
						}
				}
				if(badSuffix.size()<=s.size() && s.substr(s.size()-badSuffix.size(),badSuffix.size())==badSuffix)
				{
					ans++;
					continue;
				}
B:;
			}
			return ans;
		}
};
