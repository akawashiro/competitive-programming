#include <vector>
#include <string>
#include <set>
using namespace std;

class RouteIntersection{
	public:
		string isValid(int N, vector <int> coords, string moves)
		{
			set<int> table;
			for(int i=0;i<coords.size();i++)
				table.insert(coords[i]);
			for(int i=0;i<coords.size();i++)
				coords[i]=distance(table.begin(),table.find(coords[i]) );

			N=table.size();
			int nMove=moves.size();
			printf("N=%d nMove=%d\n",N,nMove);
			int position[nMove+1][N];
			for(int i=0;i<nMove+1;i++)
				for(int j=0;j<N;j++)
					position[i][j]=0;

			for(int i=1;i<nMove+1;i++){
				for(int j=0;j<N;j++)
					position[i][j]=position[i-1][j];
				position[i][coords[i-1]]+=(moves[i-1]=='+') ? 1 : -1;
			}
			
			for(int i=0;i<nMove+1;i++){
				for(int j=0;j<N;j++)
					printf("%d ",position[i][j]);
				printf("\n");
			}
			
			for(int i=0;i<nMove+1;i++){
				for(int j=0;j<nMove+1;j++){
					if(i==j)
						continue;
					bool isSame=true;

					for(int k=0;k<N;k++)
						if(position[i][k]!=position[j][k]){
							isSame=false;
							break;
						}

					if(isSame)
						return "NOT VALID";
				}
			}

			return "VALID";
		}
};
