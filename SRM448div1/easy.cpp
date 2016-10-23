//ACrushの写し
#include <vector>
#include <string>
using namespace std;

class TheBlackJackDivOne
{
	public:

		double f(vector<int> left,int score)
		{
			if(21<=score)
				return 0;
			int total=0;
			for(int i=0;i<12;i++)
				total+=left[i];
			for(int i=0;i<12;i++)
				if(left[i])
				{
					left[i]--;
					result+=f(score+i,left)*left[i];
					left[i]++;
				}
			return result/total+1.0;
		}

		double expected(vector <string> cards)
		{
			int score=0;
			vector<int> left(12,4);
			left[0]=0;
			left[1]=0;
			left[10]=16;
			for(int i=0;i<cards.size();i++)
			{
				char c=cards[i][0];
				int d=0;
				if(c=='T' || c=='J' || c=='Q' || c==K')
					d=10;
				else if(c=='A')
					d=11;
				else
					d=c-'0';
				left[d]--;
				score+=d;
			}
			return f(left,score);
		}
};
