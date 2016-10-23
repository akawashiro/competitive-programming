#include <vector>
using namespace std;

class NumberNeighbours{
	public:
		int numPairs(vector <int> numbers)
		{
			int ans=0;
			int n=numbers.size();
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					int nd1[10],nd2[10],d1=numbers[i],d2=numbers[j];
					for(int k=0;k<10;k++){
						nd1[k]=0;
						nd2[k]=0;
					}
					for(int k=0;k<10;k++){
						nd1[d1%10]++;
						nd2[d2%10]++;
						d1=(d1==0) ? 0 : d1/10;
						d2=(d2==0) ? 0 : d2/10;
					}
					ans++;
					for(int k=1;k<10;k++){
						if(nd1[k]!=nd2[k]){
							ans--;
							break;
						}
					}
				}
			}
			return ans;
		}
};
