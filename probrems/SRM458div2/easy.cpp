#include <string>
#include <vector>
using namespace std;

class Desertification{
	public:
		int desertArea(vector <string> island, int T)
		{
			int height=island.size();
			int width=island[0].size();
			if(1000<T)
				T=1000;
			for(int k=0;k<T;k++){
				for(int i=0;i<height;i++)
					for(int j=0;j<width;j++)
						if(island[i][j]=='D'){
							if(i+1<height && island[i+1][j]=='F') island[i+1][j]='H';
							if(0<=i-1     && island[i-1][j]=='F') island[i-1][j]='H';
							if(j+1<width  && island[i][j+1]=='F') island[i][j+1]='H';
							if(0<=j-1     && island[i][j-1]=='F') island[i][j-1]='H';
						}
				for(int i=0;i<height;i++)
					for(int j=0;j<width;j++)
						if(island[i][j]=='H')
							island[i][j]='D';
			}
			int ans=0;
			for(int i=0;i<height;i++)
				for(int j=0;j<width;j++)
					if(island[i][j]=='D')
						ans++;
			return ans;
		}
};
