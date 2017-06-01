#include <string>
using namespace std;

class AppleWord{
	public:
		int minRep(string word)
		{
			if(word.size()<5)
				return -1;

			int dif=0;
			if(!(word[0]=='a' || word[0]=='A'))
				dif++;
			for(int i=1;i<word.size()-2;i++)
				if(!(word[i]=='p' || word[i]=='P'))
					dif++;
			if(!(word[word.size()-2]=='l' || word[word.size()-2]=='L'))
				dif++;
			if(!(word[word.size()-1]=='e' || word[word.size()-1]=='E'))
				dif++;
			return dif;
		}
};
