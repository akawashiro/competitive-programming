#include <string>
using namespace std;

class PalindromesCount{
public:
int count(string A, string B)
{
int ans=0;
for(int i=0;i<A.size()+1;i++){
string s;
if(i==0)
s=B+A;
else if(i==A.size())
s=A+B;
else
s=A.substr(0,i-0)+B+A.substr(i,s.size()-i);
string s2;
for(int j=s.size()-1;0<=j;j--)
s2+=s[j];
//printf("%s == %s \n",s.c_str(),s2.c_str());
if(s==s2)
ans++;
}
return ans;
}
};
