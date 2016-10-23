#include <string>
using namespace std;

class AgeEncoding{
	public:
		double getRadix(int age, string les)
		{
			int zn=0;
			for(zn=0;zn<les.size() && les[zn]=='0';zn++);
			les=les.substr(zn,les.size()-zn);

			if(les=="")
				return -1;
			int nOne=0;
			for(int i=0;i<les.size();i++)
				if(les[i]=='1')
					nOne++;
			if(les[les.size()-1]=='1' && nOne==1 && age==1)
				return -2;
			if(les[les.size()-1]=='1' && nOne==1 && 1<age)
				return -1;
			if(les[les.size()-1]=='1' && 1<nOne && age==1)
				return -1;

			double base=0;
			double error=1;
			while(0.00000000001<error){
				base+=error;
				double num=0;
				int i;
				double j;
				for(i=les.size()-1,j=1;0<=i;i--,j*=base)
					num+=(les[i]=='1') ? j : 0;
				if(age == num)
					break;
				if((double)age < num){
					base-=error;
					error/=10;
				}
			}
			return base;
		}
};
