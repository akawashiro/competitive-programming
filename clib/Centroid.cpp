const int MAXN = 10010;
const int INF = 1e9;

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cost){
    g[from].push_back((Edge){to,cost});
}

// 重心として使われてるかのフラグ
bool centroid[MAXN];
// 部分木のサイズ
int subSize[MAXN];

// 部分木のサイズを計算する
int getSubSize(const Graph &G,int v, int p) {
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
pair<int,int> getCentroid(const Graph &G,int v, int p, int t) {
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


