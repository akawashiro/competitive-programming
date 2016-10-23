#include <string>
#include <vector>

using namespace std;

class FloorIndicator
{
	public:

		vector<int> canDig(vector<string> dig,vector<string> ind,int pos)
		{
			vector<int> r;
			for(int n=0;n<10;n++)
			{
				bool b=true;
				for(int i=0;i<5;i++)
					for(int j=0;j<3;j++)
						if(ind[i][4*pos+j]=='#' && dig[i][4*n+j]=='.')
							b=false;
				if(b)
					r.push_back(n);
			}
			return r;
		}

		double averageFloor(int N, vector <string> indicator)
		{
			vector<string> digits;
			digits.push_back("###...#.###.###.#.#.###.###.###.###.###");
			digits.push_back("#.#...#...#...#.#.#.#...#.....#.#.#.#.#");
			digits.push_back("#.#...#.###.###.###.###.###...#.###.###");
			digits.push_back("#.#...#.#.....#...#...#.#.#...#.#.#...#");
			digits.push_back("###...#.###.###...#.###.###...#.###.###");

			double ans=0;
			for(int pos=1,t=1;pos<=N;pos++,t*=10)
			{
				vector<int> v=canDig(digits,indicator,N-pos);
				if(v.size()==0)
					return -1.0;

				double ave=0;
				for(int i=0;i<(int)v.size();i++)
					ave+=v[i];
				ave/=(double)v.size();

				ans+=ave*(double)t;
			}

			return ans;
		}
};


