#include <iostream>
#include <map>
#include <limits.h>
using namespace std;

int n;
int chart[101][101];

int mincost(int s,int e)	//dist[i]をフラグ代わりに使用 (=INT_MAX => まだ確定していない)
{
		multimap<int,int> way;
		int dist[101];
		for(int i=1;i<=n;i++)
				dist[i]=INT_MAX;	//フラグ兼答えを初期化
		way.insert(multimap<int ,int>::value_type(0,s));	//sが最初に選ばれる
	
		while(1){
				if(way.empty())
						break;

				int p,d;
				d=way.begin()->first;	p=way.begin()->second;
				way.erase(way.begin());

				if(dist[p]!=INT_MAX)	//もう決定しているのでパス
						continue;
				dist[p]=d;	//決定する

				for(int i=1;i<=n;i++){	//辺の追加
						if(dist[i]!=INT_MAX || chart[p][i]==INT_MAX)	//決定しているもしくは道が無いならパス
								continue;
						way.insert(multimap<int ,int>::value_type(d+chart[p][i],i));

				}
		}
		return dist[e];
}

int main()
{
		int k;
		cin >> n >> k;
		for(int i=0;i<101;i++)
				for(int j=0;j<101;j++)
						chart[i][j]=INT_MAX;
		for(int i=0;i<101;i++)
				chart[i][i]=0;
		for(int i=0;i<k;i++){
				int a;
				cin >> a;
				if(a==0){
						int b,c;
						cin >> b >> c;
						int r=mincost(b,c);
						r=(r==INT_MAX) ? -1 : r;
						cout << r << endl;
				}else if(a==1){
						int b,c,d;
						cin >> b >> c >> d;
						if(d < chart[b][c]){
								chart[b][c]=d;	chart[c][b]=d;
						}
				}
		}
		return 0;
}

