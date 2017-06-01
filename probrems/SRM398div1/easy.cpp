#include <vector>
#include <algorithm>
using namespace std;

class CountExpressions
{
	public:
		int calcExpressions(int x, int y, int val)
		{
			vector<int> nums;
			nums.push_back(x);
			nums.push_back(x);
			nums.push_back(y);
			nums.push_back(y);
			sort(nums.begin(),nums.end());

			int ans=0;
			do{
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						for(int k=0;k<3;k++)
						{
							int p=nums[0];

							if(i==0)	p+=nums[1];
							if(i==1)	p-=nums[1];
							if(i==2)	p*=nums[1];

							if(j==0)	p+=nums[2];
							if(j==1)	p-=nums[2];
							if(j==2)	p*=nums[2];
							
							if(k==0)	p+=nums[3];
							if(k==1)	p-=nums[3];
							if(k==2)	p*=nums[3];

							if(p==val)
								ans++;
						}
			}while(next_permutation(nums.begin(),nums.end()));

			return ans;
		}
};

