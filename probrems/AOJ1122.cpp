//AOJ1122
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int L,H,an;
vector<int> hi,bl,ans,tmp,th,tb;
vector<vector<int> > tr,ex;
void dfs(int k){
	if(1<an){
		;
	}else if(k==L){
		int ok=1;
		for(int i=0;i<H;i++)
			if(hi[i]!=th[i]||bl[i]!=tb[i])
				ok=0;
		if(ok){
			/*for(int i=0;i<L;i++)
				cout<<tmp[i];
			cout<<endl;*/
			for(int i=0;i<L;i++)
				ans[i]=tmp[i];
			an++;
		}
	}else{
		int left=(1<<10)-1;
		for(int i=0;i<k;i++)	
			left-=1<<tmp[i];
		for(int i=0;i<10;i++)
			if(left&(1<<i)){
				int ok=1;
				vector<int> h(H,0),b(H,0);
				for(int j=0;j<H;j++){
					if(tr[j][k]==i)
						h[j]++;
					else if(ex[j][i])
						b[j]++;
					th[j]+=h[j],tb[j]+=b[j];
					if(hi[j]<th[j]||bl[j]<tb[j])
						ok=0;
				}
				if(ok){
					tmp[k]=i;
					dfs(k+1);
				}
				for(int j=0;j<H;j++)
					th[j]-=h[j],tb[j]-=b[j];
			}
	}
}
int main(){
	while(1){
		cin>>L>>H;
		if(!L&&!H)	break;
		hi=bl=th=tb=vector<int>(H);
		ans=tmp=vector<int>(L);
		tr=vector<vector<int> >(H,vector<int>(L));
		ex=vector<vector<int> >(H,vector<int>(10,0));
		for(int i=0;i<H;i++){
			string s;
			cin>>s>>hi[i]>>bl[i];
			for(int j=0;j<L;j++){
				tr[i][j]=s[j]-'0';
				ex[i][s[j]-'0']=1;
			}
		}
		an=0;
		dfs(0);
		if(an==1){
			for(int i=0;i<L;i++)
				cout<<ans[i];
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

