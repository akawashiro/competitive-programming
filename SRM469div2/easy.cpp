#include <vector>
using namespace std;

class TheMoviesLevelOneDivTwo{
	public:
		int find(int n, int m, vector <int> row, vector <int> seat)
		{
			if(m==1)
				return 0;
			bool isReserved[50][50];
			for(int i=0;i<50;i++)
				for(int j=0;j<50;j++)
					isReserved[i][j]=false;
			for(int i=0;i<row.size();i++)
				isReserved[row[i]][seat[i]]=true;
			int count=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<m;j++)
					if(!isReserved[i][j] && !isReserved[i][j+1])
						count++;
			return count;
		}
};
