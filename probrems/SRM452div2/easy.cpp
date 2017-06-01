class EggCartons{
	public:
		int minCartons(int n)
		{
			int ans=n/8;
			for(ans;0<=ans;ans--)
				if((n-ans*8)%6==0)
					return ans+(n-ans*8)/6;
			return -1;
		}
};
