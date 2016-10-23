#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;

class SolitaireSimulation
{
	public:
		int periodLength(vector <int> heaps)
		{
			sort(heaps.begin(),heaps.end());
			vector<vector<int> > se;
			while(1)
			{
				if(find(se.begin(),se.end(),heaps)!=se.end())
					return (int)distance(find(se.begin(),se.end(),heaps),se.end());
				se.push_back(heaps);
				vector<int> v;
				v.push_back(heaps.size());
				for(int i=0;i<heaps.size();i++)
					if(0<heaps[i]-1)
						v.push_back(heaps[i]-1);
				sort(v.begin(),v.end());
				heaps=v;
			}
			return -1;
		}
};
