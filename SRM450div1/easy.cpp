#include <vector>
#include <string>
using namespace std;

class OrderedNim
{
	public:
		string winner(vector <int> layout)
		{
			string ans="Alice";
			for(int i=layout.size()-2;0<=i;i--)
			{
				if(ans=="Alice" && layout[i]==1)
					ans="Bob";
				else
					ans="Alice";
			}
			return ans;
		}
};
