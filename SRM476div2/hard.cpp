#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

bool isSubAnagram(string a,string b)
{
int aCount[26];
int bCount[26];
for(int i=0;i<26;i++){
				aCount[i]=0;
				bCount[i]=0;
}
for(int i=0;i<a.size();i++){
				aCount[a[i]-'A']++;
}
for(int i=0;i<b.size();i++){
				bCount[b[i]-'A']++;
}
for(int i=0;i<26;i++)
if(bCount[i]<aCount[i]){
				printf("%8s isn't subanagram of %8s\n",a.c_str(),b.c_str());
				return false;
}
printf("%8s is subanagram of %8s\n",a.c_str(),b.c_str());return true;
}

class SubAnagrams{
public:
int maximumParts(vector <string> suppliedWord)
{
string total;
for(int i=0;i<suppliedWord.size();i++)
total+=suppliedWord[i];
int n=total.size();
int table[n][n];
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
table[i][j]=(j==0) ? 1 : 0;
for(int i=1;i<n;i++){
				for(int j=1;j<=i;j++){
								string b=total.substr(j,i-j+1);
								int m=0;
								for(int k=0;k<=j-1;k++){
												string a=total.substr(k,j-1-k+1);
												if(isSubAnagram(a,b))
																m=max(m,table[j-1][k]);
								}
								if(m!=0)	m++;
								table[i][j]+=m;
				}
}
int ans=0;
for(int i=0;i<n;i++)
ans=max(ans,table[n-1][i]);
return ans;
}
};

int main()
{
				SubAnagrams s;
				vector<string> data;
				data.push_back("AAAA");
				printf("%d\n",s.maximumParts(data));
}
