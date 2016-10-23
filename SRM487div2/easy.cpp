#include <string>
using namespace std;

class BunnyExamAfter{
	public:
		int getMaximum(string black, string gray, string white)
		{
			int count=0;
			for(int i=0;i<black.size();i++){
				if(black[i]!=gray[i] && gray[i]==white[i])
					count+=2;
				else if(black[i]!=gray[i])
					count++;
				else if(black[i]!=white[i])
					count++;
			}
			return count;
		}
};
