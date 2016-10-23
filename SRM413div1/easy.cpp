#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS=le-9;

class ArithmeticProgression
{
public:
double minCommonDifference(int a0, vector <int> seq)
{
	double d=0;
	for(int i=0;i<(int)seq.size();i++)
		d=max(d,(seq[i]-a0)/(i+1.0));
	for(int i=0;i<(int)seq.size();i++)
		if((int)floor(a0+(i+1)*d+EPS)!=seq[i])
			return -1;
	return d;
}
};
