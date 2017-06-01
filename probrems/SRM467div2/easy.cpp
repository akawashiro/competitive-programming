class ShorterSuperSum{

	public:
		int cache[15][15];

		int superSum(int k,int n)
		{
			if(cache[k][n]!=-1)
				return cache[k][n];
			if(k==0)
				return n;
			int r=0;
			for(int i=1;i<=n;i++)
				r+=superSum(k-1,i);
			return r;
		}

		int calculate(int k, int n)
		{
			for(int i=0;i<15;i++)
				for(int j=0;j<15;j++)
					cache[i][j]=-1;
			return superSum(k,n);
		}

};
