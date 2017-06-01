typedef long long LL;

class TheLuckyNumbers
{
	public:
		int count(int a, int b)
		{
			int ans=0;
			for(LL digit=1;digit<=12;digit++)
			{
				for(LL num=0;num<(1<<digit);num++)
				{
					LL n=0;
					for(int i=0;i<digit;i++)
					{
						n*=10;
						if(num & (1<<i))
							n+=4;
						else
							n+=7;
					}
					if((LL)a<=n && n<=(LL)b)
						ans++;
				}
			}
			return ans;
		}
};
