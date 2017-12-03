#define MAX_V 1000

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
int N;
vector<Edge> G[MAX_V];

void addEdge(int from,int to,int cost){
    G[from].push_back((Edge){to,cost});
}

