#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class ToolsBox{
	public:
		int countTools(vector <string> need)
		{
			set<string> se;
			for(int i=0;i<need.size();i++){
				stringstream ss;
				string s;
				ss << need[i];
				while(ss >> s)
					se.insert(s);
			}
			return se.size();
		}
};
