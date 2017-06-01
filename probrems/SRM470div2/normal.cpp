#include <vector>
#include <string>
using namespace std;

class DoorsGame{
	public:
		int determineOutcome(string doors, int trophy)
		{
			bool JDoor[26];
			bool GDoor[26];
			int nJ=0,nG=0,nB=0;
			for(int i=0;i<26;i++)
				JDoor[i]=false,GDoor[i]=false;
			int n=doors.size();
			for(int i=0;i<n;i++){
				if(i<trophy)
					JDoor[doors[i]-'A']=true;
				else
					GDoor[doors[i]-'A']=true;
			}
			for(int i=0;i<26;i++){
				if(JDoor[i] && GDoor[i]){
					nB++;
					continue;
				}
				if(JDoor[i])
					nJ++;
				if(GDoor[i])
					nG++;
			}
			printf("nJ=%d nG=%d nB=%d\n",nJ,nG,nB);
			if(nJ+nB <= nG)
				return 2*(nJ+nB)-1;
			if(nG+nB < nJ)
				return -2*(nG+nB);
			return 0;
		}
};
