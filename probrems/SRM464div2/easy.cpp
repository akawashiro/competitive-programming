#include <iostream>
using namespace std;

class ColorfulBoxesAndBalls{
	public:
		int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
		{
			int ans=numRed*onlyRed+numBlue*onlyBlue;
			if(numRed<=numBlue)
				ans=max(ans,numRed*2*bothColors+(numBlue-numRed)*onlyBlue);
			else 
				ans=max(ans,numBlue*2*bothColors+(numRed-numBlue)*onlyRed);
			return ans;
		}
};
