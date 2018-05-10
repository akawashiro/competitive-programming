struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cost){
    g[from].push_back((Edge){to,cost});
}

void dfs_u(const Graph &g,vector<int> &dist_u,int v,int p,int d){
    dist_u[v] = d;
    for(auto e : g[v])
        if(e.to != p)
            dfs_u(g,dist_u,e.to,v,d+e.cost);
}

void dfs_v(const Graph &g,vector<int> &dist_v,int v,int p,int d){
    dist_v[v] = d;
    for(auto e : g[v])
        if(e.to != p)
            dfs_v(g,dist_v,e.to,v,d+e.cost);
}

// vとuは直径の端点
// 直径の値を返す
int diameter(const Graph &g,int &u,int &v,vector<int> &dist_u,vector<int> &dist_v){
    int N = g.size();
    dist_u = vector<int>(N);
    dist_v = vector<int>(N);
    dfs_u(g,dist_u,0,-1,0);
    int m = -1;
    for(int i=0;i<N;i++)
        if(m < dist_u[i]){
            v=i;
            m=dist_u[i];
        }
    dfs_v(g,dist_v,v,-1,0);
    m=-1;
    for(int i=0;i<N;i++)
        if(m < dist_v[i]){
            u=i;
            m=dist_v[i];
        }
    dfs_u(g,dist_u,u,-1,0);
    return dist_v[u];
}

