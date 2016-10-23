#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MatrixGame{
	public:
		vector <string> getMinimal(vector <string> matrix)
		{
			int h=matrix.size();
			int w=matrix[0].size();
			vector<string> ans=matrix;
			vector<int> perm;
			for(int i=0;i<w;i++)
				perm.push_back(i);
			do{
				vector<string> t=matrix;
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						t[i][j]=matrix[i][perm[j]];
				sort(t.begin(),t.end());
				ans=min(ans,t);
			}while(next_permutation(perm.begin(),perm.end()));
			return ans;
		}
};
