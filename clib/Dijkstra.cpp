#define MAX_V 1000

class Edge{
    public:
        int to,cost;
        Edge(int t,int c){to=t;cost=c;}
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<Edge> Graph[MAX_V];

void addEdge(int from,int to,int cap){
    G[from].push_back((Edge){to,cap,(int)G[to].size()});
	}

int dijkstra(Graph &G,int s,int g)
{
	int n=G.size();
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
