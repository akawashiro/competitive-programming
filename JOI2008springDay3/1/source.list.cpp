#include <stdio.h>
#include <set>
#include <algorithm>
#include <list>
#include <map>

using namespace std;
typedef map<int,list<int> > XLIST;

int main()
{
  int n,H,W;
  scanf("%d%d%d",&n,&W,&H);
  XLIST xList;
  for(int i=0;i<n;i++)
  {
    int p,q,r,s;
    scanf("%d%d%d%d",&p,&q,&r,&s);
    p--,q--;
    xList[q*2].push_back(p*2);
    xList[q*2].push_back(r*2-1);
    xList[s*2-1].push_back(p*2);
    xList[s*2-1].push_back(r*2-1);
  }

  int thick=0,S=0;
  int maxThick=0;
  list<int> row;
  int befY=((*(xList.begin())).first+1)/2-1;
  for(XLIST::iterator it=xList.begin();it!=xList.end();it++)
  {
    int y=((*it).first+1)/2;

    printf("y=%d -- ",y);
    for(list<int>::iterator jt=row.begin();jt!=row.end();jt++)
    	printf("%d ",(*jt));
    printf("\n");
    maxThick=max(maxThick,(int)row.size());
    
    list<int> xs=(*it).second;
    xs.sort();

    int t=0,bx=(*(row.begin()));
    for(list<int>::iterator jt=row.begin();jt!=row.end();jt++)
    {
      int x=((*jt)+1)/2;
      int s=(x-bx)*(y-befY);
      if(t==thick)
	S+=s;
      else if(thick<t && 0<s)
	thick=t,S=s;

      if((*jt)%2==0)
	t++;
      else
	t--;
      bx=x;
    }
    if((*it).first%2==0)
    {
      row.merge(xs);
    }
    if((*it).first%2!=0)
    {
      set<int> se(xs.begin(),xs.end());
      for(list<int>::iterator jt=row.begin();jt!=row.end();)
      {
	if(se.find((*jt))!=se.end())
	{
	  jt=row.erase(jt);
	  continue;
	}
	jt++;
      }
    }
    befY=y;
  }

  printf("maxThick=%d\n",maxThick);

  printf("%d\n%d\n",thick,S);
  return 0;
}

