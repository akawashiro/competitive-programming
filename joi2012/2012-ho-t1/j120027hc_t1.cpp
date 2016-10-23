#include <stdio.h>
#include <vector>
using namespace std;
char in[10000000+10];
int main(){
	scanf("%s",in);
	vector<int> ch,sq;
	int c=in[0],s=1;
	for(int i=1;in[i]!=0&&in[i]!='\n';i++){
		if(c!=in[i]){
			ch.push_back(c);
			sq.push_back(s);
			c=in[i];
			s=1;
		}else{
			s++;
		}
	}
	ch.push_back(c);
	sq.push_back(s);
	int ans=0;
	for(int i=0;i+2<(int)ch.size();i++){
		if(ch[i]=='J'&&ch[i+1]=='O'&&ch[i+2]=='I'&&sq[i+1]<=min(sq[i],sq[i+2]))
			ans=max(ans,min(sq[i],sq[i+1]));
	}
	printf("%d\n",ans);
	return 0;
}

