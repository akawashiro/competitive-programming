#include <math.h>
#include <vector>
using namespace std;

class MinimalDifference{
	public:

		int digitSum(int n)
		{
			int r=0;
			while(0<n){
				r+=n%10;
				n/=10;
			}
			return r;
		}


		int findNumber(int A, int B, int C)
		{
			int cDig=digitSum(C);
			int ans=min(A,B);
			for(int i=min(A,B);i<=max(A,B);i++)
				if( abs(cDig-digitSum(i)) <  abs(cDig-digitSum(ans)) )
					ans=i;
			return ans;
		}

};
