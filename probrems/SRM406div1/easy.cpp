#include <algorithm>
#include <vector>
using namespace std;

class SymmetricPie
{
	public:
		int getLines(vector <int> dogs)
		{
			int n=dogs.size();
			vector<int> order;
			for(int i=0;i<n;i++)
				order.push_back(i);
			int ans=0;

			do{
				vector<int> v(n);
				for(int i=0;i<n;i++)
					v[i]=dogs[order[i]];
				int r=0;
				bool isCenter=false;
				for(int i=0;i<n;i++)
					for(int j=i+1;j<n;j++)
					{
						int sum=0;
						for(int k=i;k<j;k++)
							sum+=v[k];
						if(sum==50)
							r++;
						if(i==0)
							isCenter=true;
					}
				if(isCenter)
					r--;
				ans=max(r,ans);
			}while(next_permutation(order.begin(),order.end()));

			return ans;
		}
};
