vector<int> string2vi(string s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]==',')
			s[i]=' ';
	vector<int> r;
	stringstream ss(s);
	int a;
	while(ss>>a)
		r.push_back(a);
	return r;
}


