vector<int> stringToVInt(string s)
{
	for(int i=0;i<(int)s.size();i++)
		if(!('0'<=s[i] && s[i]<='9'))
				s[i]=' ';
	stringstream ss(s);
	vector<int> res;
	int a;
	while(ss>>a)
		res.push_back(a);
	return res;
}

