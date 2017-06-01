#include <vector>
#include <string>
using namespace std;

class SpidersOnTheGrid{
	public:
		int find(vector <string> A)
		{
			int count=0;
			for(int i=0;i<A.size();i++)
				for(int j=0;j<A[0].size();j++){
					if(0<=i-1 && A[i-1][j]=='S')	continue;
					if(i+1<A.size() && A[i+1][j]=='N')	continue;
					if(0<=j-1 && A[i][j-1]=='E')	continue;
					if(j+1<A[0].size() && A[i][j+1]=='W')	continue;
					count++;
				}
			return count;
		}
};
