//compreted
#include <vector>
#include <string>
using namespace std;

class TheBasketballDivTwo{
	public:
		vector<string> table;
		int n;
		int ans;

		void DFS(int index)
		{
			if(index==n*n)
			{
				int a=0,b=0;
				for(int i=0;i<n;i++){
					a=0;
					for(int j=0;j<n;j++)
					{
						if(table[i][j]=='W')	a++;
						if(table[j][i]=='L')	a++;
					}
					b=max(a,b);
				}
				ans=min(b,ans);
			}
			
			else{ 
				if(table[index/n][index%n]=='?')
				{
					table[index/n][index%n]='W';
					DFS(index+1);
					table[index/n][index%n]='L';
					DFS(index+1);
					table[index/n][index%n]='?';
				}
				else
					DFS(index+1);
			}
		}

		int find(vector <string> tempTable)
		{
			table=tempTable;
			n=table.size();
			DFS(0);
			return ans;
		}
};
