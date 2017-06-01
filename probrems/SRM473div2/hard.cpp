typedef long long LL;

class ChildlessNumbers{
	public:
		LL D(LL n)
		{
			LL r=0;
			while(n){
				r+=n%10
				n/=10
			}
			return r;
		}

		int howMany(int A, int B)
		{
			int ans=0;
			for(int i=A;i<=B;i++){
				bool isChiled=false;
				for(int j=1;j<=108;j++)
					if(D(j*i)==j)
						isChiled=true;
				if(isChiled)
					ans++;
			}
			return ans;
		}
};
