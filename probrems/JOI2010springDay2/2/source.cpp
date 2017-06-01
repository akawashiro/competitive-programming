#include <vector>
#include <string>
#include <iostream>

using namespace std;

int atgc2i(char c)
{
	if(c=='A')	return 0;
	else if(c=='T')	return 1;
	else if(c=='G')	return 2;
	else	return 3;
}

class Trie{
	public:
		int isEnd;
		int edge[4];
		int next[4];
		/*Trie()
		{
			isEnd=0;
			for(int i=0;i<4;i++)
				edge[i]=0;
		}*/
		/*void make(string s,int p)
		{
			//cout<<s<<" "<<p<<endl;
			if(p==(int)s.size()){
				//cout<<"end"<<endl;
				isEnd=1;
				return;
			}
			if(edge[atgc2i(s[p])]==0){
				next[atgc2i(s[p])]=new Trie;
			}
			edge[atgc2i(s[p])]++;
			(*next[atgc2i(s[p])]).make(s,p+1);
		}*/
		/*int check(string s,int p)
		{
			//cout<<s<<" "<<p<<endl;
			if(p==(int)s.size())
			{
				//cout<<s<<" "<<isEnd<<"end"<<endl;
				return isEnd;
			}
			if(edge[atgc2i(s[p])]==0)
				return 0;
			return (*next[atgc2i(s[p])]).check(s,p+1);
		}*/
};

int te=0;
Trie trie[150000*20+10];

void make(string s,int tk)
{
	int p=0;
	while(1){
		if(p==(int)s.size()){
			//cout<<"end"<<endl;
			trie[tk].isEnd=1;
			return;
		}
		if(trie[tk].edge[atgc2i(s[p])]==0){
			trie[tk].next[atgc2i(s[p])]=te;
			trie[te].isEnd=0;
			for(int i=0;i<4;i++)
				trie[te].edge[i]=0;
			te++;
		}
		trie[tk].edge[atgc2i(s[p])]++;
		tk=trie[tk].next[atgc2i(s[p])];
		p++;
	}
}

int check(string s,int tk)
{
	int p=0;
	while(1){
		if((int)s.size()==p)
			return trie[tk].isEnd;
		if(0<trie[tk].edge[atgc2i(s[p])]){
			tk=trie[tk].next[atgc2i(s[p])];
			p++;
		}
		else
			return -1;
	}
}

int jump[150000+10];
int DP[150000+10];

int main()
{
	int m;
	cin>>m;
	string target;
	cin>>target;;
	trie[te].isEnd=0;
	for(int i=0;i<4;i++)
		trie[te].edge[i]=0;
	te++;
	//cout<<"trie start"<<endl;
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		//cout<<s<<endl;

		make(s,0);
	}
	//for(int i=0;i<m;i++)
	//	cout<<trie.check(DNA[i],0)<<endl;
	for(int i=0;i<(int)target.size();i++)
		for(int l=1;l<=20 && i+l<=(int)target.size();l++)
		{
			int s=i,e=i+l;
			int c=0;
			int tk=0;
			while(1){
				if(s==e)
				{
					c=trie[tk].isEnd;
					break;
				}
				else if(0<trie[tk].edge[atgc2i(target[s])]){
					tk=trie[tk].next[atgc2i(target[s])];
					s++;
				}
				else{
					c=-1;
					break;
				}
			}
			//if(c==-1)
			//	continue;
			if(c==1){
				jump[i]=l;
			}
		}
	/*for(int i=0;i<(int)target.size();i++)
	  cout<<"jump["<<i<<"]="<<jump[i]<<endl;*/
	//cout<<"trie checked"<<endl;
	DP[target.size()-1]=0;
	for(int i=(int)target.size()-2;0<=i;i--){
		DP[i]=500000+10;
		//cout<<"DP["<<i<<"]="<<DP[i]<<endl;
		for(int j=i+1;j<i+jump[i];j++)
			DP[i]=min(DP[i],DP[j]+1);
	}
	cout<<DP[0]<<endl;
}
