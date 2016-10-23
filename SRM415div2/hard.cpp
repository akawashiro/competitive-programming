#include <set>
#include <vector>

using namespace std;

class CardsCheating
{
	public:
		int numberOfShuffles(vector <int> cards, vector <int> shuffle)
		{
			int n=cards.size();
			vector<int> real;
			for(int i=0;i<n;i++)
				real.push_back(i);

			int ans=0;
			set<vector<int> > se;

			while(1)
			{
				bool isEnd=true;
				for(int i=0;i<n;i++)
					if(cards[real[i]]!=i%3)
					{
						isEnd=false;
						break;
					}
				if(isEnd)
					return ans;

				if(se.insert(real).first==false)
					return -1;

				vector<int> v(n);
				for(int i=0;i<n;i++)
					v[shuffle[i]]=real[i];
				real=v;
				ans++;
			}

			return -1;
		}
};

