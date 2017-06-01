#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
int rank[100000+10];

int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<int,int> > student;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		student.push_back(make_pair(a,i));
	}
	sort(student.begin(),student.end());
	reverse(student.begin(),student.end());
	for(int i=0;i<n;i++)
	{
		if(0<i && student[i-1].first==student[i].first)
			rank[student[i].second]=rank[student[i-1].second];
		else
			rank[student[i].second]=i+1;
	}
	for(int i=0;i<n;i++)
		printf("%d\n",rank[i]);
	return 0;
}


