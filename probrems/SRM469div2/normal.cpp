#include <vector>
#include <cstdio>
#include <limits.h>
using namespace std;

class TheMoviesLevelTwoDivTwo{
	public:

		int n;
		vector<int> len;
		vector<int> sca;
		vector<int> ans;
		vector<int> movie;
		int maxAwake;

		void search(bool isAdded[7])
		{
			bool isEnd=true;
			for(int i=0;i<n;i++)
				if(!isAdded[i])
					isEnd=false;

			if(isEnd){

				for(int i=0;i<n;i++)
					printf("%d ",movie[i]);
				printf("\n");

				int awake;
				int nsc=74;
				for(awake=0;-1<nsc && awake<n;awake++){
					nsc-=sca[movie[awake]];
					if(nsc<0)
						break;
					nsc+=47;
					nsc-=(len[movie[awake]]-sca[movie[awake]]);
					if(nsc<0)
						break;
				}

				printf("awake=%d nsc=%d\n",awake,nsc);

				if(maxAwake<awake){
					ans=movie;
					maxAwake=awake;
				}else if(maxAwake==awake)
					for(int i=0;i<n;i++){
						if(movie[i] < ans[i]){
							ans=movie;
							break;
						}
						if(ans[i] < movie[i])
							break;
					}
				return;
			}

			for(int i=0;i<n;i++){
				if(!isAdded[i]){
					movie.push_back(i);
					isAdded[i]=true;
					search(isAdded);
					vector<int>::iterator it=movie.end();
					it--;
					movie.erase(it);
					isAdded[i]=false;
				}
			}
		}

			
		vector <int> find(vector <int> length, vector <int> scary)
		{
			n=length.size();
			len=length;
			sca=scary;
			maxAwake=0;
			bool isAdded[7];
			for(int i=0;i<7;i++){
				ans.push_back(INT_MAX);
				isAdded[i]=false;
			}
			search(isAdded);
			return ans;
		}
};
