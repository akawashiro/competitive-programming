#define MAX_V 1000

class Edge{
    public:
        int to,cost;
        Edge(int t,int c){to=t;cost=c;}
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<Edge> Graph[MAX_V];

