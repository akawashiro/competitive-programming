#define MAX_V 1000

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cost){
    g[from].push_back((Edge){to,cost});
}

// < vertexes order in EulerTour, < left position of vertex in EulerTour, right position of vertex in EulerTour>
pair<vector<int>,vector<pair<int,int> > > eulerTour(const Graph &g,int start){
    int N = g.size();
    vector<int> tour;
    stack<int> st;
    vector<int> visited(N,0);
    st.push(start);
    while(!st.empty()){
        auto p=st.top();st.pop();
        tour.push_back(p);
        if(visited[p])continue;
        st.push(p);
        visited[p]=1;
        FOR(i,0,SZ(g[p]))
            if(!visited[g[p][i].to])
                st.push(g[p][i].to);
    }
    vector<pair<int,int> > index(SZ(tour)/2);
    FOR(i,0,SZ(index))index[i]=make_pair(-1,-1);
    FOR(i,0,SZ(tour)){
        if(index[tour[i]].first==-1)
            index[tour[i]].first=i;
        else
            index[tour[i]].second=i;
    }
    return make_pair(tour,index);
}

