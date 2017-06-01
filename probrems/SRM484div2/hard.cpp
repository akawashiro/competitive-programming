#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CubeColoring{
		public:
				long long theCount(vector <string> colors);
};

long long CubeColoring::theCount(vector <string> colors)
{
		long long count=0;
		int n=colors[0].size();
		for(int c0=0;c0<n;c0++){
				if((colors[0])[c0]=='N')
						continue;
				for(int c2=0;c2<n;c2++){
						if((colors[2])[c2]=='N')
								continue;
						for(int c5=0;c5<n;c5++){
								if((colors[5])[c5]=='N')
										continue;
								for(int c7=0;c7<n;c7++){
										if((colors[7])[c7]=='N')
												continue;
										int nc1,nc3,nc4,nc6;
										nc1=0;
										for(int i=0;i<n;i++){
												if((colors[1])[i]=='Y' && i!=c0 && i!=c2 && i!=c5)
														nc1++;
										}
										nc3=0;
										for(int i=0;i<n;i++){
												if((colors[3])[i]=='Y' && i!=c0 && i!=c2 && i!=c7)
														nc3++;
										}
										nc4=0;
										for(int i=0;i<n;i++){
												if((colors[4])[i]=='Y' && i!=c0 && i!=c5 && i!=c7)
														nc4++;
										}
										nc6=0;
										for(int i=0;i<n;i++){
												if((colors[6])[i]=='Y' && i!=c2 && i!=c5 && i!=c7)
														nc6++;
										}
										count+=(nc1*nc3*nc4*nc6);
								}
						}
				}
		}
		return count;
}
