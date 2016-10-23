#include <algorithm>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BirthdayCake
{
	public:

		set<string> fruit;

		int s2i(string s)
		{
			return (int)distance(fruit.begin(),fruit.find(s));
		}

		int popCount(int n)
		{
			int r=0;
			for(int i=0;i<25;i++)
				if(n & (1<<i))
					r++;
			return r;
		}

		int howManyFriends(vector <string> availableFruits, vector <string> friendsDislikings, int K)
		{
			int nFriend=friendsDislikings.size();
			for(int i=0;i<(int)availableFruits.size();i++)
				fruit.insert(availableFruits[i]);
			for(int i=0;i<nFriend;i++)
			{
				string s;
				stringstream ss(friendsDislikings[i]);
				while(ss >> s)
					fruit.insert(s);
			}

			int nFruit=fruit.size();
			vector<int> useFruit(nFruit,0);
			for(int i=0;i<(int)availableFruits.size();i++)
				useFruit[s2i(availableFruits[i])]=1;
			vector<vector<int> > fD(nFriend);
			for(int i=0;i<nFriend;i++)
			{
				string s;
				stringstream ss(friendsDislikings[i]);
				while(ss >> s)
					fD[i].push_back(s2i(s));
			}

			int ans=0;
			int a=0;
			for(int i=0;i<nFruit;i++)
				a+=useFruit[i];
				
			//printf("nFriend=%d nFruit=%d\n",nFriend,nFruit);
			
			for(int eat=0;eat<(1<<nFriend);eat++)
			{
				//printf("eat=%d\n",eat);
				
				int r=a;
				vector<int> v=useFruit;
				for(int i=0;i<nFriend;i++)
					if(eat & (1<<i))
					{
						//printf("%d ",i);
						for(int j=0;j<fD[i].size();j++)
							if(v[fD[i][j]]==1)
							{
								r--;
								v[fD[i][j]]=0;
								//if(r<K)
								//	goto B1;
							}
					}
//B1:
				
				//printf("\n");
				//printf("r=%d\n\n",r);
				
				if(K<=r)
					ans=max(ans,popCount(eat));
			}

			return ans;
		}
};

