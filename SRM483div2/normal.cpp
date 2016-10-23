#include <vector>
#include <string>
using namespace std;

class MovieSeating{
		public:
				long long getSeatings(int numFriends, vector <string> hall);
};

long long MovieSeating::getSeatings(int numFriends, vector <string> hall)
{
		long long ways=0;
		int n=hall.size()+hall[0].size();
		int empty[n];
		for(int i=0;i<n;i++)
				empty[i]=0;
		for(int i=0;i<hall.size();i++){
				for(int j=0;j<hall[i].size();j++){
						if((hall[i])[j]=='.')
								empty[i]++;
				}
		}
		for(int i=0;i<hall[0].size();i++){
				for(int j=0;j<hall.size();j++){
						if((hall[j])[i]=='.')
								empty[i+hall.size()]++;
				}
		}
		if(numFriends==1){
				for(int i=0;i<hall.size();i++)
						ways+=empty[i];
		}else{
				for(int i=0;i<n;i++){
						if(empty[i] < numFriends)
								continue;
						long long a=1;
						long long b=empty[i];
						for(int j=0;j<numFriends;j++){
								a*=b;
								b--;
						}
						ways+=a;
				}
		}
		return ways;
}

