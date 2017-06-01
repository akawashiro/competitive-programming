#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class TheBoardingDivTwo
{
	public:
		int find(vector <int> pattern, int boardingTime)
		{
			int n=pattern.size();
			int ans=0;

			vector<int> order;
			for(int i=0;i<n;i++)
				order.push_back(i);

			do{
				for(int i=0;i<n;i++)
					if(pattern[i]!=-1 && pattern[i]-1!=order[i])
						goto LABEL;

				vector<int> seat(2*n,INT_MAX);
				for(int i=0;i<n;i++)
					seat[i]=order[i];

				int time;
				for(time=0;time<=boardingTime;time++)
				{
					int i;
					for(i=0;i<2*n;i++)
						if(seat[i]!=INT_MAX && seat[i]!=-1)
							break;
					if(i==2*n)
					{
						ans++;
						break;
					}

					for(i=2*n-1;0<=i;i--)
					{
						if(seat[i]<0)
						{
							seat[i]++;
							if(seat[i]==0)
								seat[i]=INT_MAX;
						}

						if(0<=seat[i] && seat[i]<n && seat[i+1]==INT_MAX)
						{
							seat[i+1]=seat[i];
							if(seat[i+1]+n==i+1)
								seat[i+1]=-75;
							seat[i]=INT_MAX;
						}
					}
				}

LABEL:;
			}while(next_permutation(order.begin(),order.end()));

			return ans;
		}
};

