#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;

int n;
string input[10000+10];
int words[10000+10][26+5];
int len[10000+10];
vector<int> G[10000+10];
int longest[10000+10];

bool cmp(string s1,string s2)
{
	return s1.size()<s2.size();
}

int rec(int k)
{
	if(longest[k]!=-1)
	{
		return longest[k];
	}
	else
	{
		longest[k]=1;
		for(int i=0;i<(int)G[k].size();i++)
			longest[k]=max(longest[k],1+rec(G[k][i]));
		return longest[k];
	}
}

int prt(int k)
{
	//printf("prt(%d)--%s\n",k,input[k]);
	//fflush(stdout);
	printf("%s\n",input[k].c_str());
	int m=0,v=-1;
	if(0<G[k].size())
	{
		for(int i=0;i<(int)G[k].size();i++)
			if(m<longest[G[k][i]])
				m=longest[G[k][i]],v=G[k][i];
		prt(v);
	}
	return 0;
}

int ABS(int n)
{
	return (0<=n)?n:-n;
}

int main()
{
	memset(words,0,sizeof(words));
	memset(len,0,sizeof(len));
	n=0;
	char tmp[30];
	while(scanf("%s",tmp)!=EOF)
	{
		input[n]=tmp;
		//for(int i=0;input[n][i]!='\0';i++,len[n]++)
		//	words[n][input[n][i]-'a']++;
		n++;
	}
	sort(input,input+n,cmp);
	/*for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(len[j]>len[j+1])
			{
				swap(len[j],len[j+1]);
				char s[30];
				strcpy(s,input[j]);
				strcpy(input[j],input[j+1]);
				strcpy(input[j+1],s);
			}*/
	for(int i=0;i<n;i++)
	{
		len[i]=input[i].size();
		for(int j=0;input[i][j]!='\0';j++)
			words[i][input[i][j]-'a']++;
	}
	//for(int i=0;i<n;i++)
	//	printf("%s-%d\n",input[i],len[i]);

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n && len[j]<=len[i]+1;j++)
			if(len[j]-len[i]==1)
			{
				int d=0,ad=0;
				for(int k=0;k<26 && ad<2;k++)
					d+=words[i][k]-words[j][k],ad+=ABS(words[i][k]-words[j][k]);
				if(d==1 && ad==1)
				{
					G[j].push_back(i);
					//printf("%s->%s\n",input[j],input[i]);
				}
				else if(d==-1 && ad==1)
				{
					G[i].push_back(j);
					//printf("%s->%s\n",input[i],input[j]);
				}
				else
					;
			}

	//printf("init-finished\n");
	//fflush(stdout);

	memset(longest,-1,sizeof(longest));
	int m=0,v=-1;
	for(int i=0;i<n;i++)
	{
		//printf("rec(%d)-in main\n",i);
		//fflush(stdout);
		int a=rec(i);
		if(m<a)
			m=a,v=i;
	}

	//printf("rec-finished\n");
	//fflush(stdout);

	prt(v);
	return 0;
}

