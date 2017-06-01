#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n,A,B,C;
	vector<int> h,w;
	cin>>n>>A>>B>>C;
	while(n--)
	{
		int ht,wt;
		cin>>ht>>wt;
		h.push_back(ht*A);
		w.push_back(wt*B);
	}

	int maxq=0;
	for(int k=0;k<h.size();k++)
	{
		vector<int> es;
		for(int i=0;i<h.size();i++)
			if(h[k]<=h[i] && h[i]-h[k]<=C)
				es.push_back( 2*(w[i]-C+h[i]-h[k]) ),es.push_back( 2*w[i]+1 );
		sort(es.begin(),es.end());

		for(int i=0,q=0;i!=es.size();i++)
			if(maxq<(es[i]&1?--q:++q))
				maxq=q;
	}
	cout<<maxq<<endl;
}

