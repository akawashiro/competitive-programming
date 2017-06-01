class MagicalSource
{
	public:
		long long calculate(long long x)
		{
			long long a=1;
			for(int i=0;i<15;i++)
			{
				a*=10;
				a++;
			}
			while(x%a!=0)
			{
				a--;
				a/=10;
			}
			return x/a;
		}
};
