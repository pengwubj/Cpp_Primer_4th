#include <utility>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<string,int> sipair;
int main(int argc, char const *argv[])
{
	pair <string,int> x;
	std::vector<sipair> v;
	cout << "INPUT STRING INT :" << endl;
	while(cin>>x.first >> x.second)
	{
		pair<string,int> y =make_pair(x.first,x.second);
		v.push_back(y);
	}
	for(std::vector<sipair>::iterator iter=v.begin();iter != v.end(); ++iter)
		cout <<  (*iter).first << (*iter).second << endl;

	return 0;
}