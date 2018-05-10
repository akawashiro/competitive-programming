// 二重辺連結成分とは、「その成分に含まれるどの1辺を除いても、
// その成分が非連結にならないような部分グラフ」のことです。
// 橋という言葉を定義すると、二重辺連結成分とは、
// 「すべての橋をグラフから取り除いたときの連結成分」であると言うこともできます。
// 橋とは、その1辺を取り除いただけでグラフが非連結となるような辺のことです。
// よって橋を列挙することができれば、二重辺連結成分も列挙することができます。


struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cost){
    g[from].push_back((Edge){to,cost});
}

void bridgeDfs(const Graph &g,int cur, int prev, vector<pair<int,int> > &brg, vector<vector<int> > &each_bcc, stack<int> &roots, stack<int> &S, vector<bool> &inS, vector<int> &order, int &k){

    // fprintf(stderr,"LINE=%d\n",__LINE__);
    order[cur] = ++k;
    S.push(cur); inS[cur] = true;
    roots.push(cur);

    for(int i=0;i<(int)g[cur].size();i++){
        int to = g[cur][i].to;
        if(order[to]==0){
            bridgeDfs(g,to,cur,brg,each_bcc,roots,S,inS,order,k);
        }
        else if(to!=prev && inS[to]){	//後退辺をたどる
            // fprintf(stderr,"LINE=%d\n",__LINE__);
            while(order[roots.top()] > order[to]) 
                roots.pop();	//cur〜toまで(toは含まない)の頂点をrootsから捨てる
        }
    }

    // fprintf(stderr,"LINE=%d\n",__LINE__);
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
    vector<int> order(MAX_V);
    vector<bool> inS(MAX_V);
    stack<int> roots, S;
    int k=0;
    for(int i=0;i<(int)g.size();i++){
        if(order[i]==0){
            bridgeDfs(g,i,-1,brg,each_bcc,roots,S,inS,order,k);
        }
    }
}

// m is a map from old vertex in g to new vertex in h
void compressToTree(const Graph &g,const vector<vector<int>> &each_bcc,Graph &h,map<int,int> &m){
    for(int i=0;i<(int)each_bcc.size();i++){
        for(int j=0;j<(int)each_bcc[i].size();j++)
            m[each_bcc[i][j]] = i;
    }
    h = Graph(each_bcc.size());
    for(int i=0;i<(int)g.size();i++){
        for(auto e : g[i])
            if(m[i] != m[e.to]){
                addEdge(h,m[i],m[e.to],e.cost);
            }
    }
}

