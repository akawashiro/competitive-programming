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

const int MAXN = 10010;
const int INF = 1e9;

struct Edge {
    int to,cost;
};
vector<Edge> G[MAXN];

void addEdge(int from,int to,int cost)
{
    G[from].push_back((Edge){to,cost});
}

int N, K;
// 重心として使われてるかのフラグ
bool centroid[MAXN];
// 部分木のサイズ
int subSize[MAXN];

// 部分木のサイズを計算する
int getSubSize(int v, int p) {
    int& ret = subSize[v];
    ret = 1;
    for (int i = 0; i < G[v].size(); i++) {
        int ch = G[v][i].to;
        if (ch == p || centroid[ch]) continue;
        ret += getSubSize(ch, v);
    }
    return ret;
}

// 重心となる頂点を探す
// first: 最大サイズ second: 対応する頂点
pair<int,int> getCentroid(int v, int p, int t) {
    pair<int,int> ret(INF, -1);
    int sum = 1, m = 0;
    for (int i = 0; i < G[v].size(); i++) {
        int ch = G[v][i].to;
        if (ch == p || centroid[ch]) continue;
        m = max(m, subSize[ch]);
        sum += subSize[ch];
        pair<int,int> p = getCentroid(ch, v, t);
        ret = min(ret, p);
    }
    m = max(m, t-sum);
    ret = min(ret, pair<int,int>(m, v));
    return ret;
}

// 部分木に含まれる頂点の距離を列挙
void getPaths(int v, int p, int d, vector<int>& ds) {
    ds.push_back(d);
    for (int i = 0; i < G[v].size(); i++) {
        Edge e = G[v][i];
        int ch = e.to;
        if (ch == p || centroid[ch]) continue;
        getPaths(ch, v, d+e.cost, ds);
    }
}

// 配列の情報から, コストが K 以下のものを探す
int countPairs(vector<int>& ds) {
    sort(ds.begin(), ds.end());
    int n = ds.size();
    int j = n;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && ds[j-1]+ds[i] > K) j--;
        ret += j-(j>i);
    }
    return ret/2;
}

int ans = 0;

// 頂点 v を含む部分問題を解く
void solve(int v) {
    // 重心を求める
    getSubSize(v, -1);
    int c = getCentroid(v, -1, subSize[v]).second;
    centroid[c] = true;
    for (int i = 0; i < G[c].size(); i++) {
        int ch = G[c][i].to;
        if (centroid[ch]) continue;
        solve(ch);
    }
    vector<int> ds(1);
    for (int i = 0; i < G[c].size(); i++) {
        Edge e = G[c][i];
        if (centroid[e.to]) continue;
        vector<int> tds;
        getPaths(e.to, c, e.cost, tds);
        ans -= countPairs(tds);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }
    ans += countPairs(ds);
    centroid[c] = false;
}

int main() {
    while (cin >> N >> K) {
        if (N==0 && K==0) break;
        memset(centroid, false, sizeof(centroid));
        for (int i = 0; i < N; i++) G[i].clear();
        for (int i = 0; i < N-1; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--; b--;
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        ans = 0;
        solve(0);
        printf("%d\n", ans);
    }
    return 0;
}
