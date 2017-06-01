#include <vector>
#include <utility>
#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long LL;

int main()
{
	vector<pair<int,LL> > sum;
	vector<pair<int,LL> > a;
	vector<pair<int,LL> > b;
	int m;
	scanf("%d",&m);
	a.push_back(make_pair(0,0));
	a.push_back(make_pair(0,1000000000));
	for(int i=0;i<m;i++){
		int n;LL s;
		scanf("%d%lld",&n,&s);
		a.push_back(make_pair(n,s));
	}
	scanf("%d",&m);
	b.push_back(make_pair(0,0));
	b.push_back(make_pair(0,1000000000));
	for(int i=0;i<m;i++){
		int n;LL s;
		scanf("%d%lld",&n,&s);
		b.push_back(make_pair(n,s));
	}
	int aI=(int)a.size()-1,bI=(int)b.size()-1;
	LL aP=0,bP=0;
	while(aI>0 || bI>0){
		int n=a[aI].first+b[bI].first;
		//printf("aI=%d aP=%lld bI=%d bP=%lld\n",aI,aP,bI,bP);
		if(aI==0){
			sum.push_back(make_pair(n,b[bI].second));
			bI--;
		}else if(bI==0){
			sum.push_back(make_pair(n,a[aI].second));
			aI--;
		}
		else if(aP==bP){
			sum.push_back(make_pair(n,min(a[aI].second,b[bI].second)));
			aP+=a[aI].second,bP+=b[bI].second;
			aI--,bI--;
		}
		else if(aP<bP){
			n=a[aI].first+b[bI+1].first;
			sum.push_back(make_pair(n,min(bP-aP,a[aI].second)));
			aP+=a[aI].second;
			aI--;
		}
		else if(bP<aP){
			n=a[aI+1].first+b[bI].first;
			sum.push_back(make_pair(n,min(aP-bP,b[bI].second)));
			bP+=b[bI].second;
			bI--;
		}
	}
	/*for(int i=0;i<(int)sum.size();i++)
		printf("n=%d s=%lld\n",sum[i].first,sum[i].second);
	printf("\n");*/
	{
		vector<pair<int,LL> > s=sum;
		sum.clear();
		int car=0;
		for(int i=0;i<(int)s.size();i++){
			if(car==0){
				if(s[i].first<10)
					sum.push_back(s[i]);
				else
				{
					sum.push_back(make_pair(s[i].first%10,1));
					sum.push_back(make_pair(s[i].first%10+1,s[i].second-1));
					car=1;
				}
			}
			else{
				if(s[i].first<9){
					sum.push_back(make_pair(s[i].first+1,1));
					sum.push_back(make_pair(s[i].first,s[i].second-1));
					car=0;
				}
				else{
					sum.push_back(make_pair((s[i].first+1)%10,s[i].second));
				}
			}
		}
		if(car==1)
			sum.push_back(make_pair(1,1));
	}
	/*for(int i=0;i<(int)sum.size();i++)
		printf("n=%d s=%lld\n",sum[i].first,sum[i].second);
	printf("\n");*/
	{
		vector<pair<int,LL> > s=sum;
		sum.clear();
		for(int i=0;i<s.size();i++)
			if(s[i].second>0)
				sum.push_back(s[i]);
	}
	/*for(int i=0;i<(int)sum.size();i++)
		printf("n=%d s=%lld\n",sum[i].first,sum[i].second);
	printf("\n");*/
	{
		vector<pair<int,LL> > s=sum;
		sum.clear();
		int i=0;
		int seq=0;
		while(i<(int)s.size()-1){
			seq=s[i].second;
			while(i<(int)s.size()-2 && s[i].first==s[i+1].first){
				seq+=s[i+1].second;
				i++;
			}
			sum.push_back(make_pair(s[i].first,seq));
			i++;
		}
	}
	/*for(int i=0;i<(int)sum.size();i++)
		printf("n=%d s=%lld\n",sum[i].first,sum[i].second);
	printf("\n");*/
	reverse(sum.begin(),sum.end());
	printf("%d\n",(int)sum.size());
	for(int i=0;i<(int)sum.size();i++)
		printf("%d %lld\n",sum[i].first,sum[i].second);

	return 0;
}

