#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct K2D{
	string ward;
	string key;
	int sn;
};

class T9{
	public:
		string message(vector <string> part, vector <string> dict, vector <string> ckeystr)
		{
			sort(dict.begin(),dict.end());
			string keystr;
			for(int i=0;i<ckeystr.size();i++)
				keystr+=ckeystr[i];

			vector<K2D> k2d(dict.size());
			string ans;
			for(int i=0;i<k2d.size();i++){
				k2d[i].ward=dict[i];
				for(int j=0;j<k2d[i].ward.size();j++)
					for(int k=0;k<part.size();k++)
						for(int l=0;l<part[k].size();l++)
							if(part[k][l]==k2d[i].ward[j])
								k2d[i].key+='0'+k+1;
				k2d[i].sn=0;
				for(int j=0;j<i;j++)
					if(k2d[j].key==k2d[i].key)
						k2d[i].sn++;
				printf("dict s=%s w=%s n=%d\n",k2d[i].key.c_str(),k2d[i].ward.c_str(),k2d[i].sn);
			}

			for(int i=0;i<keystr.size();i++){
				if(keystr[i]=='0'){
					ans+=' ';
					continue;
				}
				string s;
				for(int j=i;j<keystr.size();j++,i++){
					if(keystr[j]!='0'){
						s+=keystr[j];
					}else
						break;
				}
				i--;
				int n=0;
				while(0<s.size()){
					if(s[s.size()-1]=='#'){
						s=s.substr(0,s.size()-1);
						n++;
						continue;
					}else if(s[s.size()-1]=='*'){
						s=s.substr(0,s.size()-1);
						n+=5;
						continue;
					}
					break;
				}
				printf("s=%s n=%d\n",s.c_str(),n);
				for(int j=0;j<k2d.size();j++){
					if(k2d[j].key==s && k2d[j].sn==n)
						ans+=k2d[j].ward;
				}
			}
			return ans;
		}
};
