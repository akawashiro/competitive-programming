#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

string calc(string a,string b)
{
	if(a=="0" && b=="0")
		return "0";
	vector<int> num1,num2;
	for(int i=0;i<a.size();i++)
		num1.push_back(a[i]-'0');
	for(int i=0;i<b.size();i++)
		num2.push_back(b[i]-'0');
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());

	vector<int> ans(max(num1.size(),num2.size())+1,0);
	for(int i=0;i<ans.size()-1;i++)
	{
		if(i<num1.size())
			ans[i]+=num1[i];
		if(i<num2.size())
			ans[i]+=num2[i];
		if(9<ans[i])
		{
			ans[i]%=10;
			ans[i+1]+=1;
		}
	}
	reverse(ans.begin(),ans.end());
	int index=0;
	while(ans[index]==0)
		index++;
	string c;
	for(index;index<ans.size();index++)
		c+=ans[index]+'0';

	return c;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string a,b,c;
		cin >> a >> b;
		c=calc(a,b);
		if(80<c.size())
			cout << "overflow" << endl;
		else
			cout << c << endl;
	}
	return 0;
}
