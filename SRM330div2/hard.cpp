#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class NextPalindromicNumber
{
	public:

		string getNext(string num)
		{
			int n=num.size();
			if(count(num.begin(),num.end(),'9')==n)
				return "1"+string(n-1,'0')+"1";

			string ans(n,'#');
			for(int i=n-1;0<=i;i--)
				ans[i]=ans[n-1-i]=num[i];
			if(ans<=num)
			{
				bool b=true;
				for(int i=(n-1)/2;0<=i;i--)
					if(b)
					{
						if(ans[i]<'9')
						{
							ans[i]++;
							ans[n-1-i]=ans[i];
							b=false;
						}
						else
							ans[n-1-i]=ans[i]='0';
					}
			}
			return ans;
		}
};

