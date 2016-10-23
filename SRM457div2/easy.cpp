#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TheSquareDivTwo{
	public:
		vector <string> solve(vector <string> board)
		{
			vector<int> R;
			int n=board.size();
			for(int i=0;i<n;i++)
				R.push_back(count(board[i].begin(),board[i].end(),'C'));
			for(int i=0;i<n;i++)
				for(int j=n-1;0<=j;j--){
					if(0<R[i]){
						board[j][i]='C';
						R[i]--;
					}else{
						board[j][i]='.';
					}
				}
			return board;
		}
};
