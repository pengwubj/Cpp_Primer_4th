#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
int main(int argc, char const *argv[])
{
	int a;
	std::vector<int> v1;
	cout << "INPUT INT :" << endl;
	while(cin >> a)
		v1.push_back(a);
	cin.clear();
	cout << accumulate(v1.begin(),v1.end(),0) << endl;
	while(true)
	{
		cout << "INPUT THE NUMBLE YOU WANA TO ANALYZE :" << endl;
		if(cin >> a)
		cout << count(v1.begin(),v1.end(),a) << "time(s)" << endl;
		else 
			break;
		cin.clear();

	}

	return 0;
}