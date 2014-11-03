#include <vector>
#include <iostream>
using namespace std;
vector<int>::iterator foo(vector<int>::iterator first,vector<int>::iterator last,int a){
	vector<int>::iterator iter;
	for(iter = first;iter !=last;++iter){
		if(*iter == a)
			break;
	}
	return iter;
}
int main(int argc, char const *argv[])
{
	int x[]= {1,2,3,4,5,6,7};
	vector<int> ival(x,x+7);
	int a;
	cout << "INPUT the NUMBER you want to check" << endl;
	while(cin >> a)
	{
		vector<int>::iterator iter = foo(ival.begin(),ival.end(),a);
		if(iter != ival.end())
			cout<< "GET IT" << *iter;
		else
			cout << "CAN NOT FIND THe INT" << endl;
	}
	vector<string> svec;
	// cout << svec.[0];
	cout << svec.at(0);
	return 0;
} 