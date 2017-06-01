#include <vector>
#include <set>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;

class EasySequence{
	public:
		int find(vector <int> A, vector <int> B)
		{
			int N=A.size(),M=B.size(),loopStart;
			vector<int> seqA;
			while(1){
				int seq=0,sum=0;
				for(int i=A.size()-N,j=0;j<N;i++,j++){
					sum+=A[i];
					seq+=A[i]*pow(10,j);
				}
				if(std::find(seqA.begin(),seqA.end(),seq)!=seqA.end()){
					loopStart=distance(seqA.begin(),std::find(seqA.begin(),seqA.end(),seq))+N;
					//printf("dist=%d N=%d\n",distance(seqA.begin(),std::find(seqA.begin(),seqA.end(),seq)),N);
					break;
				}
				A.push_back(sum%10);
				seqA.push_back(seq);
			}
			/*for(int i=0;i<A.size();i++)
				printf("%d ",A[i]);
			printf("\nloopStart=%d",loopStart);*/
			for(int i=0;i<A.size();i++){
				int match=0,index=i;
				for(int j=0;j<B.size();j++){
					if(A[index]==B[j])
						match++;
					index=(index+1==A.size()) ? loopStart : index+1;
				}
				if(match==B.size())
					return i;
			}
			return -1;
		}
};
