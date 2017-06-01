class LotteryPyaterochka{
	public:
		double chanceToWin(int N)
		{
			double n=N;
			return (10.0*(5*n-5)*(5*n-6)/2+5*(5*n-5)+1.0)*n*120/((5*n)*(5*n-1)*(5*n-2)*(5*n-3)*(5*n-4));
		}
};

