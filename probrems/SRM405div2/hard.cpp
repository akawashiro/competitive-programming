#include <string>
#include <vector>

using namespace std;

class IdealString
{
	public:

		string ans;
		int length;

		string calc(vector<int> startIndex)
		{
			int nS=startIndex.size();
			string r(length,'#');
			vector<int> left=startIndex;
			
			for(int i=1;i<nS;i++)
				r[startIndex[i]-1]='A'+i-1,left[i]--;
				
			for(int i=1;i<nS;i++)
				for(int j=startIndex[i];j<length;j++)
					if(r[j]=='#' && 0<left[i])
						r[j]='A'+i-1,left[i]--;
						
			//printf("%s\n",r.c_str());	
						
			return (r.find('#')==string::npos)?r:string(length,'Z'+1);
		}

		void rec(vector<int> startIndex,int left)
		{
			if(left==0)
			{
				/*for(int i=0;i<startIndex.size();i++)
					printf("%d ",startIndex[i]);
				printf("\n");*/

				ans=min(ans,calc(startIndex));
				return;
			}
			vector<int> v=startIndex;
			int last=v.size();
			v.push_back(0);
			for(int next=startIndex.back()+1;0<=left-next && next<=(length-left+1);next++)
			{
				v[last]=next;
				rec(v,left-next);
			}
			return;
		}
		
		string construct(int _length)
		{
			length=_length;
			ans=string(length,'Z'+1);
			rec(vector<int>(1,0),length);

			return (ans==string(length,'Z'+1))?"":ans;
		}
};

