#include <string>
#include <utility>
#include <vector>
using namespace std;

class OrderedSuperString
{
public:

pair<int,string> connect(string front,string back,int start)
{
	for(start;start<=front.size();start++)
	{
		int a=min(front.size()-start,back.size());
		string s=front.substr(start,a);
		string t=back.substr(0,a);
		if(s==t)
		{
			if(0<back.size()-a)
				front+=back.substr(a,back.size()-a);
			return make_pair(start,front);
		}
	}
	return make_pair(-1,"");
}

int getLength(vector <string> words)
{
	int start=0;
	string r=words[0];
	for(int i=1;i<words.size();i++)
	{
		pair<int,string> p;
		p=connect(r,words[i],start);
		start=p.first;
		r=p.second;
		if(start==-1)
			printf("error\n");
	}
	return r.size();
}
};
