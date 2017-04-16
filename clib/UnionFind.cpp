class UnionFind
{
	vector<int> data;
	vector<int> scale;
	public:
	UnionFind(int n)
	{
		for(int i=0;i<n;i++)
		{
			data.push_back(i);
			scale.push_back(1);
		}
	}
	int root(int n)
	{
		if(data[n]==n)
			return n;
		else
			return data[n]=root(data[n]);
	}
	void set(int x,int y)
	{
		if(root(x)==root(y))
			return;
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		data[root(x)]=data[root(y)];
	}
	int size(int n)
	{
		return scale[root(n)];
	}
};

