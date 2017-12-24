#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define GI(i) (scanf("%d",&i))
#define GLL(i) (scanf("%lld",&i))
#define GD(i)  (scanf("%lf",&i))
#define PB          push_back
#define MP          make_pair
#define MT          make_tuple
#define GET0(x)     (get<0>(x))
#define GET1(x)     (get<1>(x))
#define GET2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       (1LL<<60)
#define LLMIN       -(1LL<<60)
#define IMAX        (1<<30)
#define IMIN        -(1<<30)
typedef long long LL;
using namespace std;

class RangeUpdateRangeSum{
    public:
        int sz;
        vector<LL> node, lazy;

        RangeUpdateRangeSum(int n) {
            sz = 1;
            while (n > sz )sz *= 2;
            node.assign(2*sz+1,0);
            lazy.assign(2*sz+1,0);
            for (int i = 0; i < 2 * sz - 1; i++)lazy[i] = -1;
        }

        void lazy_evaluate_node(int k, int l, int r) {
            if (lazy[k] != -1) { 
                node[k] = lazy[k]; 
                if (r - l > 1) {
                    lazy[k * 2 + 1] = lazy[k]; 
                    lazy[k * 2 + 2] = lazy[k]; 
                }
                lazy[k] = -1;
            }
        }

        void update(int a, int b, LL v){    update(a,b,v,0,0,sz);   }
        void update(int a, int b, LL v, int k, int l, int r) {
            lazy_evaluate_node(k, l, r); 
            if (r <= a || b <= l)return; 
            if (a <= l && r <= b) {
                lazy[k] = v;
                lazy_evaluate_node(k, l, r);
            }
            else {
                update(a, b, v, k * 2 + 1, l, (l + r) / 2);
                update(a, b, v, k * 2 + 2, (l + r) / 2, r);
                node[k] = (node[k * 2 + 1] | node[k * 2 + 2]);
            }
        }

        LL orR(int a, int b){   return orR(a,b,0,0,sz); }
        LL orR(int a, int b, int k, int l, int r) {
            lazy_evaluate_node(k, l, r);
            if (r <= a || b <= l)return 0;
            if (a <= l && r <= b)return node[k];
            LL x = orR(a, b, k * 2 + 1, l, (l + r) / 2); 
            LL y = orR(a, b, k * 2 + 2, (l + r) / 2, r);
            return (x | y);
        }
};

#define MAX_V 500000

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
int N;
vector<Edge> G[MAX_V];

void addEdge(int from,int to,int cost){
    G[from].push_back((Edge){to,cost});
}

pair<vector<int>,vector<pair<int,int> > > eulerTour(int start){
    vector<int> tour;
    stack<int> st;
    vector<int> visited(N,0);
    st.push(start);
    while(!st.empty()){
        auto p=st.top();st.pop();
        tour.push_back(p);
        if(visited[p])continue;
        st.push(p);
        visited[p]=1;
        FOR(i,0,SZ(G[p]))
            if(!visited[G[p][i].to])
                st.push(G[p][i].to);
    }
    vector<pair<int,int> > index(SZ(tour)/2);
    FOR(i,0,SZ(index))index[i]=make_pair(-1,-1);
    FOR(i,0,SZ(tour)){
        if(index[tour[i]].first==-1)
            index[tour[i]].first=i;
        else
            index[tour[i]].second=i;
    }
    return make_pair(tour,index);
}

int popCount(LL _mask)
{
    int r=0;
    for(LL i=0;i<62;i++)
        if(_mask & (LL(1)<<i))
            r++;
    return r;
}

int main(void){
    int M;
    GI(N);GI(M);
    vector<int> color(N);
    REP(i,N)GI(color[i]);
    REP(i,N-1){
        int x,y;GI(x);GI(y);
        x--;y--;
        addEdge(x,y,1);addEdge(y,x,1);
    }
    auto eu = eulerTour(0);
    RangeUpdateRangeSum seg(SZ(eu.first));
    REP(i,N){
        seg.update(eu.second[i].first,eu.second[i].first+1,(1LL<<color[i]));
        seg.update(eu.second[i].second,eu.second[i].second+1,(1LL<<color[i]));
    }
    REP(i,M){
        int t;GI(t);
        if(t==1){
            int v,c;
            GI(v);GI(c);v--;
            seg.update(eu.second[v].first,eu.second[v].second+1,(1LL<<c));
        }else{
            int v;GI(v);v--;
            LL r=seg.orR(eu.second[v].first,eu.second[v].second+1);
            printf("%d\n",popCount(r));
        }
    }
    return 0;
}
