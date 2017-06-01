#include <string>
#include <vector>
#include <pair>
using namespace std;

class RabbitStepping{
public:
double getExpected(string field, int r)
{
vector<pair<int,int> > rabbit(field.size()-1);	//<<pos,beforePos> >
for(int i=0;i<field.size();i++)
rabbit[i]=make_pair<int,int>(i,i-1);
for(int i=field.size();2<i;i++){
for(int j=0;j<rabbit.size();i++){
int before=rabbit.second;
rabbit.second=rabbit.first;
if(rabbit.first==0)
rabit.first++;
else if(rabbit.first==(i-1) || rabbit.first==(i-2))
rabbit.first--;
else if(field[rabbit.first]=='W')
rabbit.first--;
else if(field[rabbit.first]=='B')
rabbit.first++;
else if(field[rabbit.first]=='R')
rabbit.first=old;
}
for(int k=0;k<field.size();k++){
int count=0;
for(int l=0;l<rabbit.size();l++)
if(rabbit[l].first==i)	count++;
if(2<=count){
for(vector<pair<int,int> >::iterator it=rabbit.begin();it!=rabbit.end();it++)
if((*it).first==k)	it=remove(it);
}
}
}
int count=0;
for(int i=0;i<rabbit.size();i++)
if(rabbit[i].first==1)	count++;
return count;
}
};
