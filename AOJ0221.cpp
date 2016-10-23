#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int player[1000+10];

int main()
{
	while(1)
	{
		int nPlayer,time,left;
		cin>>nPlayer>>time;
		left=nPlayer;
		if(nPlayer==0 && time==0)
			break;
		int p=0;
		for(int i=0;i<nPlayer;i++)
			player[i]=1;
		for(int t=1;t<=time;t++)
		{
			string input;
			cin>>input;
			if(1<left)
			{
				int wrong=0;
				if(t%15==0)
					wrong=(input=="FizzBuzz");
				else if(t%3==0)
					wrong=(input=="Fizz");
				else if(t%5==0)
					wrong=(input=="Buzz");
				else
					wrong=(atoi(input.c_str())==t);
				if(!wrong)
				{
					player[p]=0;
					left--;
				}
				p=(p+1)%nPlayer;
				while(!player[p])
					p=(p+1)%nPlayer;
			}
		}
		int isFirst=1;
		for(int i=0;i<nPlayer;i++)
			if(player[i])
			{
				if(isFirst)
				{
					isFirst=0;
				}
				else
					cout<<" ";
				cout<<i+1;
			}
		cout<<endl;
	}
	return 0;
}

