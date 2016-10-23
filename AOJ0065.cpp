#include <stdio.h>
#include <map>

using namespace std;

int main(){
     map<int,int> ma1,ma2;
//     fprintf(stderr,"%d\n",__LINE__);
     while(1){
	  int a,b;
	  scanf("%d,%d",&a,&b);
//	  fprintf(stderr,"%d %d\n",a,b);
	  ma1[a]++;
	  char c=getc(stdin);
	  c=getc(stdin);
	  if(c=='\n')
	       break;
	  else
	       ungetc(c,stdin);
     }
//     fprintf(stderr,"%d\n",__LINE__);
     while(1){
	  int a,b;
	  if(scanf("%d,%d",&a,&b)==EOF)
	       break;
	  ma2[a]++;
     }
     for(map<int,int>::iterator it=ma1.begin();it!=ma1.end();it++)
	  if(ma2[(*it).first]!=0)
	       printf("%d %d\n",(*it).first,(*it).second+ma2[(*it).first]);
     return 0;
}
