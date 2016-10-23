#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

class MatchString
{
	public:
		int placeWords(string matchString, vector <string> matchWords)
		{
			int len=0;
			int n=matchWords.size();
			for(int i=0;i<n;i++)
				len=max(len,(int)matchWords[i].size());
			for(int i=0;i<n;i++)
				matchWords[i]+=string(len-matchWords[i].size(),'.');

			int ans=(1<<28);

			for(int anchorY=0;anchorY<n;anchorY++)
				for(int anchorX=0;anchorX<len;anchorX++)
					if(matchWords[anchorY][anchorX]==matchString[anchorY])
					{
						int t=0;
						for(int y=0;y<n;y++)
						{
							int l=0;
							while(matchWords[y][anchorX-l]!=matchString[y] && 0<=anchorX-l)
								l++;
							if(anchorX-l<0)
								l=(1<<28);
							t+=l;
							
							if((1<<28)<=t)
								break;
						}
						ans=min(ans,t);
					}

			return (ans==(1<<28)) ? -1 : ans;
		}
};

