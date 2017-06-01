#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

class PrimePalindromic
{
	public:
		int count(int A, int B)
		{
			int ans=0;
			for(int num=A;num<=B;num++)
			{
				int n=num;
				vector<string> vs;
				while(1<n)
				{
					int a;
					for(a=2;a*a<=n;a++)
						if(n%a==0)
							break;
					if(n<a*a)
						a=n;
					stringstream ss;
					ss << a;
					vs.push_back(ss.str());
					n/=a;
				}
				
				sort(vs.begin(),vs.end());

				bool pal=false;
				do{
					string s,t;
					for(int i=0;i<(int)vs.size();i++)
						s+=vs[i];
					t=s;
					reverse(t.begin(),t.end());
					
					if(s==t)
					{
						pal=true;
						break;
					}
				}while(next_permutation(vs.begin(),vs.end()));

				if(pal)
					ans++;
			}

			return ans;
		}
};

