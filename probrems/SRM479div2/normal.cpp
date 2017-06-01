#include <vector>
#include <algorithm>
using namespace std;

class TheCoffeeTimeDivTwo{
		public:
				int find(int n, vector <int> tea);
};

int TheCoffeeTimeDivTwo::find(int n, vector <int> tea)
{
				int time=n*4;
				sort(tea.begin(),tea.end());
				int left=tea.size();
				for(left;7<left;left-=7)
								time+=(47+tea[left-1]*2);
				time+=(47+tea[left-1]*2);
				vector<int> coffee;
				for(int i=1;i<=n;i++)
								if(tea.end()==std::find(tea.begin(),tea.end(),i))
												coffee.push_back(i);
				if(coffee.size()==0)
								return time;
				left=coffee.size();
				for(left;7<left;left-=7)
								time+=(47+coffee[left-1]*2);
				time+=(47+coffee[left-1]*2);
				return time;
}	

