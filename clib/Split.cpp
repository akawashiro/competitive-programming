vector<string> split(string s,char d){
    vector<string> r;
    string t;
    FOR(i,0,SZ(s)){
        if(s[i]==d){
            if(t!="")
                r.pb(t);
            i++;
        }else{
            t+=s[i];
        }
    }
    return r;
}
