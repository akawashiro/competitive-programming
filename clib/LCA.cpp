#define MAX_V 100000
#define MAX_LOG_V 32

struct Edge{
    int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cap){
    g[from].push_back((Edge){to,cap});
}

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(const Graph &g,int v,int p,int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i=0;i<g[v].size();i++)
        if(g[v][i].to != p)
            dfs(g[v][i].to, v, d+1);
}

void init(int root){
    dfs(root,-1,0);

    for(int k=0;k+1<MAX_LOG_V;k++)
        for(int v=0;v<N;v++){
            if(parent[k][v]<0)
                parent[k+1][v]=-1;
            else
                parent[k+1][v]=parent[k][parent[k][v]];
        }
}

int lca(int u,int v){
    if(depth[u]>depth[v])
        swap(u,v);
    for(int k=0;k<N;k++)
        if((depth[v] - depth[u]) >> k & 1)
            v = parent[k][v];
    if(u == v)
        return u;
    for(int k=MAX_LOG_V-1;0<=k;k--)
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    return parent[0][u];
}

