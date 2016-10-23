#include <vector>
#include <string>
#include <set>

using namespace std;

class ProductBundling
{
  public:
    int howManyBundles(vector <string> data)
    {
      set se<string>;

      for(int i=0;i<data[0].size();i++)
      {
	string s;
	for(int j=0;j<data.size();j++)
	  s+=data[j][i];
	se.insert(s);
      }

      return se.size();
    }
};

