pair<vector<int>,vector<pair<int,int> > > EulerTour(Graph &G,int start){
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


