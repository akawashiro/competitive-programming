int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}

class DesignCalendar
{
public:
int shortestPeriod(int d, int y)
{
	return d/gcd(d,y);
}
};
