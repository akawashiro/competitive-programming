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


