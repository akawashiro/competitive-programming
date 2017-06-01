typedef long long LL;

LL S(LL num)
{
	num++;
	LL r=0;
	for(LL digit=0,i=10;digit<15;digit++,i*=10)
	{
		LL l=num;
		r+=l/i*45*(i/10);
		l%=i;
		for(LL j=0;0<l;j++,l-=(i/10))
			r+=((i/10)<=l)?j*(i/10):j*l;
	}
	return r;
}

class SumThemAll
{
	public:
		long long getSum(int lowerBound, int upperBound)
		{
			return S((LL)upperBound)-S((LL)(lowerBound-1));
		}
};

