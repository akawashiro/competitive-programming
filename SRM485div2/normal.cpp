#include <vector>
using namespace std;

class AfraidOfEven{
		public:
				vector <int> restoreProgression(vector <int> seq);
};

bool isproduct(int a,int b)
{
		for(b;b<a;b*=2){;}
		return (a==b);
}

vector<int> AfraidOfEven::restoreProgression(vector<int> seq)
{
		vector<int> r1(seq.size()),r2(seq.size());
		bool canr1=false,canr2=false;
		int dif1=seq[2]-seq[0],dif2=seq[3]-seq[1];
		if(dif1%2==0){
				canr1=true;
				dif1/=2;
				r1[0]=seq[0];
				for(int i=1;i<seq.size();i++){
						r1[i]=r1[i-1]+dif1;
						if(!isproduct(r1[i],seq[i])){
								canr1=false;
								break;
						}
				}
		}
		if(dif2%2==0){
				canr2=true;
				dif2/=2;
				r2[0]=seq[1]-dif2;
				if(!isproduct(r2[0],seq[0]))
						canr2=false;
				for(int i=1;i<seq.size();i++){
						r2[i]=r2[i-1]+dif2;
						if(!isproduct(r2[i],seq[i])){
								canr2=false;
								break;
						}
				}
		}
		if(canr1 && canr2){
				for(int i=0;i<seq.size();i++){
						if(r1[i]<r2[i]){
								printf("returned r1\n");
								return r1;
						}else if(r2[i]<r1[i]){
								printf("returned r2\n");
								return r2;
						}
				}
				return r1;
		}else if(canr1){
				printf("returned r1\n");
				return r1;
		}else if(canr2){
				printf("returned r2\n");
				return r2;
		}else
				printf("what!\n");
}
