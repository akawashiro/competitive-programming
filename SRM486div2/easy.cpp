#include <string>
#include <sstream>
using namespace std;

class TxMsg{
		public:
				string getMessage(string original);
};

bool isvocal(char c)
{
		if(c=='a' || c=='e' || c=='i' || c== 'o' || c=='u')
				return true;
		else
				return false;
}

bool isonlyvocal(string s)
{
		for(int i=0;i<s.size();i++)
				if(!isvocal(s[i]))
						return false;
		return true;
}

string TxMsg::getMessage(string original)
{
		stringstream ss(original);
		string ans;
		string word;
		while(ss >> word){
				string r;
				if(isonlyvocal(word)){
						ans+=" ";
						ans+=word;
						continue;
				}
				bool iscons=false;
				for(int i=0;i<word.size();i++){
						if(isvocal(word[i])){
								iscons=false;
						}else if(!isvocal(word[i]) && !iscons){
								r+=word[i];
								iscons=true;
						}
				}
				ans+=" ";
				ans+=r;
		}
		return ans.substr(1);
}
