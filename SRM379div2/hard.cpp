#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TVGameWinnings
{
	public:

		int n;
		vector<string> board;

		int cycleNumber(vector<int> y,vector<int> x)
		{
			vector<bool> isUsed(n,false);
			int r=0;

			for(int i=0;i<n;i++)
			{
				if(isUsed[i])
					continue;
				
				r++;
				int pos=i;
				while(!isUsed[pos])
				{
					isUsed[pos]=true;
					int a=x[pos];
					for(int j=0;j<n;j++)
						if(y[j]==a)
						{
							pos=j;
							break;
						}
				}
			}

			return r;
		}

		int getPoint(vector<int> y,vector<int> x)
		{
			int r=1;
			for(int i=0;i<n;i++)
			{
				int c=board[y[i]][x[i]];
				if('0'<=c && c<='9')
				{
					c-='0';
				}
				else if('A'<=c && c<='I')
				{
					c-='A';
					c+=1;
					c=-c;
				}
				r*=c;
			}

			if(cycleNumber(y,x)%2==0)
				r=-r;

			return r;
		}

		vector <int> getMinMax(vector<string> _board)
		{
			board=_board;
			n=board.size();

			vector<int> y;
			vector<int> x;
			for(int i=0;i<n;i++)
				y.push_back(i),x.push_back(i);

			vector<int> ans(2);
			ans[0]=(1<<28),ans[1]=-(1<<28);
			
			do{
				int a=getPoint(y,x);
				ans[0]=min(ans[0],a);
				ans[1]=max(ans[1],a);
			}while(next_permutation(x.begin(),x.end()));

			return ans;
		}
};

