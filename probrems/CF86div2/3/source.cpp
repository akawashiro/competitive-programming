#include <string>
#include <iostream>
#include <vector>

using namespace std;

int isMaleV(string s)
{
	string tale="initis";
	if(s.size()<tale.size())
		return 0;
	return (s.substr(s.size()-tale.size())==tale);
}
int isFemaleV(string s)
{
	string tale="inites";
	if(s.size()<tale.size())
		return 0;
	return (s.substr(s.size()-tale.size())==tale);
}
int isMaleN(string s)
{
	string tale="etr";
	if(s.size()<tale.size())
		return 0;
	return (s.substr(s.size()-tale.size())==tale);
}
int isFemaleN(string s)
{
	string tale="etra";
	if(s.size()<tale.size())
		return 0;
	return (s.substr(s.size()-tale.size())==tale);
}
int isMaleA(string s)
{
	string tale="lios";
	if(s.size()<tale.size())
		return 0;
	return (s.substr(s.size()-tale.size())==tale);
}
int isFemaleA(string s)
{
	string tale="liala";
	if(s.size()<tale.size())
		return 0;
	return (s.substr(s.size()-tale.size())==tale);
}

int isMaleSentense(vector<string> input)
{
	int pos=0;
	while(pos!=(int)input.size() && isMaleA(input[pos]))
		pos++;
	if(pos==(int)input.size() || !isMaleN(input[pos]))
		return 0;
	pos++;
	while(pos!=(int)input.size() && isMaleV(input[pos]))
		pos++;
	return (pos==(int)input.size());
}

int isFemaleSentense(vector<string> input)
{
	int pos=0;
	while(pos!=(int)input.size() && isFemaleA(input[pos]))
		pos++;
	while(pos==(int)input.size() || !isFemaleN(input[pos]))
		return 0;
	pos++;
	while(pos!=(int)input.size() && isFemaleV(input[pos]))
		pos++;
	return (pos==(int)input.size());
}

int main()
{
	string s;
	vector<string> input;
	while(cin>>s)
		input.push_back(s);
	if(input.size()==1)
	{
		if(isMaleA(input[0]) || isMaleN(input[0]) || isMaleV(input[0]) ||
				isFemaleA(input[0]) || isFemaleN(input[0]) || isMaleV(input[0]))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	else
	{
		if(isMaleSentense(input) || isFemaleSentense(input))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

