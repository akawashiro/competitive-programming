vector<int> unionSet(const vector<int>& a,const vector<int>& b){
     vector<int> r=a;
     r.insert(r.end(),b.begin(),b.end());
     sort(r.begin(),r.end());
     r.erase(unique(r.begin(),r.end()),r.end());
     return r;
}

vector<int> interSet(const vector<int>& a,const vector<int>& b){
     set<int> se(a.begin(),a.end());
     vector<int> r;
     for(int i=0;i<(int)b.size();i++)
	  if(se.find(b[i])!=se.end())
	       r.push_back(b[i]);
     return r;
}

//elements which blong to A but don't belong to B
vector<int> diffSet(const vector<int>& a,const vector<int>& b){
     set<int> se(b.begin(),b.end());
     vector<int> r;
     for(int i=0;i<(int)a.size();i++)
	  if(se.find(a[i])==se.end())
	       r.push_back(a[i]);
     return r;
}
