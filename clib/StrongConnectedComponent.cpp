struct Edge{
    int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;
// Prepare two graph
void addEdge(Graph &g,Graph &rg,int from,int to,int cap){
    g[from].push_back((Edge){to,cap});
    rg[to].push_back((Edge){from,cap});
}

#define MAX_V 10000
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
void dfs(const Graph &g,int v){
    used[v]=true;
    for(int i=0;i<(int)g[v].size();i++)
        if(!used[g[v][i].to])
            dfs(g,g[v][i].to);
    vs.push_back(v);
}
void rdfs(const Graph &rg,int v,int k){
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rg[v].size();i++)
        if(!used[rg[v][i].to])
            rdfs(rg,rg[v][i].to,k);
}
int scc(const Graph g,const Graph rg){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<(int)g.size();v++)
        if(!used[v])
            dfs(g,v);
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;0<=i;i--)
        if(!used[vs[i]])
            rdfs(rg,vs[i],k++);
    return k;
}

