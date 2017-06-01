#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

#define INF (1<<28)

using namespace std;

void solve()
{
	int n,k;
	cin >> n >> k;

	vector<int> input(n);
	for(int i=0;i<n;i++)
		cin >> input[i];
	sort(input.begin(),input.end());

	vector<int> len(n-1);
	for(int i=0;i+1<n;i++)
		len[i]=input[i+1]-input[i];
	sort(len.begin(),len.end());

	/*for(int i=0;i<n-1;i++)
		cout << len[i] << " ";
	cout << endl;*/

	int ans=0;
	for(int i=n,j=0;k<i;i--,j++)
		ans+=len[j];

	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t	;i++)
		solve();
	return 0;
}

