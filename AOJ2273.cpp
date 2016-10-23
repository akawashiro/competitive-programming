#include <string>
#include <set>
#include <stdio.h>

using namespace std;

set<string> used;

string makeWord(char b,char e)
{
	for(char c1='a';c1<='z';c1++)
		for(char c2='a';c2<='z';c2++)
			for(char c3='a';c3<='z';c3++)
			{
				string s;
				s+=b,s+=c1,s+=c2,s+=c3,s+=e;
				if(used.find(s)==used.end())
					return s;
			}
}

int main()
{
	printf("?aaaaa\n");
	fflush(stdout);
	used.insert("aaaaa");
	while(1)
	{
		string opponent;
		char cs[100];
		scanf("%s",cs);
		opponent=cs;
		if(opponent[0]!='a' || used.find(opponent)!=used.end())
		{
			printf("!OUT\n");
			fflush(stdout);
			break;
		}
		used.insert(opponent);
		string say=makeWord(opponent[opponent.size()-1],'a');
		printf("?%s\n",say.c_str());
		fflush(stdout);
		used.insert(say);
	}
	return 0;
}

