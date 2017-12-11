#define MAX_V 1000

class Edge{
    public:
        int to,cost;
        Edge(int t,int c){to=t;cost=c;}
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<Edge> Graph[MAX_V];

Graph G;

void addEdge(int from,int to,int cap){
    G[from].push_back((Edge){to,cap,(int)G[to].size()});
  }

pair<vector<int>,vector<pair<int,int> > > EulerTour(int start){
    vector<int> tour;
    stack<int> st;
    vector<int> visited(SZ(G),0);
    st.push(start);
    while(!st.empty()){
        auto p=st.top();st.pop();
        tour.pb(p);
        if(visited[p])continue;
        st.push(p);
        visited[p]=1;
        FOR(i,0,SZ(G[p]))
            if(!visited[G[p][i].to])
                st.push(G[p][i].to);
    }
    vector<pair<int,int> > index(SZ(tour)/2);
    FOR(i,0,SZ(index))index[i]=mp(-1,-1);
    FOR(i,0,SZ(tour)){
        if(index[tour[i]].first==-1)
            index[tour[i]].first=i;
        else
            index[tour[i]].second=i;
    }
    return mp(tour,index);
}
