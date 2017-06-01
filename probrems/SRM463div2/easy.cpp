#include <vector>
#include <algorithm>
using namespace std;

class BunnyPuzzle{
	public:
		vector<int> bunnies;
		int n;

		bool isContain(int x,int y,int ex1,int ex2){
			for(int i=0;i<n;i++)
				if(min(x,y)<=bunnies[i] && bunnies[i]<=max(x,y) && i!=ex1 && i!=ex2)
					return true;
			return false;
		}

		int theCount(vector <int> tempbunnies)
		{
			bunnies=tempbunnies;
			n=bunnies.size();
			int cnt=0;
			sort(bunnies.begin(),bunnies.end());
			for(int i=1;i<n;i++){
				if(!isContain(2*bunnies[i]-bunnies[i-1],bunnies[i],i,i-1))
					cnt++;
				if(!isContain(2*bunnies[i-1]-bunnies[i],bunnies[i-1],i,i-1))
					cnt++;
			}
			return cnt;
		}

};
