#define MAX_V 1000

struct Edge{ int to,cap,rev; };
int used[MAX_V];
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cap){
    g[from].push_back((Edge){to,cap,(int)g[to].size()});
    g[to].push_back((Edge){from,0,(int)g[from].size()-1});
}

int DFS(Graph &g,int v,int t,int f){
    if(v==t)
        return f;
    used[v]=true;
    for(int i=0;i<(int)g[v].size();i++){
        Edge &e=g[v][i];
        if(!used[e.to] && 0<e.cap){
            int d=DFS(e.to,t,min(f,e.cap));
            if(0<d){
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(Graph &g,int s,int t){
    int flow=0;
    while(1){
        for(int i=0;i<MAX_V;i++)
            used[i]=false;
        int f=DFS(g,s,t,INT_MAX);
        if(f==0)
            break;
        flow+=f;
    }
    return flow;
}

