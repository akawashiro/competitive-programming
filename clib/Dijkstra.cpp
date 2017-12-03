#define MAX_V 1000

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
vector<Edge> G[MAX_V];
int n;

void addEdge(int from,int to,int cost){
    G[from].push_back((Edge){to,cost});
}

int dijkstra(int s,int g)
{
    vector<int> dist(n,INT_MAX/2);
    priority_queue<Edge> que;
    que.push(Edge(s,0));
    while(!que.empty()){
        Edge e=que.top();
        que.pop();
        if(e.cost<dist[e.to]){
            dist[e.to]=e.cost;
            for(int i=0;i<(int)G[e.to].size();i++)
                que.push(Edge(G[e.to][i].to,e.cost+G[e.to][i].cost));
        }
    }
    return dist[g];
}
