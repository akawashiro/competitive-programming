struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;
Graph g;

void addEdge(Graph &g,int from,int to,int cost){
    g[from].push_back((Edge){to,cost});
}

void dfs(const Graph &g,int cur, int prev, vector<pair<int,int> > &brg, vector<vector<int> > &each_bcc, stack<int> &roots, stack<int> &S, vector<bool> &inS, vector<int> &order, int &k){
    order[cur] = ++k;
    S.push(cur); inS[cur] = true;
    roots.push(cur);

    for(int i=0;i<g[cur].size();i++){
        int to = g[cur][i].to;
        if(order[to]==0){
            dfs(g,to,cur,brg,each_bcc,roots,S,inS,order,k);
        }
        else if(to!=prev && inS[to]){	//後退辺をたどる
            while(order[roots.top()] > order[to]) roots.pop();	//cur〜toまで(toは含まない)の頂点をrootsから捨てる
        }
    }

    if(cur==roots.top()){
        if(prev!=-1)brg.push_back(pair<int,int>(prev,cur));
        vector<int> bcc;
        while(1){
            int node = S.top(); S.pop(); inS[node] = false;
            bcc.push_back(node);
            if(node==cur)break;
        }
        each_bcc.push_back(bcc);
        roots.pop();
    }
}

void bridge(const Graph &g,vector<pair<int,int>> &brg, vector<vector<int>> &each_bcc){
    vector<int> order(g.size());
    vector<bool> inS(g.size());
    stack<int> roots, S;
    int k=0;
    for(int i=0;i<g.size();i++){
        if(order[i]==0){
            dfs(g,i,-1,brg,each_bcc,roots,S,inS,order,k);
        }
    }
}

void compressToTree(const Graph &g,const vector<vector<int>> &bcc,Graph &h,UnionFind &u){
    u = UnionFind(g.size());
    for(auto v : bcc){
        int a = v[0];
        for(auto b : v)
            u.set(a,b);
    }
    h = Graph(g.size());
    for(int i=0;i<g.size();i++){
        for(auto e : g[i])
            if(u.root(i) != u.root(e.to)){
                addEdge(h,u.root(i),u.root(e.to),e.cost);
            }
    }
}

