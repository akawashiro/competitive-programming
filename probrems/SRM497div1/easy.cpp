#include <string>
#include <vector>

using namespace std;

class PermutationSignature
{
	public:

		vector <int> reconstruct(string signature)
		{
			int n=signature.size();
			vector<int> ans(n+1);
			for(int i=1;i<=n+1;i++)
				ans[i-1]=i;

			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(signature[j]=='I' && ans[j]>ans[j+1])
						swap(ans[j],ans[j+1]);
					if(signature[j]=='D' && ans[j]<ans[j+1])
						swap(ans[j],ans[j+1]);
				}

			for(int i=0;i<n;i++)
			{
					if(signature[j]=='I' && ans[j]>ans[j+1])
						ans=vector<int>(0);
					if(signature[j]=='D' && ans[j]<ans[j+1])
						ans=vector<int>(0);
			}

			return ans;
		}
};

