#include <vector>
#include <set>
#include <string>
#include <math.h>

using namespace std;

class TheQuestionsAndAnswersDivTwo{
	public:
		int find(vector <string> questions)
		{
			set<string> se;
			for(int i=0;i<questions.size();i++)
				se.insert(questions[i]);
			return pow(2,se.size());
		}
};
