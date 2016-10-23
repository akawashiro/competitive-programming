class MagicalSpheres 
{
	public:

		int count(int n,int p)
		{
			int r=0;
			while(n>1)
			{
				r+=n/p;
				n/=p;
			}
			return r;
		}

		bool check(int s,int f,int g)
		{
			for(int i=2;1<g;)
			{
				if(g%i==0)
				{
					int e=0;
					while(g%i==0)
						e++,g/=i;
					int c=count(s+f,i)-count(s,i)-count(f,i);
					if(c<e)
						return false;
				}
				i++;
				if(g<i*i)
					i=g;
			}
			return true;
		}

		int divideWork(int s,int f,int g) 
		{
			for(int i=g;0<i;i--)
				if(check(s,f,i))
					return i;
		}
};

