vector<pair<int,int> > primeFactor(int num){ //first->prime,second->pow{
	if(num==1){
		vector<pair<int,int> > r;
		r.push_back(make_pair(1,1));
		return r;
	}
	else{
		vector<pair<int,int> > r;
		for(int i=2;i*i<=num;i++){
			if(num%i==0){
				int p=0;
				while(num%i==0)
					num/=i,p++;
				r.push_back(make_pair(i,p));
			}
		}
		if(num!=1)
			r.push_back(make_pair(num,1));
		return r;
	}
}

