#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;

class ColorfulStrings{
	public:
		string getKth(int n, int k)
		{
			if(8<n)
				return "";
			int perm[10];
			for(int i=0;i<10;i++)
				perm[i]=i;
			int cnt=0;
			do{
				set<int> se;
				bool isNG=false;
				for(int i=0;i<n;i++){
					int t=1;
					for(int j=i;j<n;j++){
						t*=perm[j];
						if(!se.insert(t).second)
							goto NG;
					}
				}

				/*string s1;
					for(int i=0;i<n;i++)
					s1+='0'+perm[i];
					printf("%s\n",s1.c_str());*/
				cnt++;
				if(cnt==k){
					string s;
					for(int i=0;i<n;i++)
						s+='0'+perm[i];
					return s;
				}
NG:
				reverse(perm+n,perm+10);
			}while(next_permutation(perm,perm+10));
			return "";
		}
};
