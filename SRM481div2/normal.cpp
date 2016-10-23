#include <string>
using namespace std;

class ChickenOracle{
		public:
				string theTruth(int n, int eggCount, int lieCount, 
								int liarCount);
};

string ChickenOracle::theTruth(int n, int eggCount, 
				int lieCount, int liarCount)
{
		int maxLie=lieCount+liarCount;
		int minLie=lieCount-liarCount;
		if(minLie<0)
				minLie*=-1;
		int chickenCount=n-eggCount;
		string ans="The oracle is a lie";
		if(minLie<=eggCount && eggCount<=maxLie)
				ans="The chicken";
		if(minLie<=chickenCount && chickenCount<=maxLie)
				ans="The egg";
		if(minLie<=eggCount && eggCount<=maxLie &&
				minLie<=chickenCount && chickenCount<=maxLie)
				ans="Ambiguous";
		return ans;
}

