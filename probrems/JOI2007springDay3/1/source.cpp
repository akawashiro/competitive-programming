#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
LL fact[21];

LL howMany(vector<int> letter)
{
	int sum=0;
	LL r=0;
	for(int i=0;i<26;i++)
		sum+=letter[i];
	r=fact[sum];
	for(int i=0;i<26;i++)
		r/=fact[letter[i]];
	return r;
}

int main()
{
	fact[0]=1;
	for(LL i=1;i<21;i++)
		fact[i]=fact[i-1]*i;
	string input;
	cin>>input;
	vector<int> letter(26,0);
	for(int i=0;i<(int)input.size();i++)
		letter[input[i]-'A']++;
	LL ans=0;
	for(int i=0;i<(int)input.size();i++)
	{
		for(int j=0;j<input[i]-'A';j++)
			if(0<letter[j])
			{
				letter[j]--;
				ans+=howMany(letter);
				letter[j]++;
			}
		letter[input[i]-'A']--;
	}
	cout<<ans+1<<endl;
	return 0;
}

