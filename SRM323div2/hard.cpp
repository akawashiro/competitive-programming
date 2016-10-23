#include <string>
#include <vector>
#include <cstring>

using namespace std;

class UnrepeatableWords
{
	public:

		int k,n,allowed;

		string rec(string before)
		{
			if(before.size()==n)
				return "";

			bool NG[allowed];
			memset(NG,false,sizeof(NG));

			for(int len=1;k*len-1<=before.size();len++)
			{
				int pos=before.size()-len*k+1;
				string s=before.substr(pos,len);
				int i;
				for(i=0;i<k-1;i++)
					if(s!=before.substr(pos+i*len,len))
						break;
				if(i==k-1 && s.substr(0,len-1)==before.substr(pos+len*(k-1),len-1))
					NG[s[len-1]-'A']=true;
			}

			for(int i=0;i<allowed;i++)
				if(!NG[i])
				{
					string s;
					char c=i+'A';
					s=c+rec(before+c);
					if(s.size()==n-before.size())
						return s;
				}
			return "";
		}

		string getWord(int _k, int _n, int _allowed)
		{
			k=_k,n=_n,allowed=_allowed;

			return rec("");
		}
};

