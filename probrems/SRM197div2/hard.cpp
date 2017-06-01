//this is copy ,too;
#include <string>
#include <sstream>
using namespace std;

int s2i(string s)
{
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}

class QuickSums{
	public:
		int minSums(string s,int INP){
			int N=s.size(),res=100;
			for(int i=0;i<(1<<N);i++){
				string tmp;
				tmp+=s[0];
				int c=0;
				for(int j=0;j<N-1;j++){
					if(i&(1<<j)){
						tmp+=" ";
						tmp+=s[j+1];
						c++;
					}else
						tmp+=s[j+1];
				}
				stringstream ss(tmp);
				int sum=0;
				while(ss>>tmp)
					sum+=s2i(tmp);
				if(sum==INP)
					res=min(res,c);
			}
			if(res==100)
				res=-1;
			return res;
		}
};
