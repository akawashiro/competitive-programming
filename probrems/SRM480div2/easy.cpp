#include <vector>
using namespace std;

class Cryptography{
		public:
				long long encrypt(vector <int> numbers);
};

long long Cryptography::encrypt(vector <int> numbers)
{
		long long max=0;
		for(int i=0;i<(int)numbers.size();i++){
				numbers[i]++;
				long long a=1;
				for(int j=0;j<(int)numbers.size();j++)
						a*=(long long)numbers[j];
				max=(max<a) ? a : max;
				numbers[i]--;
		}
		return max;
}

