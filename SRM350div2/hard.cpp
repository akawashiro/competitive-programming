#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BagsQuiz
{
	public:
		vector<int> bags;
		int n;

		bool PUT(int i,int j)
		{
			if(bags[i]!=100 || bags[j]!=100)
				return false;
			bags[i]=j;
			return true;
		}

		bool SET(int i)
		{
			if(bags[i]!=100)
				return false;
			for(int k=0;k<n+1;k++)
				if(bags[k]==i)
					bags[k]=100;
			return true;
		}

		bool SWAP(int i,int j)
		{
			if(bags[i]!=100 || bags[j]!=100)
				return false;
			for(int k=0;k<n+1;k++)
			{
				if(bags[k]==i)
					bags[k]=j;
				else if(bags[k]==j)
					bags[k]=i;
			}
			return true;
		}

		int checkIfProper(int _n, vector <string> actions)
		{
			n=_n;
			bags=vector<int>(n+1,100);
			bags[0]=200;

			for(int time=0;time<(int)actions.size();time++)
			{
				int i,j;
				string s,t,u;
				stringstream ss(actions[time]);

				ss >> s;
				if(s=="PUT")
				{
					ss >> i >> t >> j;
					if(!PUT(i,j))
						return -1;
				}
				if(s=="SET")
				{
					ss >> i >> t;
					if(!SET(i))
						return -1;
				}
				if(s=="SWAP")
				{
					ss >> i >> t >> j;
					if(!SWAP(i,j))
						return -1;
				}
			}

			for(int i=0;i<n+1;i++)
				if(bags[i]<i)
					return -1;
			int ans=0;
			for(int i=0;i<n+1;i++)
				if(bags[i]==100)
					ans++;
			return ans;
		}
};
