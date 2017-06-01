class BunnyConverter{public:
int getMinimum( int n, int z, int start, int goal )
{
	long long z3=z;
	z3*=(long long)z;z3%=(long long)n;
	z3*=(long long)z;z3%=(long long)n;

	int ans=0;
	long long t=goal;
	for(ans=0;ans<n;ans++)
	{
		if(t==start)
			return ans;
		t=(2*n-t*t%n-z3-1)%n+1;
	}
	return -1;
}
};
