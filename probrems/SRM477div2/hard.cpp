typedef long long LL;

class CarelessSecretary{
	public:
	
		int popCount(int bit)
		{
			int count=0;
			for(int i=0;i<20;i++)
				if(bit & 1<<i)
					count++;
			return count;
		}

		int howMany(int N, int K)
		{
			LL MOD=1000000007;
			LL dp[12][1<<12];
			for(int i=0;i<12;i++)
				for(int j=0;j<(1<<12);j++)
					dp[i][j]=0;
			dp[0][0]=N-K;
			for(int i=1;i<K;i++)
				dp[0][1<<i]=1;
			
			for(int i=1;i<K;i++)
			{
				for(int j=0;j!=(1<<K);j++)
				{
					LL rest=(N-K-(i-popCount(j)))%MOD;
					if(0<rest)
						dp[i][j]+=(dp[i-1][j]*rest)%MOD;
					dp[i][j]%=MOD;
					for(int l=0;l<K;l++)
					{
						if(i==l || !(j&(1<<l)) )
							continue;
						dp[i][j]+=dp[i-1][(j & ~(1<<l))];
						dp[i][j]%=MOD;
					}
				}
			}
			
			LL other=1;
			for(int i=1;i<=N-K;i++)
			{
				other*=i;
				other%=MOD;
			}
			LL ans=0;
			for(int i=0;i<(1<<K);i++)
			{
				ans+=(dp[K-1][i]*other)%MOD;
				ans%=MOD;
			}
			return ans;
		}
};
