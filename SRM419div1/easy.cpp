#include <vector>
#include <sstream>
#include <utility>
using namespace std;

class Undo
{
	public:
		string getText(vector <string> commands, vector <int> time)
		{
			int n=commands.size();
			vector<pair<int,string> > state;
			state.push_back(make_pair(0,""));

			for(int index=0;index<n;index++)
			{
				stringstream ss;
				string s,t,u;
				ss << commands[index];
				ss >> s;
				if(s=="type")
				{
					ss >> u;
					t=state[state.size()-1].second+u;
					state.push_back(make_pair(time[index],t));
				}
				if(s=="undo")
				{
					int a;
					ss >> a;
					a=time[index]-a-1;
					for(int i=0;i<state.size()-1;i++)
						if(state[i].first<=a && a<state[i+1].first)
							t=state[i].second;
					if(state[state.size()-1].first<=a)
						t=state[state.size()-1].second;
					state.push_back(make_pair(time[index],t));
				}
			}
			return state[state.size()-1].second;
		}
};
