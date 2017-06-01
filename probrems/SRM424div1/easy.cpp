class ProductOfDigits
{
	public:
		int smallestNumber(int N)
		{
			if(N==1)
				return 1;
			int count=0;
			for(count=0;N!=1;count++)
			{
				for(int i=9;1<i;i--)
				{
					if(N%i==0)
					{
						N/=i;
						break;
					}
					if(i==2)
						return -1;
				}
			}
			return count;
		}
};
