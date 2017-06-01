#include <algorithm>
#include <vector>

using namespace std;

class TrueStatements
{
	public:
		int numberTrue(vector <int> st)
		{
			int ans=-1;
			sort(st.begin(),st.end());
			if(st[0]!=0)
				ans=0;
			
			for(int i=0;i<(int)st.size();i++)
				if( st[i] == (int)distance(lower_bound(st.begin(),st.end(),st[i]),
							upper_bound(st.begin(),st.end(),st[i])) )
					ans=max(ans,st[i]);
			return ans;
		}
};
